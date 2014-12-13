#pragma once

#include "physicpointpositionprovider.h"
#include "../physicpoint.h"

#include "../../system.hpp"

namespace sbg {

template <int n>
class PhysicPointComponentProvider : public virtual ComponentProvider<n>, public virtual PhysicPointPositionProvider<n>
{
public:
	PhysicPointComponentProvider(const PhysicPoint<n>& physicPoint, Vector<freedom(n), double> orientation = Vector<freedom(n), double>());
	PhysicPointComponentProvider(const PhysicPoint<n>& physicPoint, std::function<Vector<freedom(n), double>()> orientation);
	
	void setOrientation(std::function<Vector<freedom(n), double>()> orientation);
	void setOrientation(Vector<freedom(n), double> orientation);
	
	virtual Vector<freedom(n), double> getOrientation() const override;
	
private:
	std::function<Vector<freedom(n), double>()> _orientation;
};

extern template class PhysicPointComponentProvider<2>;
extern template class PhysicPointComponentProvider<3>;

typedef PhysicPointComponentProvider<2> PhysicPoint2DComponentProvider;
typedef PhysicPointComponentProvider<3> PhysicPoint3DComponentProvider;

}