#pragma once

#include "physicpointpositionprovider.h"
#include "../physicbody.h"

#include "../../system.hpp"

namespace sbg {

template<int n>
class PhysicBodyComponentProvider : public virtual ComponentProvider<n>, public virtual PhysicPointPositionProvider<n>
{
public:
	PhysicBodyComponentProvider(const PhysicBody<n>& physicoBody);
	
	virtual Vector<freedom(n), double> getOrientation() const override;
	
private:
	const PhysicBody<n>& _physicBody;
};

extern template class PhysicBodyComponentProvider<2>;
extern template class PhysicBodyComponentProvider<3>;

typedef PhysicBodyComponentProvider<2> PhysicBody2DComponentProvider;
typedef PhysicBodyComponentProvider<3> PhysicBody3DComponentProvider;

}