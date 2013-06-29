#include "pointtester.h"
#include "../point.h"

namespace subgine
{
namespace collision
{
namespace Testers
{

PointTester::~PointTester()
{

}

Results::CollisionResult* PointTester::compareObject(Collisionnable& object1, Collisionnable& object2, double time) const
{
	Point* point = nullptr;
	Point_able* object = nullptr;

	if (!(!(point = dynamic_cast<Point*>(&object2)) && !(point = dynamic_cast<Point*>(&object1)))
			&& !(!(object = dynamic_cast<Point_able*>(&object2)) && !(object = dynamic_cast<Point_able*>(&object1)))) {
		if (object->isPointInside(point->getPosition())) {
			return new Results::CollisionResult(true, time);
		}

		return new Results::CollisionResult(false, time);
	}

	return nullptr;
}

}
}
}
