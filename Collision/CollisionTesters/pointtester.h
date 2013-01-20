#ifndef POINTTESTER_H
#define POINTTESTER_H

#include "../../system.hpp"
#include "../CollisionResults/collisionresult.h"
#include "collisiontester.h"

class PointTester : public CollisionTester
{
public:
	PointTester() = default;
	virtual ~PointTester();
	
	virtual CollisionResult* compareObject(Collisionnable::Collisionnable& object1, Collisionnable::Collisionnable& object2, double time) const;
};

#endif // POINTTESTER_H
