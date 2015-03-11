#pragma once

#include "../../system.hpp"

namespace sbg {

template<int> class PhysicPoint;
	
template<int n>
class Rule : public virtual Clonable
{
public:
	virtual Vector<n, double> getResult(const PhysicPoint<n>& object) const = 0;
	virtual Rule<n>* clone() const = 0;
};

using Rule2D = Rule<2>;
using Rule3D = Rule<3>;

extern template class Rule<2>;
extern template class Rule<3>;

}
