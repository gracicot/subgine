#pragma once

#include "rule.h"
#include "../physicpoint.h"

namespace sbg {

template<int n>
class Resistance : public Rule<n>
{
public:
	Resistance(const double value = 0);
	
	Vector<n, double> getResult(const PhysicPoint<n>& object) const override;
	Resistance<n>* clone() const override;
	
	double getValue() const;
	void setValue(const double value);

private:
	double _value;
};

extern template class Resistance<2>;
extern template class Resistance<3>;

using Resistance2D = Resistance<2>;
using Resistance3D = Resistance<3>;

}
