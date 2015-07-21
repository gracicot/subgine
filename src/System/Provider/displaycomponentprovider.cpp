#include "displaycomponentprovider.h"

using namespace std;

namespace sbg {

template <int n>
DisplayComponentProvider<n>::DisplayComponentProvider(
	ValueProvider<Vector<n, double>> position,
	ValueProvider<Vector<freedom(n), double>> orientation,
	ValueProvider<Vector<n, double>> scale
) : 
	_position{move(position)},
	_orientation{move(orientation)},
	_scale{move(scale)}
{}

template <int n>
Vector<n, double> DisplayComponentProvider<n>::getScale() const
{
	return _scale();
}

template <int n>
Vector <freedom(n), double> DisplayComponentProvider<n>::getOrientation() const
{
	return _orientation();
}

template<int n>
Vector<n, double> DisplayComponentProvider<n>::getPosition() const
{
	return _position();
}

template class DisplayComponentProvider<2>;
template class DisplayComponentProvider<3>;

}
