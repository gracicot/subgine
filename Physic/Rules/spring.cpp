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

namespace Rule
{

Spring::Spring(const Vector2 value, const double size, Positionnable& position) : _deletePosition(false), _value(value), _size(size)
{
	setPosition(position);
}

Spring::Spring(const Vector2 value, const double size, const Vector2 position) : _deletePosition(false), _value(value), _size(size)
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

Vector2 Spring::getPosition() const
{
	if(_position == nullptr)
	{
		return Vector2();
	}

	return _position->getPosition();
}

void Spring::setPosition(Positionnable& position)
{
	if(_deletePosition)
	{
		delete _position;
	}

	_deletePosition = false;
	_position = &position;
}

void Spring::setPosition(Vector2 pos)
{
	if(_deletePosition)
	{
		Vector2* position = dynamic_cast<Vector2*>(_position);
		*position = pos;
	}
	else
	{
		_position = new Vector2(pos);
	}

	_deletePosition = true;
}


double Spring::getSize() const
{
	return _size;
}

void Spring::setSize(const double size)
{
	_size = size;
}

Vector2 Spring::getResult(const PhysicPoint& object) const
{
	return (getPosition() - object.getPosition()).unit() * getValue() * ((getPosition() - object.getPosition()).getLenght() - getSize());
}

Vector2 Spring::getValue() const
{
	return _value;
}

void Spring::setValue(const Vector2 value)
{
	_value = value;
}

}
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
