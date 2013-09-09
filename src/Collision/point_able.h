#pragma once

#include "../system.hpp"
#include "collisionnable.h"

namespace subgine
{


namespace collision
{


class Point_able : public virtual Collisionnable, public virtual Traits::Position2
{
public:
	Point_able();
	virtual ~Point_able();

	virtual bool isPointInside(Vector2 point) const = 0;
};


}
}
