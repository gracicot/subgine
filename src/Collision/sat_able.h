#pragma once

#include "../system.hpp"
#include "collisionentity.h"
#include "aabb_able.h"
#include "point_able.h"

namespace sbg {

class SatTester;

class SAT_able : public virtual CollisionEntity, public virtual AABB_able, public virtual Point_able
{
public:
	SAT_able() = default;
	virtual ~SAT_able() = default;
	
	using DefaultTester = SatTester;

	virtual SAT_able* clone() const = 0;
	virtual std::pair<double, double> projection(double angle) const = 0;
	virtual Vector2d overlap(const SAT_able& other) const = 0;
	virtual Vector2d getNearestPoint(Vector2d point) const = 0;

protected:
};


}
