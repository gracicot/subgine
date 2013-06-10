#include "collision.h"

#include <algorithm>

Collision::Collision() : _testers()
{

}

Collision::~Collision()
{

}

void Collision::execute (const float time)
{
	for (auto test : _objects) {

		CollisionResult* result = std::get<0> (test)->compareObject (*std::get<1> (test), *std::get<2> (test), time);

		if (result != nullptr) {
			if (result->isColliding()) {
				std::get<1> (test)->trigger (*std::get<2> (test), result, std::get<0> (test)->getAlias());
				std::get<2> (test)->trigger (*std::get<1> (test), result, std::get<0> (test)->getAlias());
			}

			delete result;
		}
	}
}

void Collision::add (Collisionnable::Collisionnable* object, std::list< std::string > groups)
{
	for (std::string & group : groups) {
		_groups[group].push_back (object);
	}

	makeObjectList();
}

CollisionTester& Collision::getTester (const std::string tag)
{
	std::map<std::string, CollisionTester*>::iterator it = _testers.find (tag);

	if (it != _testers.end()) {
		return *it->second;
	}

	throw std::out_of_range ("No collision tester found with this tag");
}

const CollisionTester& Collision::getTester (const std::string tag) const
{
	std::map<std::string, CollisionTester*>::const_iterator it = _testers.find (tag);

	if (it != _testers.end()) {
		return *it->second;
	}

	throw std::out_of_range ("No collision tester found with this tag");
}

void Collision::addTester (CollisionTester* tester, const std::string tag)
{
	if (tester == nullptr || tester == 0) {
		throw std::runtime_error ("The tester is null");
	}

	_testers[tag] = tester;

	makeObjectList();
}

void Collision::remove (Collisionnable::Collisionnable& object)
{
	for (auto group : _groups) {
		group.second.remove (&object);
	}

	makeObjectList();
}

void Collision::addTest (std::string tester, std::string group1, std::string group2)
{
	_testDefinition.push_back (std::make_tuple (tester, group1, group2));
}

void Collision::removeTest (std::string tester, std::string group1, std::string group2)
{
	std::tuple<std::string, std::string, std::string> toFind = std::make_tuple (tester, group1, group2);
	std::remove_if (_testDefinition.begin(), _testDefinition.end(), [&] (std::tuple<std::string, std::string, std::string> it) -> bool {
		return it == toFind;
	});
}

void Collision::remove (Collisionnable::Collisionnable& object, std::list< std::string > groups)
{
	for (auto group : groups) {
		_groups[group].remove (&object);
	}

	makeObjectList();
}

void Collision::clear()
{
	_groups.clear();
	_testers.clear();
	_testDefinition.clear();
	_objects.clear();
}

void Collision::makeObjectList()
{
	_objects.clear();

	for (auto test : _testDefinition) {
		for (auto object1 : _groups[std::get<1> (test)]) {
			for (auto object2 : _groups[std::get<2> (test)]) {
				_objects.push_back (std::make_tuple (_testers[std::get<0> (test)], object1, object2));
			}
		}
	}

}
