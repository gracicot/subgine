#include "physicpointcomponentprovider.h"

using namespace std;

namespace sbg {

template<int n>
PhysicPointComponentProvider<n>::PhysicPointComponentProvider(const PhysicPoint<n>& physicPoint, function<Vector<freedom(n), double>()> orientation) :
	PhysicPointPositionProvider<n>(physicPoint),
	_orientation(orientation)
{

}

template<int n>
PhysicPointComponentProvider<n>::PhysicPointComponentProvider(const PhysicPoint<n>& physicPoint, Vector<freedom(n), double> orientation) :
	PhysicPointPositionProvider<n>(physicPoint),
	_orientation([orientation]() {
		return orientation;
	})
{

}

template<int n>
void PhysicPointComponentProvider<n>::setOrientation(function<Vector<freedom(n), double>()> orientation)
{
	_orientation = orientation;
}

template<int n>
void PhysicPointComponentProvider<n>::setOrientation(Vector<freedom(n), double> orientation)
{
	_orientation = [orientation]() {
		return orientation;
	};
}

template <int n>
Vector<freedom(n), double> PhysicPointComponentProvider<n>::getOrientation() const
{
	return _orientation();
}

template <int n>
PhysicPointComponentProvider<n>* PhysicPointComponentProvider<n>::clone() const
{
	return new PhysicPointComponentProvider<n>(*this);
}

template class PhysicPointComponentProvider<2>;
template class PhysicPointComponentProvider<3>;

}
