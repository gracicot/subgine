#pragma once

#include "../system.hpp"

#include "collisionbody.h"
#include "point_able.h"

namespace subgine
{
namespace collision
{

class Point : public virtual CollisionBody, public virtual Positionnable2
{
public:
	Point() = default;
	Point(std::function< subgine::Vector2(void) > functor);
	Vector2 getPosition() const;
	virtual ~Point();

	operator Vector2();
	
private:
	std::function< Vector2(void) > _functor;
};

}
}
