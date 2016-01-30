#pragma once

#include "../../system.hpp"

namespace sbg {

template<int> struct PhysicPoint;

template<int n>
struct Rule : Clonable {
	virtual ~Rule();
	virtual Vector<n, double> getResult(const PhysicPoint<n>& object) const = 0;
	Rule<n>* clone() const override = 0;
};

using Rule2D = Rule<2>;
using Rule3D = Rule<3>;

extern template struct Rule<2>;
extern template struct Rule<3>;

}
