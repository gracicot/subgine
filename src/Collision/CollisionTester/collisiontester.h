#pragma once

#include <memory>

namespace subgine{
namespace collision{

class CollisionBody;

namespace Results {
	class CollisionResult;
}

class CollisionTester
{
public:
	virtual std::unique_ptr< Results::CollisionResult > test(const CollisionBody& self, const CollisionBody& other, double time, std::string test) const = 0;
};

}
}