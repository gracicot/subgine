#pragma once

#include "../system.hpp"

#include "collisionnable.h"
#include "point_able.h"

namespace Collisionnable
{

class Point : public virtual Collisionnable, public virtual Traits::Position
{
public:
	Point() = default;
	Point(Vector2 position);
	virtual ~Point();
	
	operator Vector2();
};

}
