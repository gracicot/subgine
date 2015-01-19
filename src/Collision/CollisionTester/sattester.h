#pragma once

#include "collisiontester.h"

#include <memory>

namespace sbg {

class SAT_able;
class SatResult;

class SatTester : public CollisionTester
{
public:
	using ResultType = SatResult;
	
	std::pair<std::unique_ptr<ResultData>, bool> test(std::shared_ptr<const CollisionEntity> self, std::shared_ptr<const CollisionEntity> other) const override;
	std::pair<std::unique_ptr<SatResult>, bool> test(std::shared_ptr<const SAT_able> self, std::shared_ptr<const SAT_able> other) const;

	SatTester* clone() const override;
	
};

}
