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

void Collision::execute(const float time)
{
	for(auto it : _objects)
	{
		for(auto testMethod : it.second)
		{
			_testers[testMethod]->setAlias(testMethod);
			_testers[testMethod]->addObject(*it.first, time);
		}
	}
	
	for(auto tester : _testers)
	{
		tester.second->flush();
	}
}

void Collision::addData(Collisionnable::Collisionnable* object, std::list< std::string > testers)
{	
	_objects[object] = testers;
}

CollisionTester& Collision::getTester(const std::string tag)
{
	std::map<std::string, CollisionTester*>::iterator it = _testers.find(tag);

	if(it != _testers.end())
	{
		return *it->second;
	}

	throw std::out_of_range("No collision tester found with this tag");
}

const CollisionTester& Collision::getTester(const std::string tag) const
{
	std::map<std::string, CollisionTester*>::const_iterator it = _testers.find(tag);

	if(it != _testers.end())
	{
		return *it->second;
	}

	throw std::out_of_range("No collision tester found with this tag");
}

void Collision::addTester(CollisionTester* tester, const std::string tag)
{
	if(tester == nullptr || tester == 0)
	{
		throw std::runtime_error("The tester is null");
	}
	
	_testers[tag] = tester;
}

void Collision::removeData(Collisionnable::Collisionnable& object)
{
	_objects.erase(&object);
}
