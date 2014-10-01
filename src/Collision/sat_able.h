#pragma once

#include "../system.hpp"
#include "collisionentity.h"
#include "aabb_able.h"
#include "point_able.h"

namespace subgine
{
namespace collision
{

class SAT_able : public virtual CollisionEntity, public virtual AABB_able, public virtual Point_able
{
public:
	SAT_able() = default;
	~SAT_able() = default;

	virtual Vector2 projection(double angle) const = 0;
	virtual Vector2 overlap(const SAT_able& other) const = 0;
	virtual Vector2 getNearestPoint(Vector2 point) const = 0;

protected:
};


}
}
