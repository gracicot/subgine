#pragma once

#include "../../system.hpp"

#include <memory>

namespace sbg{

class CollisionEntity;
class ResultData;

class CollisionTester : public Clonable
{
public:
	virtual std::pair<std::unique_ptr<ResultData>, bool> test(std::shared_ptr<const CollisionEntity> self, std::shared_ptr<const CollisionEntity> other) const = 0;
	virtual CollisionTester* clone() const = 0;
};

}
