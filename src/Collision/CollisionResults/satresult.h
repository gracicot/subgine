#pragma once

#include "../../system.hpp"

#include "collisionresult.h"
#include "../collisionnable.h"

struct SatResult : public CollisionResult
{
	SatResult(bool _isCollision, double _time, Vector2 _distance);
	~SatResult() = default;
	
	const Vector2 distance;
};
