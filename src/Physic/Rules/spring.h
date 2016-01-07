#pragma once

#include <functional>
#include <iostream>

#include "rule.h"
#include "../physicpoint.h"


namespace sbg {

template<int n>
struct Spring : Rule<n> {
	Spring();
	Spring(const double strength, const double length);
	Spring(const double strength, const double length, PositionProvider<n> provider);
	Spring(const Spring& other) = default;
	Spring(Spring&& other) = default;
	
	Vector<n, double> getPosition() const;
	void setPositionProvider(PositionProvider<n> provider);
	
	double getLength() const;
	void setLength(const double length);
	
	double getStrength() const;
	void setStrength(const double strength);
	
	Vector<n, double> getResult(const PhysicPoint<n>& object) const override;
	Spring<n>* clone() const override;

private:
	double _strength;
	double _length;
	PositionProvider<n> _provider;
};

extern template struct Spring<2>;
extern template struct Spring<3>;

using Spring2D = Spring<2>;
using Spring3D = Spring<3>;

}
