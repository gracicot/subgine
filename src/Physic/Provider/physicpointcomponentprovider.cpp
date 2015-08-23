#include "physicpointcomponentprovider.h"

#include "../physicpoint.h"

using namespace std;

namespace sbg {

template<int n>
ComponentProvider<n> makePhysicPointComponentProvider(const PhysicPoint<n>& physicPoint, Provider<Vector<freedom(n), double>> orientation)
{
	return {[&physicPoint]{
		return physicPoint.getPosition();
	}, orientation};
}

template ComponentProvider<2> makePhysicPointComponentProvider<2>(const PhysicPoint<2>&, Provider<Vector<freedom(2), double>>);
template ComponentProvider<3> makePhysicPointComponentProvider<3>(const PhysicPoint<3>&, Provider<Vector<freedom(3), double>>);

}
