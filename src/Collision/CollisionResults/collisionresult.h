#pragma once

#include "../collisionnable.h"

class CollisionResult
{
public:
	CollisionResult(const bool colliding, const double time);
	virtual ~CollisionResult();

	bool isColliding() const;
	void colliding(const bool colliding);

	double getTime() const;
	void setTime(double time);

private:
	bool _colliding;
	double _time;
};
