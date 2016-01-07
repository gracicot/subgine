#pragma once

#include "../vector-all.h"

namespace sbg {

template<int n>
struct AbstractShapeInfo {
	virtual ~AbstractShapeInfo();
	
	virtual Vector<freedom(n), double> getMomentOfInertia(double mass) const = 0;
	virtual Vector<n, double> getCenterOfMass() const = 0;
};

extern template struct AbstractShapeInfo<2>;
extern template struct AbstractShapeInfo<3>;

using AbstractShape2DInfo = AbstractShapeInfo<2>;
using AbstractShape3DInfo = AbstractShapeInfo<3>;

}
