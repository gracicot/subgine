#pragma once

#include "../CollisionResults/collisionresult.h"

namespace sbg {

class CollisionBody;

class CollisionHandler : Clonable
{
public:
	virtual void apply(std::shared_ptr<Entity> object, CollisionResult result) = 0;
	virtual CollisionHandler* clone() const = 0;
};

}
