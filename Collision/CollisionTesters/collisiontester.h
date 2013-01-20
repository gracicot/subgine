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


#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include "../collisionnable.h"
#include "../CollisionResults/collisionresult.h"

class CollisionTester
{
public:
	CollisionTester() = default;
	virtual ~CollisionTester();

	virtual CollisionResult* compareObject(Collisionnable::Collisionnable& object1, Collisionnable::Collisionnable& object2, double time) const = 0;
	void addObject(Collisionnable::Collisionnable& object, double time);
	void flush();
	void setAlias(std::string alias);
	std::string getAlias() const;
	
protected:
	std::list<Collisionnable::Collisionnable*> _objects;
	
private:
	std::string _alias;
};

#endif // COLLISIONDETECTOR_H
