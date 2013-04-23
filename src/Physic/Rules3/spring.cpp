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

#include "../physicpoint3.h"

namespace Rule3
{

Spring::Spring(const Vector3 value, const double size, Positionnable3& position) : _deletePosition(false), _value(value), _size(size)
{
	setPosition(position);
}

Spring::Spring(const Vector3 value, const double size, const Vector3 position) : _deletePosition(false), _value(value), _size(size)
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
		return Vector3();
	}

	return _position->getPosition();
}

void Spring::setPosition(Positionnable3& position)
{
	if(_deletePosition)
	{
		delete _position;
	}

	_deletePosition = false;
	_position = &position;
}

void Spring::setPosition(Vector3 pos)
{
	if(_deletePosition)
	{
		Vector3* position = dynamic_cast<Vector3*>(_position);
		*position = pos;
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

Vector3 Spring::getResult(const PhysicPoint3& object) const
{
	Vector3 relative = getPosition() - object.getPosition();
	return relative.unit() * getValue() * (relative.getLenght() - getSize());
}

Vector3 Spring::getValue() const
{
	return _value;
}

void Spring::setValue(const Vector3 value)
{
	_value = value;
}

}

