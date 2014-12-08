#include "physicbodydisplaycomponentprovider.h"

namespace subgine {
namespace physic {

template<int n>
PhysicBodyDisplayComponentProvider<n>::PhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, std::function<double()> scale) : 
	PhysicBodyComponentProvider<n>(physicBody),
	_scale(scale)
{
	
}

template<int n>
PhysicBodyDisplayComponentProvider<n>::PhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, double scale) : 
	PhysicBodyComponentProvider<n>(physicBody),
	_scale([scale]() {
		return scale;
	})
{

}

template<int n>
void PhysicBodyDisplayComponentProvider<n>::setScale(std::function<double()> scale)
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
}