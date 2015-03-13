#include "physicbodycomponentprovider.h"

#include "../physicbody.h"

using namespace std;

namespace sbg {

template<int n>
PhysicBodyComponentProvider<n>::PhysicBodyComponentProvider(weak_ptr<const PhysicBody<n>> physicBody) : PhysicPointPositionProvider<n>(physicBody), _physicBody(physicBody)
{
	
}

template<int n>
Vector<freedom(n), double> PhysicBodyComponentProvider<n>::getOrientation() const
{
	return _physicBody.expired() ? Vector<freedom(n), double>{}:_physicBody.lock()->getOrientation();
}

template<int n>
PhysicBodyComponentProvider<n>* PhysicBodyComponentProvider<n>::clone() const
{
	return new PhysicBodyComponentProvider<n>(*this);
}

template class PhysicBodyComponentProvider<2>;
template class PhysicBodyComponentProvider<3>;

}
