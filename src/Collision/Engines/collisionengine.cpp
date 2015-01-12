#include "collisionengine.h"

#include "../CollisionTester/collisiontester.h"
#include "../collisionbody.h"
#include "../CollisionResults/collisionresult.h"
#include "../CollisionResults/resultdata.h"

#include <future>
#include <thread>
#include <algorithm>

using namespace std;

namespace sbg {

void CollisionEngine::execute(const double time)
{
	if (!_listClean) {
		makeObjectList();
	}
	_inserting.lock();
	vector<Test> objects = _test;
	_inserting.unlock();
	// todo: move to a class
	struct TestResult {
		shared_ptr<CollisionBody> object;
		CollisionResult result;
		string test;
	};
	
	mutex write;
	vector<TestResult> results;
	
	parallel_for(objects.begin(), objects.end(), [&results, time, this, &write](Test& test){
		if (!test.getObject().expired() && !test.getOther().expired()) {
			auto testObject = test.getObject().lock();
			auto testOther = test.getOther().lock();
			
			TestResult&& testResult{testObject, move(testObject->testObject(testOther, time, test.getTest())), test.getTest()};
			write.lock();
			results.push_back(move(testResult));
			write.unlock();
		} else {
			if (test.getObject().expired()) {
				remove(test.getObject());
			}
			
			if (test.getOther().expired()) {
				remove(test.getOther());
			}
		}
	});
	
	for_each(results.begin(), results.end(), [](TestResult& result) {
		if (result.result.isColliding()) {
			result.object->trigger(move(result.result), result.test);
		}
	});
}

void CollisionEngine::add(std::weak_ptr<CollisionBody> object, vector<string> groups, vector< string > collisionGroups)
{
	_inserting.lock();
	_objects[object] = {groups, collisionGroups};
	
	_listClean = false;
	_inserting.unlock();
}

void CollisionEngine::remove(std::weak_ptr<CollisionBody> object)
{
	_inserting.lock();
	_objects.erase(object);
	
	_listClean = false;
	_inserting.unlock();
}

void CollisionEngine::makeObjectList()
{
	_inserting.lock();
	_test.clear();
	
	for (auto object : _objects) {
		for (auto group : object.second.second) {
			auto findByGroup = [&group] (decltype(object)& current) -> bool {
				return find(current.second.first.begin(), current.second.first.end(), group) != current.second.first.end();
			};
			for (
				auto it = find_if(_objects.begin(), _objects.end(), findByGroup);
				it != _objects.end();
				it = find_if(++it, _objects.end(), findByGroup)
			) {
				if (!(!object.first.owner_before(it->first) && !it->first.owner_before(object.first))) {
					_test.push_back({object.first, it->first, group});
				}
			}
		}
	}
	
	_listClean = true;
	_inserting.unlock();
}

}
