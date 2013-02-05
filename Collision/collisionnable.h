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


#ifndef COLLISIONNABLE_H
#define COLLISIONNABLE_H

#include "../system.hpp"

#include "CollisionHandlers/collisionhandler.h"
#include "CollisionResults/collisionresult.h"

namespace Collisionnable
{

class Collisionnable
{
public:
	Collisionnable();
	virtual ~Collisionnable();
	
	void removeCollisionHandler(std::string tag);
	void addCollisionHandler(CollisionHandler* handler, std::string tag);
	void trigger(Collisionnable& other, CollisionResult* result, std::string tag);

protected:
	std::map<std::string, CollisionHandler*> _collisionhandlers;
};

}
#endif // COLLISIONNABLE_H

