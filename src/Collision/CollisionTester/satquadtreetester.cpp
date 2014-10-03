#include "satquadtreetester.h"

#include "../collisionbody.h"
#include "../sat_able.h"
#include "../quadtree.h"
#include "../CollisionResults/satresult.h"

#include "../../system.hpp"

namespace subgine {
namespace collision {

std::unique_ptr< Results::CollisionResult > SatQuadTreeTester::test(const CollisionBody& self, const CollisionBody& other, double time, std::string test) const
{
	Vector2d response;

	auto tree = std::dynamic_pointer_cast<const QuadTree>(other.getCollisionEntity(test));
	auto satThis = std::dynamic_pointer_cast<const SAT_able>(self.getCollisionEntity(test));

	if (tree && satThis) {
		QuadTree::container test;

		if (tree->isContaining(*satThis)) {
			test = tree->getNearby(*satThis);

			for (auto weakAAABBOther : test) {
				if (!weakAAABBOther.expired()) {
					auto realAABBOther = weakAAABBOther.lock();

					if (satThis->isboxOverlapping(*realAABBOther)) {
						auto realSatOther = std::dynamic_pointer_cast<const SAT_able>(realAABBOther);

						Vector2d overlap1 = satThis->overlap(*realSatOther);
						Vector2d overlap2 = realSatOther->overlap(*satThis);

						if (overlap1.notZero() && overlap2.notZero()) {
							Vector2d shortest = overlap1 < overlap2 ? overlap1 : -1 * overlap2;

							if ((shortest.x > 0 && response.x > 0) || (shortest.x < 0 && response.x < 0)) {
								response.x = std::abs(response.x) < std::abs(shortest.x) ? shortest.x : response.x;
							} else {
								response.x += shortest.x;
							}

							if ((shortest.y > 0 && response.y > 0) || (shortest.y < 0 && response.y < 0)) {
								response.y = std::abs(response.y) < std::abs(shortest.y) ? shortest.y : response.y;
							} else {
								response.y += shortest.y;
							}
						}
					}
				}
			}
		}

		if (response.getLength() > 0) {
			return std::unique_ptr<Results::CollisionResult>(new Results::SatResult(other, true, time, response));
		} else {
			return std::unique_ptr<Results::CollisionResult>(new Results::SatResult(other, false, time, Vector2d()));
		}
	} else {
		return std::unique_ptr<Results::CollisionResult>(nullptr);
	}
}

}
}
