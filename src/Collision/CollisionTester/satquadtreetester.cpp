#include "satquadtreetester.h"

#include "../collisionbody.h"
#include "../sat_able.h"
#include "../quadtree.h"
#include "../CollisionResults/satresult.h"

#include "../../system.hpp"

namespace sbg {

std::unique_ptr< Results::CollisionResult > SatQuadTreeTester::test(const CollisionBody& self, const CollisionBody& other, double time, std::string test) const
{
	auto tree = std::dynamic_pointer_cast<const QuadTree>(other.getCollisionEntity(test));
	auto satThis = std::dynamic_pointer_cast<const SAT_able>(self.getCollisionEntity(test));

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
						auto realSatOther = std::dynamic_pointer_cast<const SAT_able>(realAABBOther);
						
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

		if (response.notZero() && count > 0) {
			return std::unique_ptr<Results::CollisionResult>(new Results::SatResult(other, true, time, response/count));
		} else {
			return std::unique_ptr<Results::CollisionResult>(new Results::SatResult(other, false, time, Vector2d()));
		}
	} else {
		return std::unique_ptr<Results::CollisionResult>(nullptr);
	}
}

CollisionTester* SatQuadTreeTester::clone()
{
	return new SatQuadTreeTester(*this);
}

}
