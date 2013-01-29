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


#ifndef SAT_ABLE_H
#define SAT_ABLE_H

#include "../system.hpp"
#include "collisionnable.h"

namespace Collisionnable
{

class SAT_able : public virtual Collisionnable, public virtual Traits::Position
{
public:
	SAT_able();
	virtual ~SAT_able();

	virtual Vector2 projection(double angle) const = 0;
	virtual Vector2 overlap(const SAT_able& other) const = 0;
	
protected:
};

}

#endif // SAT_ABLE_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
