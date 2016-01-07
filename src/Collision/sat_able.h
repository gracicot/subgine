#pragma once

#include "../system.hpp"
#include "collisionentity.h"
#include "aabb_able.h"
#include "point_able.h"

namespace sbg {

struct SatTester;

struct SAT_able : virtual CollisionEntity, virtual AABB_able, virtual Point_able {
	SAT_able() = default;
	virtual ~SAT_able() = default;
	
	using DefaultTester = SatTester;

	virtual std::pair<double, double> projection(double angle) const = 0;
	virtual Vector2d overlap(const SAT_able& other) const = 0;
	virtual Vector2d getNearestPoint(Vector2d point) const = 0;
};

}
