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


#include "../../collision.hpp"
#include "bounce.h"
#include "../physicpoint.h"

void Bounce::apply(Collisionnable::Collisionnable& object, const Collisionnable::Collisionnable& other, CollisionResult& result)
{
	SatResult* sat = dynamic_cast<SatResult*>(&result);
	PhysicPoint* point = dynamic_cast<PhysicPoint*>(&object);
	if(point != nullptr && point != 0 && sat != nullptr && sat != 0)
	{
		PhysicPoint const* other = dynamic_cast<PhysicPoint const*>(other);
		
		if(other != nullptr && other != 0)
		{
		}
		else
		{
		}
		
	}
	else
	{
		throw std::runtime_error("can't convert current collisionnable to PhysicPoint...");
	}
}

