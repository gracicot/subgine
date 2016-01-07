#pragma once

#include "../system.hpp"

#include "collisionbody.h"
#include "point_able.h"

namespace sbg {

struct Point : CollisionEntity {
	Point() = default;
	Point(Provider<Vector2d> position);
	Vector2d getPosition() const;
	operator Vector2d();
	
private:
	Provider<Vector2d> _position;
};

}
