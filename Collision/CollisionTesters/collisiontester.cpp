/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

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


#include "collisiontester.h"

CollisionTester::~CollisionTester()
{

}

void CollisionTester::flush()
{
	_objects.clear();
}

void CollisionTester::addObject(Collisionnable::Collisionnable& object, double time)
{
	CollisionResult* result = nullptr;

for(auto object2 : _objects)
	{
		result = compareObject(object, *object2, time);

		if(result != 0 && result != nullptr)
		{
			if(result->isCollision)
			{
				object.trigger(*object2, result, getAlias());
				object2->trigger(object, result, getAlias());
			}
			delete result;
		}
	}

	_objects.push_back(&object);
}

std::string CollisionTester::getAlias() const
{
	return _alias;
}

void CollisionTester::setAlias(std::string alias)
{
	_alias = alias;
}
