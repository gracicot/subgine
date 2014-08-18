#pragma once

#include "../collisionbody.h"

namespace subgine
{
namespace collision
{
namespace Results
{

class CollisionResult
{
public:
	CollisionResult(const CollisionBody& other, const bool colliding, const double time);
	virtual ~CollisionResult();

	bool isColliding() const;
	void colliding(const bool colliding);

	double getTime() const;
	void setTime(double time);
	
	const CollisionBody& getOther() const;
	void setOther(const CollisionBody& other);

private:
	const CollisionBody* _other;
	bool _colliding;
	double _time;
};

}
}
}
