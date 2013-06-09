#pragma once

#include "../collisionnable.h"

struct CollisionResult
{
	CollisionResult(const bool _isCollision, double _time);
	virtual ~CollisionResult();
	
	const bool isCollision;
	const double time;
};
