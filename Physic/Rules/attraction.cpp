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


#include "attraction.h"

namespace Rule
{

Attraction::Attraction(const Attraction& c) : _value(c._value), _objects(c._objects)
{

}

Attraction::Attraction(const Vector2 value) : _value(value)
{

}

Vector2 Attraction::getResult(const PhysicPoint& object) const
{
	Vector2 result;
	Vector2 absolute;
	
for(auto i : _objects)
	{
		absolute = i->getPosition() - object.getPosition();
		result +=  (absolute.normalize() * i->getMass() * object.getMass()) / (pow2(absolute.x) + pow2(absolute.y));	  
	}

	return result * getValue();
}

void Attraction::addObject(const PhysicPoint& object)
{
	_objects.remove(&object);
	_objects.push_back(&object);
}

void Attraction::removeObject(const PhysicPoint& object)
{
	_objects.remove(&object);
}

Vector2 Attraction::getValue() const
{
	return _value;
}

void Attraction::setValue(const Vector2 value)
{
	_value = value;
}

}
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
