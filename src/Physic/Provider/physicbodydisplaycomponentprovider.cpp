#include "physicbodydisplaycomponentprovider.h"

using namespace std;

namespace sbg {

template<int n>
PhysicBodyDisplayComponentProvider<n>::PhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, function<double()> scale) :
	PhysicPointPositionProvider<n>(physicBody),
	PhysicBodyComponentProvider<n>(physicBody),
	_scale(scale)
{
	
}

template<int n>
PhysicBodyDisplayComponentProvider<n>::PhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, double scale) :
	PhysicPointPositionProvider<n>(physicBody),
	PhysicBodyComponentProvider<n>(physicBody),
	_scale([scale]() {
		return scale;
	})
{

}

template<int n>
void PhysicBodyDisplayComponentProvider<n>::setScale(function<double()> scale)
{
	_scale = scale;
}

template<int n>
void PhysicBodyDisplayComponentProvider<n>::setScale(double scale)
{
	_scale = [scale]() {
		return scale;
	};
}

template<int n>
double PhysicBodyDisplayComponentProvider<n>::getScale() const
{
	return _scale();
}

template class PhysicBodyDisplayComponentProvider<2>;
template class PhysicBodyDisplayComponentProvider<3>;

}