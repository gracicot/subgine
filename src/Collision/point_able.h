#pragma once

#include "../system.hpp"
#include "collisionentity.h"

namespace subgine
{


namespace collision
{


class Point_able : public virtual CollisionEntity
{
public:
	Point_able() = default;
	~Point_able() = default;

	virtual bool isPointInside(Vector2d point) const = 0;
};


}
}
