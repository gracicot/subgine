#pragma once

#include <functional>
#include <iostream>

#include "rule.h"
#include "../physicpoint.h"


namespace sbg {

template<int n>
class Spring : public Rule<n>
{
public:
	Spring();
	~Spring();
	Spring(const double strength, const double length);
	Spring(const double strength, const double length, std::unique_ptr<PositionProvider<n>> provider);
	Spring(const Spring& other);
	
	Vector<n, double> getPosition() const;
	void setPositionProvider(std::unique_ptr<PositionProvider<n>> provider);
	
	double getLength() const;
	void setLength(const double length);
	
	double getStrength() const;
	void setStrength(const double strength);
	
	Vector<n, double> getResult(const PhysicPoint<n>& object) const override;
	Spring<n>* clone() const override;

private:
	double _strength;
	double _length;
	std::unique_ptr<PositionProvider<n>> _provider;
};

extern template class Spring<2>;
extern template class Spring<3>;

using Spring2D = Spring<2>;
using Spring3D = Spring<3>;

}
