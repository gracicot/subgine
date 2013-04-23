#include "pointtester.h"
#include "../point.h"

PointTester::~PointTester()
{

}

CollisionResult* PointTester::compareObject(Collisionnable::Collisionnable& object1, Collisionnable::Collisionnable& object2, double time) const
{
	Collisionnable::Point* point = nullptr;
	Collisionnable::Point_able* object = nullptr;

	if(!(!(point = dynamic_cast<Collisionnable::Point*>(&object2)) && !(point = dynamic_cast<Collisionnable::Point*>(&object1)))
			&& !(!(object = dynamic_cast<Collisionnable::Point_able*>(&object2)) && !(object = dynamic_cast<Collisionnable::Point_able*>(&object1))))
	{
		if(object->isPointInside(point->getPosition()))
		{
			return new CollisionResult(true, time);
		}
		else
		{
			return new CollisionResult(false, time);
		}
	}
	return nullptr;
}
