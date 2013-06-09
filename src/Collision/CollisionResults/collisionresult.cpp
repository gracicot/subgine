#include "collisionresult.h"

CollisionResult::CollisionResult(const bool colliding, const double time) : _time(time), _colliding(colliding)
{

}

CollisionResult::~CollisionResult()
{

}

void CollisionResult::colliding (const bool colliding)
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

void CollisionResult::setTime (double time)
{
	_time = time;
}
