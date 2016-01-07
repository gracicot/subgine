#include "sattester.h"

#include "../collisionbody.h"
#include "../sat_able.h"
#include "../CollisionResults/satresult.h"

#include "../../system.hpp"

using namespace std;

namespace sbg {

pair<unique_ptr<ResultData>, bool> SatTester::test(shared_ptr<const CollisionEntity> self, shared_ptr<const CollisionEntity> other) const
{
	auto satOther = dynamic_pointer_cast<const SAT_able>(other);
	auto satThis = dynamic_pointer_cast<const SAT_able>(self);

	if (satThis && satOther) {
		return test(satThis, satOther);
	} else {
		return {nullptr, false};
	}
}

pair<unique_ptr<SatResult>, bool> SatTester::test(shared_ptr<const SAT_able> self, shared_ptr<const SAT_able> other) const
{
	if (self->isboxOverlapping(*other)) {
		Vector2d overlap1 = self->overlap(*other);
		Vector2d overlap2 = other->overlap(*self);

		if (!overlap1.null() && !overlap2.null()) {
			Vector2d shortest = overlap1 < overlap2 ? overlap1 : -1 * overlap2;
			return {make_unique<SatResult>(shortest), true};
		}
	}

	return {make_unique<SatResult>(), false};
}

SatTester* SatTester::clone() const
{
	return new SatTester(*this);
}

}
