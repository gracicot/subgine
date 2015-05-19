#include "physicpointdisplaycomponentprovider.h"

#include "../physicpoint.h"

using namespace std;

namespace sbg {

template<int n>
DisplayComponentProvider<n> makePhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, Vector<freedom(n), double> orientation, Vector<n, double> scale)
{
	return {
		[physicPoint]{
			return physicPoint.expired() ? Vector<n, double>{} : physicPoint.lock()->getPosition();
		},
		[orientation]{
			return orientation;
		},
		[scale]{
			return scale;
		}
	};
}

template<int n>
DisplayComponentProvider<n> makePhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, std::function<Vector<freedom(n), double>()> orientation, Vector<n, double> scale)
{
	return {
		[physicPoint]{
			return physicPoint.expired() ? Vector<n, double>{} : physicPoint.lock()->getPosition();
		},
		orientation,
		[scale]{
			return scale;
		}
	};
}

template<int n>
DisplayComponentProvider<n> makePhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, Vector<freedom(n), double> orientation, std::function<Vector<n, double>()> scale)
{
	return {
		[physicPoint]{
			return physicPoint.expired() ? Vector<n, double>{} : physicPoint.lock()->getPosition();
		},
		[orientation]{
			return orientation;
		},
		scale
	};
}

template<int n>
DisplayComponentProvider<n> makePhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, std::function<Vector<freedom(n), double>()> orientation, std::function<Vector<n, double>()> scale)
{
	return {
		[physicPoint]{
			return physicPoint.expired() ? Vector<n, double>{} : physicPoint.lock()->getPosition();
		},
		orientation,
		scale
	};
}

template DisplayComponentProvider<2> makePhysicPointDisplayComponentProvider<2>(std::weak_ptr<const PhysicPoint<2>> physicPoint, Vector<freedom(2), double>, Vector<2, double>);
template DisplayComponentProvider<2> makePhysicPointDisplayComponentProvider<2>(std::weak_ptr<const PhysicPoint<2>> physicPoint, std::function<Vector<freedom(2), double>()>, Vector<2, double>);
template DisplayComponentProvider<2> makePhysicPointDisplayComponentProvider<2>(std::weak_ptr<const PhysicPoint<2>> physicPoint, Vector<freedom(2), double>, std::function<Vector<2, double>()>);
template DisplayComponentProvider<2> makePhysicPointDisplayComponentProvider<2>(std::weak_ptr<const PhysicPoint<2>> physicPoint, std::function<Vector<freedom(2), double>()>, std::function<Vector<2, double>()>);
template DisplayComponentProvider<3> makePhysicPointDisplayComponentProvider<3>(std::weak_ptr<const PhysicPoint<3>> physicPoint, Vector<freedom(3), double>, Vector<3, double>);
template DisplayComponentProvider<3> makePhysicPointDisplayComponentProvider<3>(std::weak_ptr<const PhysicPoint<3>> physicPoint, std::function<Vector<freedom(3), double>()>, Vector<3, double>);
template DisplayComponentProvider<3> makePhysicPointDisplayComponentProvider<3>(std::weak_ptr<const PhysicPoint<3>> physicPoint, Vector<freedom(3), double>, std::function<Vector<3, double>()>);
template DisplayComponentProvider<3> makePhysicPointDisplayComponentProvider<3>(std::weak_ptr<const PhysicPoint<3>> physicPoint, std::function<Vector<freedom(3), double>()>, std::function<Vector<3, double>()>);

}