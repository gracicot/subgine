#pragma once

#include "../../system.hpp"

#include "../collisionbody.h"
#include "collisiontester.h"
#include "../sat_able.h"
#include "../CollisionResults/satresult.h"

namespace subgine
{
namespace collision
{
namespace Testers
{

class SatTester : public CollisionTester
{
public:
	Results::CollisionResult* compareObject(subgine::collision::CollisionBody& object1, subgine::collision::CollisionBody& object2, double time) const;
};

}
}
}
