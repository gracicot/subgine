#pragma once

#include "../CollisionResults/collisionresult.h"

namespace sbg {

struct CollisionBody;

struct CollisionHandler : Clonable {
	virtual void apply(std::shared_ptr<Entity> object, CollisionResult result) = 0;
	CollisionHandler* clone() const override = 0;
};

}
