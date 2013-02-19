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

void Polygon::addPoint(const Vector2 point)
{
	_vertex.push_back(point);
}

bool Polygon::isPointInside(Vector2 point) const
{
	bool oddNodes = false;
	Vector2 previous_vertex = *_vertex.rbegin();
	previous_vertex.setAngle(previous_vertex.getAngle() + _angle);
	previous_vertex += _position;
for(Vector2 current_vertex : _vertex)
	{
		current_vertex.setAngle(current_vertex.getAngle() + _angle);
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

Vector2 Polygon::projection(double angle) const
{
	Vector2 axis = {cos(angle), sin(angle)};
	Vector2 result_projection;
	Vector2 current;


	std::list<Vector2>::const_iterator verticle = _vertex.begin();

	current = *verticle;
	current.setAngle(_angle + current.getAngle());

	result_projection.x = axis.dot(current + _position);
	result_projection.y = result_projection.x;

	for(verticle++ ; verticle != _vertex.end() ; verticle++)
	{
		current = *verticle;
		current.setAngle(_angle + current.getAngle());
		double p = axis.dot(current + _position);
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

Vector2 Polygon::overlap(const SAT_able& other) const
{
	Vector2 overlap;
	overlap.setLenght(std::numeric_limits< double >().max());
	overlap.setAngle(pi/4);
	
for(double angle : getAngles())
	{
		Vector2 projectionThis = this->projection(angle);
		Vector2 projectionOther = other.projection(angle);

		if((projectionThis.y < projectionOther.x) || projectionThis.x > projectionOther.y)
		{
			return Vector2();
		}
		
		if(projectionThis.x < projectionOther.x && projectionThis.y > projectionOther.x && projectionThis.y < projectionOther.y || true)
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
				overlap.setAngle(_angle);
			}
		}
		else if(projectionThis.x > projectionOther.x && projectionThis.x < projectionOther.y && projectionThis.y > projectionOther.y)
		{
			if(overlap.getLenght() > projectionOther.y - projectionThis.x)
			{
				overlap = {projectionOther.y - projectionThis.x, 0};
				overlap.setAngle(_angle);
			}
		}
		else if(projectionThis.x < projectionOther.x && projectionThis.y > projectionOther.y)
		{
			if(overlap.getLenght() > projectionOther.y - projectionOther.x)
			{
				overlap = {projectionOther.y - projectionOther.x};
				overlap.setAngle(_angle);
			}
		}
		else
		{
			return Vector2(0,0);
		}
	}
	return overlap;
}

std::vector< double > Polygon::getAngles() const
{
	std::vector<double> angles;
	Vector2 previous = *_vertex.rbegin();
	previous.setAngle(_angle + previous.getAngle());
for(Vector2 current : _vertex)
	{
		current.setAngle(_angle + current.getAngle());
		angles.push_back((previous - current).getAngle() - (pi / 2));
		previous = current;
	}
	return angles;
}

Vector2 Polygon::getNearestPoint(Vector2 point) const
{
	Vector2 nearest;
for(Vector2 current : _vertex)
	{
		current.setAngle(_angle + current.getAngle());
		if(nearest.getLenght() > (current - nearest).getLenght())
		{
			nearest = (current - nearest);
		}
	}
	return nearest;
}

}

