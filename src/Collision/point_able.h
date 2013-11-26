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
	Point_able();
	virtual ~Point_able();

	virtual bool isPointInside(Vector2 point) const = 0;
};


}
}
