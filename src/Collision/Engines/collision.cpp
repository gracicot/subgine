#include "collision.h"

#include "../collisionbody.h"
#include "../CollisionResults/collisionresult.h"

#include <future>
#include <thread>

using namespace std;

namespace subgine
{
namespace collision
{

Collision::Collision()
{

}

Collision::~Collision()
{

}

void Collision::execute(const double time)
{
	_inserting.lock();
	vector<Test> objects = _objects;
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
	for (auto group : groups) {
		for (auto collisionGroup : collisionGroups) {
			_groups[group].push_back(make_tuple(object, collisionGroup));
		}
	}

	makeObjectList();
}

void Collision::makeObjectList()
{
	_inserting.lock();
	_objects.clear();

	for (auto group : _groups) {
		for (auto object : group.second) {
			for (auto relatedObject : _groups[get<1>(object)]) {
				if (get<0>(object) != get<0>(relatedObject)) {
					_objects.push_back(Test(get<0>(object), get<0>(relatedObject), get<1>(object)));
				}
			}
		}
	}
	_inserting.unlock();
}

}
}
