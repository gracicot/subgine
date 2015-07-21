#include "componentprovider.h"

using namespace std;

namespace sbg {

template <int n>
ComponentProvider<n>::ComponentProvider(ValueProvider<Vector<n, double>> position, ValueProvider<Vector<freedom(n), double>> orientation) :
	_position{move(position)},
	_orientation{move(orientation)}
{}

template <int n>
Vector <freedom(n), double> ComponentProvider<n>::getOrientation() const
{
	return _orientation();
}

template<int n>
Vector<n, double> ComponentProvider<n>::getPosition() const
{
	return _position();
}

template class ComponentProvider<2>;
template class ComponentProvider<3>;

}
