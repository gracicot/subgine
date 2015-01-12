#pragma once

#include "../system.hpp"
#include "collisionentity.h"
#include "aabb_able.h"
#include "point_able.h"

namespace sbg {

class SAT_able : public virtual CollisionEntity, public virtual AABB_able, public virtual Point_able
{
public:
	SAT_able() = default;
	~SAT_able() = default;

	virtual std::pair<double, double> projection(double angle) const = 0;
	virtual Vector2d overlap(const SAT_able& other) const = 0;
	virtual Vector2d getNearestPoint(Vector2d point) const = 0;

protected:
};


}
