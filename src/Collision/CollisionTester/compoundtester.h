#pragma once

#include "collisiontester.h"
#include "../compoundcollision.h"

namespace sbg {

template<typename T, typename Next = typename T::DefaultTester>
class CompoundTester : public CollisionTester
{
public:
	std::pair<std::unique_ptr<ResultData>, bool> test(std::shared_ptr<const CollisionEntity> self, std::shared_ptr<const CollisionEntity> other) const override
	{
		auto selfT = std::dynamic_pointer_cast<const T>(self);
		auto otherT = std::dynamic_pointer_cast<const CompoundCollision<const T>>(other);

		if (otherT && selfT) {
			return test(selfT, otherT);
		} else {
			return {nullptr, false};
		}
	}
	
	std::pair<std::unique_ptr<ResultData>, bool> test(std::shared_ptr<const T> self, std::shared_ptr<const CompoundCollision<const T>> others) const
	{
		for (auto other : others->get()) {
			std::pair<std::unique_ptr<ResultData>, bool> result = _next.test(self, other);
			if (result.second) {
				return result;
			}
		}
		return {nullptr, false};
	}
	
	CompoundTester<T, Next>* clone() const override
	{
		return new CompoundTester<T, Next>(*this);
	}
	
private:
	Next _next;
};

}