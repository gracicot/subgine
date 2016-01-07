#include "nsphere.h"

namespace sbg {
namespace shape {

template<int n>
NSphere<n>::NSphere(double radius) : _radius{radius} {}

template<int n>
double NSphere<n>::getRadius() const
{
	return _radius;
}

template<int n>
void NSphere<n>::setRadius(double radius)
{
	_radius = radius;
}

template struct NSphere<2>;
template struct NSphere<3>;

}
}
