#include "collision.h"

#include "../collisionbody.h"

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
	std::vector<std::tuple<CollisionBody*, std::unique_ptr<Results::CollisionResult>, std::string, CollisionBody*>> results;
	
	for (auto test : _objects) {
		results.push_back(make_tuple(std::get<0> (test), std::move(std::get<0> (test)->testObject(*std::get<1> (test), time, std::get<2> (test))), std::get<2> (test), std::get<1>(test)));
	}
	
	for (auto& result : results) {
		if (std::get<1>(result)) {
			if (std::get<1> (result)->isColliding()) {
				std::get<0> (result)->trigger(*std::get<3> (result), std::move(std::get<1> (result)), std::get<2> (result));
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
					_objects.push_back(std::make_tuple(std::get<0>(object), std::get<0>(relatedObject), std::get<1>(object)));
				}
			}
		}
	}

}

}
}
