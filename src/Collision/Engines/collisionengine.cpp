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

CollisionEngine::CollisionEngine(shared_ptr<GroupContainer> groupContainer) : _groupContainer{groupContainer} {}

void CollisionEngine::execute(Time time)
{
	if (!_listClean) {
		makeObjectList();
	}
	// todo: move to a class
	struct TestResult {
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
					results.push_back(move(testResult));
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

void CollisionEngine::add(std::weak_ptr<CollisionBody> object, vector<std::string> groups, vector<std::string> collisionGroups)
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
			auto findByGroup = [&group] (decltype(object)& current) -> bool {
				return find(current.second.first.begin(), current.second.first.end(), group) != current.second.first.end();
			};
			for (
				auto it = find_if(_objects.begin(), _objects.end(), findByGroup);
				it != _objects.end();
				it = find_if(++it, _objects.end(), findByGroup)
			) {
				if (!(!object.first.owner_before(it->first) && !it->first.owner_before(object.first))) {
					_tests.push_back({object.first, it->first, _groupContainer->group(group)});
				}
			}
		}
	}
	
	_listClean = true;
}

}
