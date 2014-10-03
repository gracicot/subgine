#pragma once

#include "sat_able.h"
#include "point_able.h"

namespace subgine
{
namespace collision
{

class Circle : public virtual SAT_able, public virtual Traits::Radius, public virtual Traits::Position2
{
public:
	Circle();
	virtual ~Circle();

	virtual bool isPointInside(Vector2d point) const override;
	virtual Vector2d projection(double angle) const override;
	virtual Vector2d overlap(const SAT_able& other) const override;
	virtual Vector2d getNearestPoint(Vector2d point) const override;
	virtual Vector2d boxOverlap(const AABB_able& other) const override;
	virtual std::pair< Vector2d, Vector2d > getBoundingBox() const override;
	
	virtual CollisionEntity* clone() const override;
};


}
}
