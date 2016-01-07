#pragma once

#include "rule.h"
#include "../physicpoint.h"

namespace sbg {

template<int n>
struct Resistance : Rule<n> {
	Resistance(const double value = 0);
	
	Vector<n, double> getResult(const PhysicPoint<n>& object) const override;
	Resistance<n>* clone() const override;
	
	double getValue() const;
	void setValue(const double value);

private:
	double _value;
};

extern template struct Resistance<2>;
extern template struct Resistance<3>;

using Resistance2D = Resistance<2>;
using Resistance3D = Resistance<3>;

}
