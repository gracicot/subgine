#pragma once

#include "../vector-all.h"

namespace sbg {
namespace shape {

template<int n>
struct Shape {
	virtual ~Shape();
	
	virtual Vector<freedom(n), double> getMomentOfInertia(double mass) const = 0;
	virtual Vector<n, double> getCenterOfMass() const = 0;
};

using Shape2D = Shape<2>;
using Shape3D = Shape<3>;

extern template struct Shape<2>;
extern template struct Shape<3>;

}
}