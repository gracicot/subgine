#include "physicpointpositionprovider.h"

#include "../physicpoint.h"

using namespace std;

namespace sbg {

template<int n>
PhysicPointPositionProvider<n>::PhysicPointPositionProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint) : _physicPoint(physicPoint)
{
	
}

template<int n>
Vector<n, double> PhysicPointPositionProvider<n>::getPosition() const
{
	return _physicPoint.expired() ? Vector<n, double>{} : _physicPoint.lock()->getPosition();
}

template<int n>
PhysicPointPositionProvider<n>* PhysicPointPositionProvider<n>::clone() const
{
	return new PhysicPointPositionProvider<n>(*this);
}

template class PhysicPointPositionProvider<2>;
template class PhysicPointPositionProvider<3>;

}
