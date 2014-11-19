#include "sattester.h"

#include "../collisionbody.h"
#include "../sat_able.h"
#include "../CollisionResults/satresult.h"

#include "../../system.hpp"

namespace subgine {
namespace collision {

std::unique_ptr< Results::CollisionResult > SatTester::test(const CollisionBody& self, const CollisionBody& other, double time, std::string test) const
{
	auto satOther = std::dynamic_pointer_cast<const SAT_able>(other.getCollisionEntity(test));
	auto satThis = std::dynamic_pointer_cast<const SAT_able>(self.getCollisionEntity(test));

	if (satThis && satOther) {
		if (satThis->isboxOverlapping(*satOther)) {
			Vector2d overlap1 = satThis->overlap(*satOther);
			Vector2d overlap2 = satOther->overlap(*satThis);

			if (overlap1.notZero() && overlap2.notZero()) {
				Vector2d shortest = overlap1 < overlap2 ? overlap1 : -1 * overlap2;
				return std::unique_ptr<Results::CollisionResult>(new Results::SatResult(other, true, time, shortest));
			}
		}

		return std::unique_ptr<Results::CollisionResult>(new Results::SatResult(other, false, time, Vector2d()));
	} else {
		return std::unique_ptr<Results::CollisionResult>(nullptr);
	}
}

CollisionTester* SatTester::clone()
{
	return new SatTester(*this);
}

}
}
