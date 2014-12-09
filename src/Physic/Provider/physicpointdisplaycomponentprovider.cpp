#include "physicpointdisplaycomponentprovider.h"

namespace subgine {
namespace physic {

template<int n>
PhysicPointDisplayComponentProvider<n>::PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, Vector<freedom(n), double> orientation, double scale) :
	PhysicPointPositionProvider<n>(physicPoint),
	PhysicPointComponentProvider<n>(physicPoint, orientation),
	_scale([scale]() {
		return scale;
	})
{
	
}

template<int n>
PhysicPointDisplayComponentProvider<n>::PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, std::function<Vector<freedom(n), double>()> orientation, double scale) :
	PhysicPointPositionProvider<n>(physicPoint),
	PhysicPointComponentProvider<n>(physicPoint, orientation),
	_scale([scale]() {
		return scale;
	})
{
	
}

template<int n>
PhysicPointDisplayComponentProvider<n>::PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, Vector<freedom(n), double> orientation, std::function<double()> scale) :
	PhysicPointPositionProvider<n>(physicPoint),
	PhysicPointComponentProvider<n>(physicPoint, orientation),
	_scale(scale)
{
	
}

template<int n>
PhysicPointDisplayComponentProvider<n>::PhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, std::function<Vector<freedom(n), double>()> orientation, std::function<double()> scale) :
	PhysicPointPositionProvider<n>(physicPoint),
	PhysicPointComponentProvider<n>(physicPoint, orientation),
	_scale(scale)
{
	
}

template<int n>
void PhysicPointDisplayComponentProvider<n>::setScale(double scale)
{
	_scale = [scale]() {
		return scale;
	};
}

template<int n>
void PhysicPointDisplayComponentProvider<n>::setScale(std::function<double()> scale)
{
	_scale = scale;
}

template<int n>
double PhysicPointDisplayComponentProvider<n>::getScale() const
{
	return _scale();
}

template class PhysicPointDisplayComponentProvider<2>;
template class PhysicPointDisplayComponentProvider<3>;

}
}