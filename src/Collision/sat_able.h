#pragma once

#include "../system.hpp"
#include "collisionnable.h"

namespace subgine
{
namespace collision
{

class SAT_able : public virtual Collisionnable, public virtual Traits::Position2
{
public:
	SAT_able();
	virtual ~SAT_able();

	virtual Vector2 projection(double angle) const = 0;
	virtual Vector2 overlap(const SAT_able& other) const = 0;
	virtual Vector2 getNearestPoint(Vector2 point) const = 0;

protected:
};


}
}
