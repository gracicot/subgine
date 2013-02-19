/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#include "circle.h"
#include <limits>

namespace Collisionnable
{

Circle::Circle()
{

}

bool Circle::isPointInside(Vector2 point) const
{
	return (_position - point).getLenght() < _radius;
}

Vector2 Circle::projection(double angle) const
{
	double proj;
	Vector2 axis = {cos(angle), sin(angle)};

	proj = axis.dot(_position);

	//std::cerr << Vector2(proj-_radius, proj+_radius) << std::endl;


	return Vector2(proj - _radius, proj + _radius);
}

Circle::~Circle()
{

}

Vector2 Circle::overlap(const SAT_able& other) const
{
	Vector2 overlap;
	overlap.setLenght(std::numeric_limits< double >().max());
	double angle = (_position - other.getNearestPoint(_position)).getAngle();

	Vector2 projectionThis = this->projection(angle);
	Vector2 projectionOther = other.projection(angle);

	if(projectionThis.x < projectionOther.x && projectionThis.y > projectionOther.x && projectionThis.y < projectionOther.y)
	{
		if(overlap.getLenght() > projectionThis.y - projectionOther.x)
		{
			overlap = {projectionThis.y - projectionOther.x, 0};
			overlap.setAngle(angle);
		}
	}
	else if(projectionThis.x > projectionOther.x && projectionThis.y < projectionOther.y)
	{
		if(overlap.getLenght() > projectionThis.y - projectionThis.x)
		{
			overlap = {projectionThis.y - projectionThis.x, 0};
			overlap.setAngle(angle);
		}
	}
	else if(projectionThis.x > projectionOther.x && projectionThis.x < projectionOther.y && projectionThis.y > projectionOther.y)
	{
		if(overlap.getLenght() > projectionOther.y - projectionThis.x)
		{
			overlap = {projectionOther.y - projectionThis.x, 0};
			overlap.setAngle(angle);
		}
	}
	else if(projectionThis.x < projectionOther.x && projectionThis.y > projectionOther.y)
	{
		if(overlap.getLenght() > projectionOther.y - projectionOther.x)
		{
			overlap = {projectionOther.y - projectionOther.x};
			overlap.setAngle(angle);
		}
	}
	else
	{
		return Vector2(0, 0);
	}

	return overlap;
}

Vector2 Circle::getNearestPoint(Vector2 point) const
{
	Vector2 nearest(_radius, 0);
	nearest.setAngle((point - nearest).getAngle());
	return nearest;
}


}

