#include "collision.h"

#include "../collisionbody.h"
#include "../CollisionResults/collisionresult.h"

#include <future>
#include <thread>
#include <algorithm>

using namespace std;

namespace subgine
{
namespace collision
{

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
		CollisionBody* object;
		unique_ptr<Results::CollisionResult> result;
		string test;
		CollisionBody* other;
	};
	
	mutex write;
	vector<TestResult> results;
	
	auto worker = [&results, time, this, &write, &objects](int number, int starts){
		auto it = objects.begin();
		advance(it, starts);
		
		while (distance(it, objects.end()) > 0) {
			Test& test = *it;
			TestResult&& testResult = {test.getObject(), move(test.getObject()->testObject(*test.getOther(), time, test.getTest())), test.getTest(), test.getOther()};
			write.lock();
			results.push_back(move(testResult));
			write.unlock();
			advance(it, number);
		}
	};
	const int numbreOfWorkers = std::min(static_cast<long unsigned int>(std::thread::hardware_concurrency() - 1), objects.size());
	if (numbreOfWorkers > 1) {
			
		vector<thread> workers;
		for (int i = 0 ; i<numbreOfWorkers ; i++) {
			workers.push_back(thread(worker, numbreOfWorkers, i));
		}
		for (auto& workerThread : workers) {
			if (workerThread.joinable()) {
				workerThread.join();
			}
		}
	} else {
		worker(1, 0);
	}
	
// 	for (Test test : _objects) {
// 		results.push_back({test.getObject(), move(test.getObject()->testObject(*test.getOther(), time, test.getTest())), test.getTest(), test.getOther()});
// 	}
	
	for (auto& result : results) {
		if (result.result) {
			if (result.result->isColliding()) {
				result.object->trigger(*result.other, move(result.result), result.test);
			}
		}
	}
}

void Collision::add(subgine::collision::CollisionBody* object, vector<string> groups, vector< string > collisionGroups)
{
	_objects[object] = {groups, collisionGroups};
	
	_listClean = false;
}

void Collision::remove(CollisionBody& object)
{
	_objects.erase(&object);
	
	_listClean = false;
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
				auto it = std::find_if(_objects.begin(), _objects.end(), findByGroup);
				it != _objects.end();
				it = std::find_if(++it, _objects.end(), findByGroup)
			) {
				if (object.first != it->first) {
					_test.push_back({object.first, it->first, group});
				}
			}
		}
	}
	
	_listClean = true;
	_inserting.unlock();
}

}
}
