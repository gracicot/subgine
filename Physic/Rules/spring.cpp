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

Spring::Spring(Vector value, double size, Positionnable& position) : _deletePosition(false), _value(value), _size(size)
{
	setPosition(position);
}

Spring::Spring(Vector value, double size, Vector position) : _deletePosition(false), _value(value), _size(size)
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

Vector Spring::getPosition() const
{
	if(_position == nullptr)
	{
		throw std::runtime_error("Position not set");
	}

	return _position->getPosition();
}

void Spring::setPosition(Positionnable& pos)
{
	if(_deletePosition)
	{
		delete _position;
	}

	_deletePosition = false;
	_position = &pos;
}

void Spring::setPosition(Vector pos)
{
	if(_deletePosition)
	{
		Vector* position = dynamic_cast<Vector*>(_position);
		position->x = pos.x;
		position->y = pos.y;
	}
	else
	{
		_position = new Vector(pos);
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

Vector Spring::apply(const PhysicPoint& object) const
{
	return (getPosition() - object.getPosition()) * getValue() * ((getPosition() - object.getPosition()).getLenght() - getSize());
}

Vector Spring::getValue() const
{
	return _value;
}

void Spring::setValue(Vector value)
{
	_value = value;
}

}
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
