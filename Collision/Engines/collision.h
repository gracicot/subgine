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


#ifndef COLLISION_H
#define COLLISION_H

#include "../../system.hpp"

#include "../collisionnable.h"
#include "../CollisionTesters/collisiontester.h"

class Collision : public Engine
{

public:
	Collision();
	virtual ~Collision();

	virtual void execute(float time);
	
	CollisionTester& getTester(const std::string tag);
	const CollisionTester& getTester(const std::string tag) const;
	
	void addTester(CollisionTester* tester, const std::string tag);
	void addData(Collisionnable::Collisionnable* object, std::list< std::string > testers);
	
protected:
	std::map<Collisionnable::Collisionnable*, std::list<std::string>> _objects;
	std::map<std::string, CollisionTester*> _testers;
};

#endif // COLLISION_H
