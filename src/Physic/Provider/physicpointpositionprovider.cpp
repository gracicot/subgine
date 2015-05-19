#include "physicpointpositionprovider.h"

#include "../physicpoint.h"

using namespace std;

namespace sbg {

template<int n>
PositionProvider<n> makePhysicPointPositionProvider(std::weak_ptr<const PhysicPoint<n>> physicPointRef)
{
	return {[=]{
		if (!physicPointRef.expired()) {
			return physicPointRef.lock()->getPosition();
			
		}
	}};
}

template PositionProvider<2> makePhysicPointPositionProvider<2>(std::weak_ptr<const PhysicPoint<2>>);
template PositionProvider<3> makePhysicPointPositionProvider<3>(std::weak_ptr<const PhysicPoint<3>>);

}
