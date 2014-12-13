#pragma once

#include <memory>

namespace sbg{

class CollisionBody;

namespace Results {
	class CollisionResult;
}

class CollisionTester
{
public:
	virtual std::unique_ptr<Results::CollisionResult> test(const CollisionBody& self, const CollisionBody& other, double time, std::string test) const = 0;
	virtual CollisionTester* clone() = 0;
};

}
