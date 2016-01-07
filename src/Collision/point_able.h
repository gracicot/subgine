#pragma once

#include "../system.hpp"
#include "collisionentity.h"

namespace sbg {

struct Point_able : virtual CollisionEntity {
	Point_able() = default;
	~Point_able() = default;

	virtual bool isPointInside(Vector2d point) const = 0;
};

}
