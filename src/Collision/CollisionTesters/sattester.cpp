#include "sattester.h"
#include <limits>

namespace subgine
{
namespace collision
{
namespace Testers
{

Results::CollisionResult* SatTester::compareObject(Collisionnable& object1, Collisionnable& object2, double time) const
{
	SAT_able* shape1 = dynamic_cast<SAT_able*>(&object1);
	SAT_able* shape2 = dynamic_cast<SAT_able*>(&object2);

	if (shape1 != 0 && shape1 != nullptr && shape2 != 0 && shape2 != nullptr) {
		Vector2 test1 = shape1->overlap(*shape2);
		Vector2 test2 = shape2->overlap(*shape1);

		if (test1.getLenght() > 0 && test2.getLenght() > 0) {
			Vector2 shortest = test1.getLenght() < test2.getLenght() ? test1 : test2;
			return new Results::SatResult(true, time, shortest);
		}

		return new Results::SatResult(false, time, Vector2(0, 0));
	}

	return nullptr;
}

}
}
}
