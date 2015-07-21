#include "physicpointpositionprovider.h"

#include "../physicpoint.h"

using namespace std;

namespace sbg {

template<int n>
PositionProvider<n> makePhysicPointPositionProvider(const PhysicPoint<n>& physicPointRef)
{
	return {[&]{
		return physicPointRef.getPosition();
	}};
}

template PositionProvider<2> makePhysicPointPositionProvider<2>(const PhysicPoint<2>&);
template PositionProvider<3> makePhysicPointPositionProvider<3>(const PhysicPoint<3>&);

}
