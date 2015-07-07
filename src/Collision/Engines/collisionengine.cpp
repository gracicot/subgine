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
	// todo: move to a class
	struct TestResult {
		TestResult(shared_ptr<CollisionBody> _object, CollisionResult&& result, Group* _test) : object{move(_object)}, result{move(result)}, test{_test} {}
		shared_ptr<CollisionBody> object;
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
				
				TestResult testResult{testObject, move(testObject->testObject(testOther, time, test.getTest())), test.getTest()};
				{
					lock_guard<mutex> lock2{write};
					if (test.isReversible()) {
						results.emplace_back(testOther, move(CollisionResult{testObject, testResult.result.isColliding(), testResult.result.getData()->reverse(), time}), test.getTest());
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
		result.object->trigger(move(result.result), result.test);
	});
}

void CollisionEngine::add(std::weak_ptr<CollisionBody> object, vector<Group*> groups, vector<Group*> collisionGroups)
{
	lock_guard<mutex> lock{_inserting};
	_objects[object] = {groups, collisionGroups};
	
	_listClean = false;
}

void CollisionEngine::remove(std::weak_ptr<CollisionBody> object)
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
					auto duplicate = find(other.second.begin(), other.second.end(), group);
					if (duplicate != other.second.end()) {
						auto otherTest = find_if(_tests.begin(), _tests.end(), [&object, &it](Test& test){
							
							return (!test.getObject().owner_before(it->first) && !it->first.owner_before(test.getObject())) &&
							(!test.getOther().owner_before(object.first) && !object.first.owner_before(test.getOther()));
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

bool CollisionEngine::findByGroup(Group* group, pair<const weak_ptr<CollisionBody>, pair<vector<Group*>, vector<Group*>>>& object)
{
	return find(object.second.first.begin(), object.second.first.end(), group) != object.second.first.end();
}

}
