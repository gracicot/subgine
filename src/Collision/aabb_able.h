#pragma once

#include "system.hpp"

#include "collisionentity.h"

namespace subgine
{
namespace collision
{

class AABB_able : public virtual CollisionEntity
{
public:
	AABB_able() = default;
	~AABB_able() = default;
	virtual Vector2d boxOverlap(const AABB_able& other) const = 0;
	virtual std::pair<Vector2d, Vector2d> getBoundingBox() const = 0;
};

}
}