#pragma once

#include "../../system.hpp"


namespace sbg {

template<int> class PhysicPoint;

namespace Rule {
	
template<int n>
class Rule
{
public:
	virtual Vector<n, double> getResult(const PhysicPoint<n>& object) const = 0;
};

}
}
