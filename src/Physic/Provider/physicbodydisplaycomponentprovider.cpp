#include "physicbodydisplaycomponentprovider.h"

#include "../physicbody.h"

using namespace std;

namespace sbg {

template<int n>
DisplayComponentProvider<n> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<n>> physicBody, Vector<n, double> scale)
{
	return {
		[physicBody]{ return physicBody.expired() ? Vector<n, double>{} : physicBody.lock()->getPosition(); },
		[physicBody]{ return physicBody.expired() ? Vector<freedom(n), double>{} : physicBody.lock()->getOrientation(); },
		[scale]{ return scale; }
	};
}

template<int n>
DisplayComponentProvider<n> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<n>> physicBody, std::function<Vector<n, double>()> scale)
{
	return {
		[physicBody]{ return physicBody.expired() ? Vector<n, double>{} : physicBody.lock()->getPosition(); },
		[physicBody]{ return physicBody.expired() ? Vector<freedom(n), double>{} : physicBody.lock()->getOrientation(); },
		scale
	};
}

template DisplayComponentProvider<2> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<2>>, Vector<2, double>);
template DisplayComponentProvider<2> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<2>>, std::function<Vector<2, double>()>);
template DisplayComponentProvider<3> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<3>>, Vector<3, double>);
template DisplayComponentProvider<3> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<3>>, std::function<Vector<3, double>()>);

}