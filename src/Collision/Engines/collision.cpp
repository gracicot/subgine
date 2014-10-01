#include "collision.h"

#include "../collisionbody.h"
#include "../CollisionResults/collisionresult.h"

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
	// todo: move to a class
	struct TestResult {
		CollisionBody* object;
		std::unique_ptr<Results::CollisionResult> result;
		std::string test;
		CollisionBody* other;
	};
	
	std::vector<TestResult> results;
	
	for (Test test : _objects) {
		results.push_back({test.getObject(), std::move(test.getObject()->testObject(*test.getOther(), time, test.getTest())), test.getTest(), test.getOther()});
	}
	
	for (auto& result : results) {
		if (result.result) {
			if (result.result->isColliding()) {
				result.object->trigger(*result.other, std::move(result.result), result.test);
			}
		}
	}
}

void Collision::add(subgine::collision::CollisionBody* object, std::vector<std::string> groups, std::vector< std::string > collisionGroups)
{
	for (auto group : groups) {
		for (auto collisionGroup : collisionGroups) {
			_groups[group].push_back(std::make_tuple(object, collisionGroup));
		}
	}

	makeObjectList();
}

void Collision::makeObjectList()
{
	_objects.clear();

	for (auto group : _groups) {
		for (auto object : group.second) {
			for (auto relatedObject : _groups[std::get<1>(object)]) {
				if (std::get<0>(object) != std::get<0>(relatedObject)) {
					_objects.push_back(Test(std::get<0>(object), std::get<0>(relatedObject), std::get<1>(object)));
				}
			}
		}
	}

}

}
}
