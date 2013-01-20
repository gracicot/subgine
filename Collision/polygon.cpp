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


#include "polygon.h"
#include <limits>


namespace Collisionnable
{

Polygon::Polygon()
{

}

Polygon::~Polygon()
{

}

void Polygon::addPoint(const Vector point)
{
	_vertex.push_back(point);
}

bool Polygon::isPointInside(Vector point) const
{
	bool oddNodes = false;
	Vector previous_vertex = *_vertex.rbegin();
	previous_vertex.setAngle(previous_vertex.getAngle()+_angle);
	previous_vertex += _position;
	for(Vector current_vertex : _vertex)
	{
		current_vertex.setAngle(current_vertex.getAngle()+_angle);
		current_vertex += _position;
		if((current_vertex.y < point.y && previous_vertex.y >= point.y
			|| previous_vertex.y < point.y && current_vertex.y >= point.y)
			&& (current_vertex.x <= point.x || previous_vertex.x <= point.x))
		{
			oddNodes ^= (current_vertex.x + (point.y - current_vertex.y) / (previous_vertex.y - current_vertex.y) * (previous_vertex.x - current_vertex.x) < point.x);
		}
		previous_vertex = current_vertex;
	}
	return oddNodes;
}

Vector Polygon::projection(double angle) const
{
	Vector axis = {cos(angle), sin(angle)};
	Vector result_projection;
	Vector current;
	std::list<Vector>::const_iterator verticle = _vertex.begin();
	current = *verticle;
	current.setAngle(_angle+current.getAngle());
	result_projection.x = axis * (current+_position);
	result_projection.y = result_projection.x;
	
	for(verticle++ ; verticle != _vertex.end() ; verticle++)
	{
		current = *verticle;
		current.setAngle(_angle+current.getAngle());
		double p = axis * (current+_position);
		if(p < result_projection.x)
		{
			result_projection.x = p;
		}
		else if(p > result_projection.y)
		{
			result_projection.y = p;
		}
	}
	return result_projection;
}

Vector Polygon::overlap(const SAT_able& other) const
{
	Vector overlap;
	overlap.setLenght(std::numeric_limits< double >().max());
	std::vector<double> angles = getAngles();
	for(double angle : angles)
	{
		Vector projectionThis = this->projection(angle);
		Vector projectionOther = other.projection(angle);
		
		if(projectionThis.y > projectionOther.x && projectionThis.y < projectionOther.y)
		{
			overlap = overlap.getLenght() > Vector(projectionOther.x, projectionThis.y).getLenght() ? Vector(projectionOther.x, projectionThis.y) : overlap;
		}
		else if(projectionThis.x < projectionOther.y && projectionThis.x > projectionOther.x)
		{
			overlap = overlap.getLenght() > Vector(projectionThis.x, projectionOther.y).getLenght() ? Vector(projectionThis.x, projectionOther.y) : overlap;
		}
		else if(projectionThis.x > projectionOther.x && projectionThis.y < projectionOther.y)
		{
			overlap = overlap.getLenght() > projectionThis.getLenght() ? projectionThis : overlap;
		}
		else if(projectionThis.x < projectionOther.x && projectionThis.y > projectionOther.y)
		{
			overlap = overlap.getLenght() > projectionOther.getLenght() ? projectionOther : overlap;
		}
		else
		{
			return Vector(0,0);
		}
	}
	return overlap;
}

std::vector< double > Polygon::getAngles() const
{
	std::vector<double> angles;
	Vector previous = *_vertex.rbegin();
	previous.setAngle(_angle+previous.getAngle());
	for(Vector current : _vertex)
	{
		current.setAngle(_angle+current.getAngle());
		angles.push_back((previous - current).getAngle() - (M_PI/2));
		previous = current;
	}
	return angles;
}

}
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
