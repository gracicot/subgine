#include "satquadtreetester.h"

#include "../collisionbody.h"
#include "../sat_able.h"
#include "../quadtree.h"
#include "../CollisionResults/satresult.h"

#include "../../system.hpp"

using namespace std;

namespace sbg {

pair<unique_ptr<ResultData>, bool> SatQuadTreeTester::test(shared_ptr<const CollisionEntity> self, shared_ptr<const CollisionEntity> other) const
{
	auto tree = dynamic_pointer_cast<const QuadTree>(other);
	auto satThis = dynamic_pointer_cast<const SAT_able>(self);

	if (tree && satThis) {
		Vector2d response;
		QuadTree::container test;
		int count = 0;

		if (tree->isContaining(*satThis)) {
			test = tree->getNearby(*satThis);

			for (auto weakAAABBOther : test) {
				if (!weakAAABBOther.expired()) {
					auto realAABBOther = weakAAABBOther.lock();

					if (satThis->isboxOverlapping(*realAABBOther)) {
						auto realSatOther = dynamic_pointer_cast<const SAT_able>(realAABBOther);
						
						if (realSatOther) {
							Vector2d overlap1 = satThis->overlap(*realSatOther);
							Vector2d overlap2 = realSatOther->overlap(*satThis);

							if (overlap1.notZero() && overlap2.notZero()) {
								count++;
								response += overlap1 < overlap2 ? overlap1 : -1 * overlap2;
							}
						}
					}
				}
			}
		}

		if (response.notZero()) {
			return {make_unique<SatResult>(response/count), true};
		} else {
			return {make_unique<SatResult>(), false};
		}
	} else {
		return {nullptr, false};
	}
}

SatQuadTreeTester* SatQuadTreeTester::clone() const
{
	return new SatQuadTreeTester(*this);
}

}
