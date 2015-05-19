#include "physicbodycomponentprovider.h"

#include "../physicbody.h"

using namespace std;

namespace sbg {

template<int n>
PositionProvider<n> makePhysicBodyComponentProvider(weak_ptr<const PhysicBody<n>> physicBody)
{
	return {[=]{
		return physicBody.expired() ? Vector<n, double>{0}:physicBody.lock()->getPosition();
	}};
}

template PositionProvider<2> makePhysicBodyComponentProvider<2>(weak_ptr<const PhysicBody<2>>);
template PositionProvider<3> makePhysicBodyComponentProvider<3>(weak_ptr<const PhysicBody<3>>);

}
