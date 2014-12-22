#include "physicpointpositionprovider.h"

using namespace std;

namespace sbg {

template<int n>
PhysicPointPositionProvider<n>::PhysicPointPositionProvider(const PhysicPoint<n>& physicPoint) : _physicPoint(physicPoint)
{
	
}

template<int n>
Vector< n, double > PhysicPointPositionProvider<n>::getPosition() const
{
	return _physicPoint.getPosition();
}

template class PhysicPointPositionProvider<2>;
template class PhysicPointPositionProvider<3>;

}