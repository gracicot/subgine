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


#include "spring.h"

namespace Rule3
{

Spring::Spring(Vector3 value, double size, Positionnable3& position) : _deletePosition(false), _value(value), _size(size)
{
	setPosition(position);
}

Spring::Spring(Vector3 value, double size, Vector3 position) : _deletePosition(false), _value(value), _size(size)
{
	setPosition(position);
}

Spring::Spring(const Spring& other)
{
	if(_deletePosition)
	{
		delete _position;
	}

	_deletePosition = other._deletePosition;
	_position = other._position;
	_size = other._size;
	_value = other._value;
}

Spring::~Spring()
{
	if(_deletePosition)
	{
		delete _position;
	}
}

Vector3 Spring::getPosition() const
{
	if(_position == nullptr)
	{
		throw std::runtime_error("Position not set");
	}

	return _position->getPosition();
}

void Spring::setPosition(Positionnable3& pos)
{
	if(_deletePosition)
	{
		delete _position;
	}

	_deletePosition = false;
	_position = &pos;
}

void Spring::setPosition(Vector3 pos)
{
	if(_deletePosition)
	{
		Vector3* position = dynamic_cast<Vector3*>(_position);
		position->x = pos.x;
		position->y = pos.y;
		position->z = pos.z;
	}
	else
	{
		_position = new Vector3(pos);
	}

	_deletePosition = true;
}


double Spring::getSize() const
{
	return _size;
}

void Spring::setSize(double size)
{
	_size = size;
}

Vector3 Spring::apply(const PhysicPoint3& object, double time) const
{
	return Vector3(
			   ((((cos((object.getPosition() - getPosition()).getAngles().y) * sin((object.getPosition() - getPosition()).getAngles().x) * getSize()) + getPosition().x) - object.getPosition().x) * time) * getValue().x,
			   ((((sin((object.getPosition() - getPosition()).getAngles().x) * sin((object.getPosition() - getPosition()).getAngles().y) * getSize()) + getPosition().y) - object.getPosition().y) * time) * getValue().y,
			   ((((cos((object.getPosition() - getPosition()).getAngles().x) * getSize()) + getPosition().z) - object.getPosition().z) * time) * getValue().z
		   );
}

Vector3 Spring::getValue() const
{
	return _value;
}

void Spring::setValue(Vector3 value)
{
	_value = value;
}

}
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
