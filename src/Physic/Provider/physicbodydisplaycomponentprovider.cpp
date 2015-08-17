#include "physicbodydisplaycomponentprovider.h"

#include "../physicbody.h"

using namespace std;

namespace sbg {

template<int n>
DisplayComponentProvider<n> makePhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, Provider<Vector<n, double>> scale)
{
	return {
		[&physicBody]{ return physicBody.getPosition(); },
		[&physicBody]{ return physicBody.getOrientation(); },
		scale
	};
}

template DisplayComponentProvider<2> makePhysicBodyDisplayComponentProvider(const PhysicBody<2>&, Provider<Vector<2, double>>);
template DisplayComponentProvider<3> makePhysicBodyDisplayComponentProvider(const PhysicBody<3>&, Provider<Vector<3, double>>);

}