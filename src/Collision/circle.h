#pragma once

#include "sat_able.h"
#include "point_able.h"

class Vector2;

namespace subgine
{
namespace collision
{

class Circle : public virtual SAT_able, public virtual Point_able, public virtual Traits::Radius
{
public:
	Circle();
	virtual ~Circle();

	virtual bool isPointInside(Vector2 point) const;
	virtual Vector2 projection(double angle) const;
	virtual Vector2 overlap(const SAT_able& other) const;
	virtual Vector2 getNearestPoint(Vector2 point) const;

};


}
}
