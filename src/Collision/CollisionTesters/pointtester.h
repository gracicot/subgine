#pragma once

#include "../../system.hpp"
#include "../CollisionResults/collisionresult.h"
#include "collisiontester.h"
namespace subgine
{
namespace collision
{
namespace Testers
{
class PointTester : public CollisionTester
{
public:
	PointTester() = default;
	virtual ~PointTester();

	virtual Results::CollisionResult* compareObject(CollisionBody& object1, CollisionBody& object2, double time) const;
};

}
}
}
