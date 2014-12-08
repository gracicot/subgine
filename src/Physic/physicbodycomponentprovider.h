#pragma once

#include "physicbody.h"

#include "../system.hpp"

namespace subgine {
namespace physic {

template<int n>
class PhysicBodyComponentProvider : public virtual ComponentProvider<n>
{
public:
	PhysicBodyComponentProvider(const PhysicBody<n>& physicoBody);
	
	virtual Vector<freedom(n), double> getOrientation() const override;
	virtual Vector<n, double> getPosition() const override;
	
private:
	const PhysicBody<n>& _physicBody;
};

extern template class PhysicBodyComponentProvider<2>;
extern template class PhysicBodyComponentProvider<3>;

typedef PhysicBodyComponentProvider<2> PhysicBody2DComponentProvider;
typedef PhysicBodyComponentProvider<3> PhysicBody3DComponentProvider;

}
}