#include "collisionengine.h"
#include "groupcontainer.h"

#include "../CollisionTester/collisiontester.h"
#include "../collisionbody.h"
#include "../CollisionResults/collisionresult.h"
#include "../CollisionResults/resultdata.h"

#include <future>
#include <thread>
#include <algorithm>

using namespace std;

namespace sbg {

CollisionEngine::CollisionEngine() {}

void CollisionEngine::execute(Time time)
{
	if (!_listClean) {
		makeObjectList();
	}
	// TODO: move to a class
	struct TestResult {
		TestResult(CollisionBody& _body, std::shared_ptr<Entity> _object, CollisionResult&& result, Group* _test) : body{_body}, object{move(_object)}, result{move(result)}, test{_test} {}
		CollisionBody& body;
		std::shared_ptr<Entity> object;
		CollisionResult result;
		Group* test;
	};
	
	vector<TestResult> results;
	mutex write;
	
	{
		lock_guard<mutex> lock{_changeTests};
		parallel_for(_tests.begin(), _tests.end(), [&results, time, this, &write](Test& test){
			if (!test.getObject().expired() && !test.getOther().expired()) {
				auto testObject = test.getObject().lock();
				auto testOther = test.getOther().lock();
				
				auto& bodyFirst = testObject->component<CollisionBody>();
				auto& bodySecond = testOther->component<CollisionBody>();
				
				TestResult testResult{bodyFirst, testObject, move(bodyFirst.testObject(testOther, time, test.getTest())), test.getTest()};
				{
					lock_guard<mutex> lock2{write};
					if (test.isReversible()) {
						auto&& data = testResult.result.getData();
						results.emplace_back(bodySecond, testOther, move(CollisionResult{testObject, testResult.result.isColliding(), data ? data->reverse():nullptr, time}), test.getTest());
					}
					results.emplace_back(move(testResult));
				}
			} else {
				if (test.getObject().expired()) {
					remove(test.getObject());
				}
				
				if (test.getOther().expired()) {
					remove(test.getOther());
				}
			}
		});
	}
	
	parallel_for(results.begin(), results.end(), [](TestResult& result) {
		result.body.trigger(result.object, move(result.result), result.test);
	});
}

void CollisionEngine::add(std::shared_ptr<Entity> object, vector<Group*> groups, vector<Group*> collisionGroups)
{
	if (object->has<CollisionBody>()) {
		lock_guard<mutex> lock{_inserting};
		_objects[object] = {groups, collisionGroups};
		
		_listClean = false;
	}
}

void CollisionEngine::remove(std::weak_ptr<Entity> object)
{
	lock_guard<mutex> lock{_inserting};
	_objects.erase(object);
	
	_listClean = false;
}

void CollisionEngine::makeObjectList()
{
	lock_guard<mutex> lock{_inserting};
	lock_guard<mutex> lock2{_changeTests};
	_tests.clear();
	
	for (auto object : _objects) {
		for (auto group : object.second.second) {
			auto findCurrent = [&group, this](decltype(object)& current){
				return findByGroup(group, current);
			};
			
			for (
				auto it = find_if(_objects.begin(), _objects.end(), findCurrent);
				it != _objects.end();
				it = find_if(++it, _objects.end(), findCurrent)
			) {
				if (!(!object.first.owner_before(it->first) && !it->first.owner_before(object.first))) {
					auto other = _objects[it->first];
					auto duplicate = find(other.first.begin(), other.first.end(), group);
					auto duplicate2 = find_if(other.second.begin(), other.second.end(), [&](Group* otherCollisionGroup){
						return find(object.second.first.begin(), object.second.first.end(), otherCollisionGroup) != object.second.first.end();
					});
					if (duplicate != other.first.end() && duplicate2 != other.second.end()) {
						auto otherTest = find_if(_tests.begin(), _tests.end(), [&object, &it, group](Test& test){
							return (!test.getObject().owner_before(it->first) && !it->first.owner_before(test.getObject())) &&
							(!test.getOther().owner_before(object.first) && !object.first.owner_before(test.getOther())) && 
							group == test.getTest();
						});
						if (otherTest == _tests.end()) {
							_tests.emplace_back(object.first, it->first, group, true);
						}
					} else {
						_tests.emplace_back(object.first, it->first, group, false);
					}
				}
			}
		}
	}
	
	_listClean = true;
}

bool CollisionEngine::findByGroup(Group* group, pair<const weak_ptr<Entity>, pair<vector<Group*>, vector<Group*>>>& object)
{
	return find(object.second.first.begin(), object.second.first.end(), group) != object.second.first.end();
}

}
