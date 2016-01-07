#pragma once

#include "collisiontester.h"
#include "../compoundcollision.h"

namespace sbg {

template<typename T, typename Next = typename T::DefaultTester, typename AccumulatorType = typename Next::ResultType::AccumulatorType>
struct CompoundTester : CollisionTester {
	using ResultType = typename Next::ResultType;
	
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
	
	std::pair<std::unique_ptr<ResultType>, bool> test(std::shared_ptr<const T> self, std::shared_ptr<const CompoundCollision<const T>> others) const
	{
		AccumulatorType accumulator;
		
		for (auto other : others->get()) {
			std::pair<std::unique_ptr<ResultType>, bool> result = _next.test(self, other);
			
			if (result.first && result.second) {
				accumulator += *result.first;
			}
			
		}
		
		return {std::make_unique<ResultType>(accumulator), !accumulator.empty()};
	}
	
	CompoundTester<T, Next>* clone() const override
	{
		return new CompoundTester<T, Next>(*this);
	}
	
private:
	Next _next;
};

}