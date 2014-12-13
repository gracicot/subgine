#pragma once


namespace sbg
{

class CollisionBody;

namespace Results {
class CollisionResult;
}


class CollisionHandler
{
public:
	CollisionHandler() = default;
	virtual ~CollisionHandler();

	virtual void apply(CollisionBody& object, const Results::CollisionResult& result) = 0;
	virtual CollisionHandler* clone() const = 0;
};

}
