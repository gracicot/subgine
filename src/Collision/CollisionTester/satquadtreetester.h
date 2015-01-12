#pragma once

#include "collisiontester.h"

#include <memory>

namespace sbg {

class SatQuadTreeTester : public CollisionTester
{
public:
	std::pair<std::unique_ptr<ResultData>, bool> test(std::shared_ptr<const CollisionEntity> self, std::shared_ptr<const CollisionEntity> other) const override;
	SatQuadTreeTester* clone() const override;
};

}
