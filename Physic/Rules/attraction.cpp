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

Attraction::Attraction(Vector value) : _value(value)
{

}

Vector Attraction::apply(const PhysicPoint& object, double time) const
{
	Vector result;
	double divider;

for(auto i : _objects)
	{
		divider = sqrt(pow2(i->getPosition().x - object.getPosition().x) +  pow2(i->getPosition().y - object.getPosition().y));
		result += Vector(
					  ((i->getPosition().x - object.getPosition().x) * i->getMass() * getValue().x * object.getMass()) / divider,
					  ((i->getPosition().y - object.getPosition().y) * i->getMass() * getValue().y * object.getMass()) / divider
				  );
	}

	return time * result;
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

Vector Attraction::getValue() const
{
	return _value;
}

void Attraction::setValue(Vector value)
{
	_value = value;
}

}
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
