#include "physicpointcomponentprovider.h"

#include "../physicpoint.h"

using namespace std;

namespace sbg {

template<int n>
ComponentProvider<n> makePhysicPointComponentProvider(weak_ptr<const PhysicPoint<n>> physicPoint, Vector<freedom(n), double> orientation)
{
	return {[physicPoint]{
		return physicPoint.expired() ? Vector<n, double>{} : physicPoint.lock()->getPosition();
	}, orientation};
}

template<int n>
ComponentProvider<n> makePhysicPointComponentProvider(weak_ptr<const PhysicPoint<n>> physicPoint, function<Vector<freedom(n), double>()> orientation)
{
	return {[physicPoint]{
		return physicPoint.expired() ? Vector<n, double>{} : physicPoint.lock()->getPosition();
	}, orientation};
}

template ComponentProvider<2> makePhysicPointComponentProvider<2>(weak_ptr<const PhysicPoint<2>>, Vector<1, double>);
template ComponentProvider<3> makePhysicPointComponentProvider<3>(weak_ptr<const PhysicPoint<3>>, Vector<3, double>);
template ComponentProvider<2> makePhysicPointComponentProvider<2>(weak_ptr<const PhysicPoint<2>>, function<Vector<1, double>()>);
template ComponentProvider<3> makePhysicPointComponentProvider<3>(weak_ptr<const PhysicPoint<3>>, function<Vector<3, double>()>);

}
