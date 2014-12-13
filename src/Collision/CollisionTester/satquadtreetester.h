#pragma once

#include "collisiontester.h"

#include <memory>

namespace sbg {

class SatQuadTreeTester : public CollisionTester
{
public:
	virtual std::unique_ptr< Results::CollisionResult > test(const CollisionBody& self, const CollisionBody& other, double time, std::string test) const override;
	virtual CollisionTester* clone() override;
};

}
