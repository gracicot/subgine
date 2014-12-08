#include "physicbodycomponentprovider.h"

#include "physicbody.h"

namespace subgine {
namespace physic {

template<int n>
PhysicBodyComponentProvider<n>::PhysicBodyComponentProvider(const PhysicBody<n>& physicBody) : _physicBody(physicBody)
{
	
}

template<int n>
Vector<freedom(n), double> PhysicBodyComponentProvider<n>::getOrientation() const
{
	return _physicBody.getOrientation();
}

template<int n>
Vector<n, double> PhysicBodyComponentProvider<n>::getPosition() const
{
	return _physicBody.getPosition();
}

template class PhysicBodyComponentProvider<2>;
template class PhysicBodyComponentProvider<3>;

}
}
