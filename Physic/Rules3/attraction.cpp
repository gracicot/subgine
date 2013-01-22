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

namespace Rule3
{

Attraction::Attraction(const Attraction& c) : _value(c._value), _objects(c._objects)
{

}

Attraction::Attraction(Vector3 value) : _value(value)
{

}

Vector3 Attraction::apply(const PhysicPoint3& object) const
{
	Vector3 result;
	
for(auto i : _objects)
	{
		result += ( ((i->getPosition() - object.getPosition()) * i->getMass() * object.getMass()) / (i->getPosition() - object.getPosition()).getLenght() ) * getValue();	  
	}

	return result;
}

void Attraction::addObject(const PhysicPoint3& object)
{
	_objects.remove(&object);
	_objects.push_back(&object);
}

void Attraction::removeObject(const PhysicPoint3& object)
{
	_objects.remove(&object);
}

Vector3 Attraction::getValue() const
{
	return _value;
}

void Attraction::setValue(Vector3 value)
{
	_value = value;
}

}
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
