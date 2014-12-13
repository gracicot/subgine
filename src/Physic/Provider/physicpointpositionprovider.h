#pragma once

#include "../physicpoint.h"

#include "../../system.hpp"

namespace sbg {

template<int n>
class PhysicPointPositionProvider : public virtual PositionProvider<n>
{
public:
	PhysicPointPositionProvider(const PhysicPoint<n>& physicPoint);
	
	virtual Vector<n, double> getPosition() const override;
protected:
	const PhysicPoint<n>& _physicPoint;
};

extern template class PhysicPointPositionProvider<2>;
extern template class PhysicPointPositionProvider<3>;

typedef PhysicPointPositionProvider<2> PhysicPoint2DPositionProvider;
typedef PhysicPointPositionProvider<3> PhysicPoint3DPositionProvider;

}
