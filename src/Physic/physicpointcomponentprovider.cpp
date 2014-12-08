#include "physicpointcomponentprovider.h"

namespace subgine {
namespace physic {

template<int n>
PhysicPointComponentProvider<n>::PhysicPointComponentProvider(const PhysicPoint<n>& physicPoint, std::function<subgine::Vector<freedom(n), double>()> orientation) :
	_physicPoint(physicPoint),
	_orientation(orientation)
{

}

template<int n>
PhysicPointComponentProvider<n>::PhysicPointComponentProvider(const PhysicPoint<n>& physicPoint, subgine::Vector<freedom(n), double> orientation) :
	_physicPoint(physicPoint),
	_orientation([orientation]() {
		return orientation;
	})
{

}

template<int n>
void PhysicPointComponentProvider<n>::setOrientation(std::function<Vector<freedom(n), double>()> orientation)
{

}

template<int n>
void PhysicPointComponentProvider<n>::setOrientation(Vector<freedom(n), double> orientation)
{

}

template<int n>
Vector<n, double> PhysicPointComponentProvider<n>::getPosition() const
{
	return _physicPoint.getPosition();
}

template <int n>
Vector<freedom(n), double> PhysicPointComponentProvider<n>::getOrientation() const
{
	return _orientation();
}

template class PhysicPointComponentProvider<2>;
template class PhysicPointComponentProvider<3>;

}
}
