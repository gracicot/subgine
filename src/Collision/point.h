#pragma once

#include "../system.hpp"

#include "collisionnable.h"
#include "point_able.h"

namespace subgine
{
namespace collision
{

class Point : public virtual Collisionnable, public virtual Traits::Position
{
public:
	Point() = default;
	Point(Vector2 position);
	Vector2 getPosition() const;
	virtual ~Point();

	operator Vector2();
};

}
}
