#include "physicbodycomponentprovider.h"

#include "../physicbody.h"

using namespace std;

namespace sbg {

template<int n>
ComponentProvider<n> makePhysicBodyComponentProvider(const PhysicBody<n>& physicBody)
{
	return {[&]{
		return physicBody.getPosition();
	}, [&]{
		return physicBody.getOrientation();
	}};
}

template ComponentProvider<2> makePhysicBodyComponentProvider<2>(const PhysicBody<2>&);
template ComponentProvider<3> makePhysicBodyComponentProvider<3>(const PhysicBody<3>&);

}
