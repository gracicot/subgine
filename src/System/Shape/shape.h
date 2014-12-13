#pragma once

#include "../vector-all.h"

namespace sbg {
namespace shape {

template<int n>
class Shape
{
public:
	Shape() = default;
	~Shape() = default;
	Shape(const Shape&) = default;
	Shape(Shape&&) = default;
	
	virtual double getMomentOfInertia(double mass) const = 0;
	virtual Vector<n, double> getCenterOfMass() const = 0;
	
private:
};

}
}