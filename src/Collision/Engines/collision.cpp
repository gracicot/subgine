#include "collision.h"

#include "../collisionbody.h"
#include "../CollisionResults/collisionresult.h"

#include <future>
#include <thread>
#include <algorithm>

using namespace std;

namespace sbg {

Collision::Collision() : _listClean(true)
{

}

Collision::~Collision()
{

}

void Collision::execute(const double time)
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
		unique_ptr<Results::CollisionResult> result;
		string test;
		shared_ptr<CollisionBody> other;
	};
	
	mutex write;
	vector<TestResult> results;
	
	auto worker = [&results, time, this, &write, &objects](int number, int starts){
		auto it = objects.begin();
		advance(it, starts);
		
		while (distance(it, objects.end()) > 0) {
			Test& test = *it;
			
			if (!test.getObject().expired() && !test.getOther().expired()) {
				auto testObject = test.getObject().lock();
				auto testOther = test.getOther().lock();
				
				TestResult&& testResult = {testObject, move(testObject->testObject(*testOther, time, test.getTest())), test.getTest(), testOther};
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
			advance(it, number);
		}
	};
	
	const int numbreOfWorkers = min(static_cast<long unsigned int>(thread::hardware_concurrency() - 10), objects.size());
// 	if (numbreOfWorkers > 1) {
// 			
// 		vector<thread> workers;
// 		for (int i = 0 ; i<numbreOfWorkers ; i++) {
// 			workers.push_back(thread(worker, numbreOfWorkers, i));
// 		}
// 		for (auto& workerThread : workers) {
// 			if (workerThread.joinable()) {
// 				workerThread.join();
// 			}
// 		}
// 	} else {
		worker(1, 0);
// 	}
	
	for (auto& result : results) {
		if (result.result) {
			if (result.result->isColliding()) {
				result.object->trigger(*result.other, move(result.result), result.test);
			}
		}
	}
}

void Collision::add(std::weak_ptr<CollisionBody> object, vector<string> groups, vector< string > collisionGroups)
{
	_inserting.lock();
	_objects[object] = {groups, collisionGroups};
	
	_listClean = false;
	_inserting.unlock();
}

void Collision::remove(std::weak_ptr<CollisionBody> object)
{
	_inserting.lock();
	_objects.erase(object);
	
	_listClean = false;
	_inserting.unlock();
}

void Collision::makeObjectList()
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
