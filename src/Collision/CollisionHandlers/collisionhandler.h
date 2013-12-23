#pragma once


namespace subgine
{
namespace collision
{

class CollisionBody;
namespace Results
{
class CollisionResult;
}


class CollisionHandler
{
public:
	CollisionHandler() = default;
	virtual ~CollisionHandler();

	virtual void apply(CollisionBody& object, const CollisionBody& other, const Results::CollisionResult& result) = 0;
	virtual CollisionHandler* clone() const = 0;
};

}
}
