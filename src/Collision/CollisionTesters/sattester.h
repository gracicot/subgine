#pragma once

#include "../../system.hpp"

#include "../collisionnable.h"
#include "collisiontester.h"
#include "../sat_able.h"
#include "../CollisionResults/satresult.h"

class SatTester : public CollisionTester
{
public:
	CollisionResult* compareObject(Collisionnable::Collisionnable& object1, Collisionnable::Collisionnable& object2, double time) const;
};
