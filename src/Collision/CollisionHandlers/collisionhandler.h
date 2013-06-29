#pragma once


namespace subgine
{
namespace collision
{

class Collisionnable;
namespace Results
{
class CollisionResult;
}


class CollisionHandler
{
public:
	CollisionHandler() = default;
	virtual ~CollisionHandler();

	virtual void apply(Collisionnable& object, const Collisionnable& other, Results::CollisionResult& result) = 0;
};

}
}
