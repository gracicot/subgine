#pragma once

#include "rule.h"
#include "../physicpoint.h"

namespace sbg {

template<int n>
struct Gravity : Rule<n> {
	Gravity(const Vector<n, double> value = Vector<n, double>());
	
	Vector<n, double> getResult(const PhysicPoint<n>& object) const override;
	Gravity<n>* clone() const override;
	
	Vector<n, double> getValue() const;
	void setValue(const Vector<n, double> value);

private:
	Vector<n, double> _value;
};

extern template struct Gravity<2>;
extern template struct Gravity<3>;

using Gravity2D = Gravity<2>;
using Gravity3D = Gravity<3>;

}
