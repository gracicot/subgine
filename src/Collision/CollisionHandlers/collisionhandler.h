#pragma once

#include "../CollisionResults/collisionresult.h"

namespace sbg {

class CollisionBody;

class CollisionHandler
{
public:
	virtual void apply(CollisionBody& object, CollisionResult result) = 0;
	virtual CollisionHandler* clone() const = 0;
};

}
