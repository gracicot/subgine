#pragma once

#include "../system.hpp"
#include "collisionnable.h"

class Vector2;

namespace Collisionnable
{

class Point_able : public virtual Collisionnable, public virtual Traits::Position
{
public:
	Point_able();
	virtual ~Point_able();

	virtual bool isPointInside(Vector2 point) const = 0;
};

}
