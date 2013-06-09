#include "collision.h"

Collision::Collision() : _testers()
{

}

Collision::~Collision()
{

}

void Collision::execute (const float time)
{
	for(auto test : _objects) {
		
		CollisionResult* result = std::get<0>(test)->compareObject(*std::get<1>(test), *std::get<2>(test), time);
		
		if(result != nullptr && result->isColliding())
		{
			std::get<1>(test)->trigger(*std::get<2>(test), result, std::get<0>(test)->getAlias());
			std::get<2>(test)->trigger(*std::get<1>(test), result, std::get<0>(test)->getAlias());
			
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

void Collision::remove (Collisionnable::Collisionnable& object, std::list< std::string > groups)
{
	for (auto group : groups) {
		_groups[group].remove (&object);
	}

	makeObjectList();
}

void Collision::makeObjectList()
{
	_objects.clear();

	for (auto groups : _groups) {
		for (std::list<Collisionnable::Collisionnable*>::iterator item1 = groups.second.begin() ; item1 != groups.second.end() ; item1++) {
			for (std::list<Collisionnable::Collisionnable*>::iterator item2 = item1 ; item2 != groups.second.end() ; item2++) {
				_objects.push_back(std::make_tuple(_testers[groups.first], *item1, *item2));
			}
		}
	}

}