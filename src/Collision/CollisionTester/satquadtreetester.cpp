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

		if (tree->isContaining(*satThis)) {
			test = tree->getNearby(*satThis);

			for (auto weakAAABBOther : test) {
				if (!weakAAABBOther.expired()) {
					auto realAABBOther = weakAAABBOther.lock();

					if (satThis->isboxOverlapping(*realAABBOther)) {
						auto realSatOther = dynamic_pointer_cast<const SAT_able>(realAABBOther);

						Vector2d overlap1 = satThis->overlap(*realSatOther);
						Vector2d overlap2 = realSatOther->overlap(*satThis);

						if (overlap1.notZero() && overlap2.notZero()) {
							Vector2d shortest = overlap1 < overlap2 ? overlap1 : -1 * overlap2;

							if ((shortest.x > 0 && response.x > 0) || (shortest.x < 0 && response.x < 0)) {
								response.x = abs(response.x) < abs(shortest.x) ? shortest.x : response.x;
							} else {
								response.x += shortest.x;
							}

							if ((shortest.y > 0 && response.y > 0) || (shortest.y < 0 && response.y < 0)) {
								response.y = abs(response.y) < abs(shortest.y) ? shortest.y : response.y;
							} else {
								response.y += shortest.y;
							}
						}
					}
				}
			}
		}

		if (response.notZero()) {
			return {make_unique<SatResult>(response), true};
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
