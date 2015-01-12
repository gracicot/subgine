#include "sattester.h"

#include "../collisionbody.h"
#include "../sat_able.h"
#include "../CollisionResults/satresult.h"

#include "../../system.hpp"

using namespace std;

namespace sbg {

std::pair<std::unique_ptr<ResultData>, bool> SatTester::test(shared_ptr<const CollisionEntity> self, shared_ptr<const CollisionEntity> other) const
{
	auto satOther = dynamic_pointer_cast<const SAT_able>(other);
	auto satThis = dynamic_pointer_cast<const SAT_able>(self);

	if (satThis && satOther) {
		if (satThis->isboxOverlapping(*satOther)) {
			Vector2d overlap1 = satThis->overlap(*satOther);
			Vector2d overlap2 = satOther->overlap(*satThis);

			if (overlap1.notZero() && overlap2.notZero()) {
				Vector2d shortest = overlap1 < overlap2 ? overlap1 : -1 * overlap2;
				return {make_unique<SatResult>(shortest), true};
			}
		}

		return {make_unique<SatResult>(), false};
	} else {
		return {nullptr, false};
	}
}

SatTester* SatTester::clone() const
{
	return new SatTester(*this);
}

}
