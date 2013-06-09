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


#include "sattester.h"
#include <limits>

CollisionResult* SatTester::compareObject(Collisionnable::Collisionnable& object1, Collisionnable::Collisionnable& object2, double time) const
{
	Collisionnable::SAT_able* shape1 = dynamic_cast<Collisionnable::SAT_able*>(&object1);
	Collisionnable::SAT_able* shape2 = dynamic_cast<Collisionnable::SAT_able*>(&object2);

	if(shape1 != 0 && shape1 != nullptr && shape2 != 0 && shape2 != nullptr)
	{
		Vector2 test1 = shape1->overlap(*shape2);
		Vector2 test2 = shape2->overlap(*shape1);
		
		if(test1.getLenght() > 0 && test2.getLenght() > 0)
		{
			Vector2 shortest = test1.getLenght() < test2.getLenght() ? test1 : test2;
			return new SatResult(true, time, shortest);
		}
		return new SatResult(false, time, Vector2(0, 0));
	}
	
	return nullptr;
}
