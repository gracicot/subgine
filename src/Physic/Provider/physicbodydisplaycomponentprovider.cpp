#include "physicbodydisplaycomponentprovider.h"

#include "../physicbody.h"

using namespace std;

namespace sbg {

template<int n>
PhysicBodyDisplayComponentProvider<n>::PhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<n>> physicBody, function<Vector<n, double>()> scale) :
	PhysicPointPositionProvider<n>(physicBody),
	PhysicBodyComponentProvider<n>(physicBody),
	_scale(scale)
{
	
}

template<int n>
PhysicBodyDisplayComponentProvider<n>::PhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<n>> physicBody, Vector<n, double> scale) :
	PhysicPointPositionProvider<n>(physicBody),
	PhysicBodyComponentProvider<n>(physicBody),
	_scale([scale]() {
		return scale;
	})
{

}

template<int n>
void PhysicBodyDisplayComponentProvider<n>::setScale(function<Vector<n, double>()> scale)
{
	_scale = scale;
}

template<int n>
void PhysicBodyDisplayComponentProvider<n>::setScale(Vector<n, double> scale)
{
	_scale = [scale]() {
		return scale;
	};
}

template<int n>
Vector<n, double> PhysicBodyDisplayComponentProvider<n>::getScale() const
{
	return _scale();
}

template<int n>
PhysicBodyDisplayComponentProvider<n>* PhysicBodyDisplayComponentProvider<n>::clone() const
{
	return new PhysicBodyDisplayComponentProvider<n>(*this);
}

template class PhysicBodyDisplayComponentProvider<2>;
template class PhysicBodyDisplayComponentProvider<3>;

}