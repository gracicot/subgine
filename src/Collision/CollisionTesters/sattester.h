#pragma once

#include "../../system.hpp"

#include "../collisionnable.h"
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
	Results::CollisionResult* compareObject(subgine::collision::Collisionnable& object1, subgine::collision::Collisionnable& object2, double time) const;
};

}
}
}
