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


#ifndef COLLISION_POLYGON_H
#define COLLISION_POLYGON_H

#include "../system.hpp"
#include "sat_able.h"
#include "point_able.h"

namespace Collisionnable
{

class Polygon : public virtual SAT_able, public virtual Point_able, public virtual Traits::Vertex, public virtual Traits::Angle
{
public:
	Polygon();
	virtual ~Polygon();

	virtual Vector2 projection(double angle) const;
	virtual bool isPointInside(Vector2 point) const;
	virtual Vector2 overlap(const SAT_able& other) const;
	
	void addPoint (const Vector2 point);
	std::vector< double > getAngles() const;
	
private:
};

}

#endif // COLLISION_POLYGON_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
