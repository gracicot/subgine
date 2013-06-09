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
