#include "componentprovider.h"

using namespace std;

namespace sbg {

template <int n>
ComponentProvider<n>::ComponentProvider(Provider<Vector<n, double>> position, Provider<Vector<freedom(n), double>> orientation) :
	_orientation{move(orientation)},
	_position{move(position)}
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

template struct ComponentProvider<2>;
template struct ComponentProvider<3>;

}
