#pragma once

#include "../vector-all.h"

namespace sbg {

template<int n>
class AbstractShapeInfo
{
public:
	virtual ~AbstractShapeInfo();
	
	virtual Vector<freedom(n), double> getMomentOfInertia(double mass) const = 0;
	virtual Vector<n, double> getCenterOfMass() const = 0;
};

using AbstractShape2DInfo = AbstractShapeInfo<2>;
using AbstractShape3DInfo = AbstractShapeInfo<3>;

extern template class AbstractShapeInfo<2>;
extern template class AbstractShapeInfo<3>;

}
