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


#ifndef POINT_ABLE_H
#define POINT_ABLE_H

#include "../system.hpp"
#include "collisionnable.h"

class Vector2;

namespace Collisionnable
{

class Point_able : public virtual Collisionnable, public virtual Traits::Position
{
public:
	Point_able();
	virtual ~Point_able();

	virtual bool isPointInside(Vector2 point) const = 0;
};

}
#endif // POINT_ABLE_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
