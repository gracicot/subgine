#include "physicpointdisplaycomponentprovider.h"

#include "../physicpoint.h"

using namespace std;

namespace sbg {

template<int n>
DisplayComponentProvider<n> makePhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, Provider<Vector<freedom(n), double>> orientation, Provider<Vector<n, double>> scale)
{
	return {
		[&physicPoint]{
			return physicPoint.getPosition();
		}, orientation, scale
	};
}

template DisplayComponentProvider<2> makePhysicPointDisplayComponentProvider<2>(const PhysicPoint<2>&, Provider<Vector<freedom(2), double>>, Provider<Vector<2, double>>);
template DisplayComponentProvider<3> makePhysicPointDisplayComponentProvider<3>(const PhysicPoint<3>&, Provider<Vector<freedom(3), double>>, Provider<Vector<3, double>>);

}