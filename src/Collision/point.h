#pragma once

#include "../system.hpp"

#include "collisionbody.h"
#include "point_able.h"

namespace sbg {

class Point : public virtual CollisionBody
{
public:
	Point() = default;
	Point(std::function< Vector2d(void) > functor);
	Vector2d getPosition() const;
	virtual ~Point();

	operator Vector2d();
	
private:
	std::function< Vector2d(void) > _functor;
};

}
