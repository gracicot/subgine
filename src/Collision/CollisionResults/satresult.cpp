#include "satresult.h"

namespace subgine
{
namespace collision
{
namespace Results
{
SatResult::SatResult(const CollisionBody& other, const bool colliding, const double time, const subgine::Vector2 gap) : CollisionResult(other, colliding, time), _gap(gap)
{

}

Vector2 SatResult::getGap() const
{
	return _gap;
}

void SatResult::setGap(const Vector2 gap)
{
	_gap = gap;
}

}
}
}
