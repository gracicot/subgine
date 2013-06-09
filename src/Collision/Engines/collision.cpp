/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  Guillaume <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


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