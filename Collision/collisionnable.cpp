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


#include "collisionnable.h"

namespace Collisionnable
{

Collisionnable::Collisionnable()
{

}

Collisionnable::~Collisionnable()
{

for(auto handler : _collisionhandlers)
	{
		delete handler.second;
	}
}

void Collisionnable::addCollisionHandler(CollisionHandler* handler, std::string tag)
{
	if(!(handler == nullptr || handler == 0))
	{
		_collisionhandlers[tag] = handler;
	}
	else
	{
		throw std::runtime_error("Collision handler is null");
	}
}

void Collisionnable::trigger(Collisionnable& other, CollisionResult* result, std::string tag)
{
	std::map<std::string, CollisionHandler*>::iterator it = _collisionhandlers.find(tag);

	if(it != _collisionhandlers.end())
	{
		if(!(it->second == nullptr || it->second == 0))
		{
			it->second->apply(*this, other, *result);
		}
	}
}

}
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
