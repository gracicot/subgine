#pragma once

#include "collisiontester.h"

#include <memory>

namespace subgine {
namespace collision {

class SatTester : public CollisionTester
{
public:
	virtual std::unique_ptr< Results::CollisionResult > test(const subgine::collision::CollisionBody& self, const subgine::collision::CollisionBody& other, double time, std::string test) const override;
	virtual CollisionTester* clone() override;
};

}
}


