#pragma once

#include "collisiontester.h"
#include "../collisionbody.h"
#include "../sat_able.h"
#include "sattester.h"
#include "../quadtree.h"
#include "../compoundcollision.h"
#include "compoundtester.h"
#include "../CollisionResults/satresult.h"

#include "../../system.hpp"

#include <memory>

namespace sbg {

template<typename T, typename Next = CompoundTester<T>>
class QuadTreeTester : public CollisionTester
{
public:
	using ResultType = typename Next::ResultType;
	
	std::pair<std::unique_ptr<ResultData>, bool> test(std::shared_ptr<const CollisionEntity> self, std::shared_ptr<const CollisionEntity> other) const override
	{
		auto selfT = std::dynamic_pointer_cast<const T>(self);
		auto tree = std::dynamic_pointer_cast<const QuadTree<T>>(other);

		if (tree && selfT) {
			return test(selfT, tree);
		} else {
			return {nullptr, false};
		}
	}
	
	std::pair<std::unique_ptr<ResultType>, bool> test(std::shared_ptr<const T> self, std::shared_ptr<const QuadTree<T>> tree) const
	{
		if (tree->isContaining(*self)) {
			typename QuadTree<T>::container othersRef = tree->getNearby(*self);
			auto others = std::make_shared<CompoundCollision<const T>>();
			
			for (auto ref : othersRef) {
				if (!ref.expired()) {
					others->add(ref.lock());
				}
			}
			
			return _next.test(self, others);
		}
		
		return {nullptr, false};
	}
	
	QuadTreeTester<T, Next>* clone() const override
	{
		return new QuadTreeTester<T, Next>(*this);
	}
	
private:
	Next _next;
};

}
