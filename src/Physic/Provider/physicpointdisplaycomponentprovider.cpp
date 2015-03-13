#include "physicpointdisplaycomponentprovider.h"

using namespace std;

namespace sbg {

template<int n>
PhysicPointDisplayComponentProvider<n>::PhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, Vector<freedom(n), double> orientation, Vector<n, double> scale) :
	PhysicPointPositionProvider<n>(physicPoint),
	PhysicPointComponentProvider<n>(physicPoint, orientation),
	_scale([scale]() {
		return scale;
	})
{
	
}

template<int n>
PhysicPointDisplayComponentProvider<n>::PhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, function<Vector<freedom(n), double>()> orientation, Vector<n, double> scale) :
	PhysicPointPositionProvider<n>(physicPoint),
	PhysicPointComponentProvider<n>(physicPoint, orientation),
	_scale([scale]() {
		return scale;
	})
{
	
}

template<int n>
PhysicPointDisplayComponentProvider<n>::PhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, Vector<freedom(n), double> orientation, function<Vector<n, double>()> scale) :
	PhysicPointPositionProvider<n>(physicPoint),
	PhysicPointComponentProvider<n>(physicPoint, orientation),
	_scale(scale)
{
	
}

template<int n>
PhysicPointDisplayComponentProvider<n>::PhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, function<Vector<freedom(n), double>()> orientation, function<Vector<n, double>()> scale) :
	PhysicPointPositionProvider<n>(physicPoint),
	PhysicPointComponentProvider<n>(physicPoint, orientation),
	_scale(scale)
{
	
}

template<int n>
void PhysicPointDisplayComponentProvider<n>::setScale(Vector<n, double> scale)
{
	_scale = [scale]() {
		return scale;
	};
}

template<int n>
void PhysicPointDisplayComponentProvider<n>::setScale(function<Vector<n, double>()> scale)
{
	_scale = scale;
}

template<int n>
Vector<n, double> PhysicPointDisplayComponentProvider<n>::getScale() const
{
	return _scale();
}

template<int n>
PhysicPointDisplayComponentProvider<n>* PhysicPointDisplayComponentProvider<n>::clone() const
{
	return new PhysicPointDisplayComponentProvider<n>(*this);
}

template class PhysicPointDisplayComponentProvider<2>;
template class PhysicPointDisplayComponentProvider<3>;

}