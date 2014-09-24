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

std::vector< Vector2d > SatResult::getContacts() const
{
	return _contacts;
}

void SatResult::setContacts(std::vector< Vector2d > contacts)
{
	_contacts = contacts;
}

}
}
}
