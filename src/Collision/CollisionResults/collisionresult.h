#pragma once

namespace subgine
{
namespace collision
{
namespace Results
{

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

}
}
}
