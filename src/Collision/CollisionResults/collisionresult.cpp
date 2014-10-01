#include "collisionresult.h"

#include "../collisionbody.h"

namespace subgine
{
namespace collision
{
namespace Results
{

CollisionResult::CollisionResult(const CollisionBody& other, const bool colliding, const double time) : _time(time), _colliding(colliding), _other(&other)
{

}

CollisionResult::~CollisionResult()
{

}

void CollisionResult::colliding(const bool colliding)
{
	_colliding = colliding;
}

double CollisionResult::getTime() const
{
	return _time;
}

bool CollisionResult::isColliding() const
{
	return _colliding;
}

void CollisionResult::setTime(double time)
{
	_time = time;
}

const CollisionBody& CollisionResult::getOther() const
{
	return *_other;
}

void CollisionResult::setOther(const CollisionBody& other)
{
	_other = &other;
}

}
}
}
