#include "componentprovider.h"

using namespace std;

namespace sbg {

template <int n>
ComponentProvider<n>::ComponentProvider(function<Vector<n, double>()> position, function<Vector<freedom(n), double>()> orientation) :
	_position(position),
	_orientation(orientation)
{
	
}

template <int n>
ComponentProvider<n>::ComponentProvider(Vector<n, double> position, function<Vector<freedom(n), double>()> orientation) :
	_position([position]{ return position; }),
	_orientation(orientation)
{
	
}

template <int n>
ComponentProvider<n>::ComponentProvider(function<Vector<n, double>()> position, Vector<freedom(n), double> orientation) :
	_position(position),
	_orientation([orientation] { return orientation; })
{
	
}

template <int n>
ComponentProvider<n>::ComponentProvider(Vector<n, double> position, Vector<freedom(n), double> orientation) :
	_position([position]{ return position; }),
	_orientation([orientation] { return orientation; })
{
	
}

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
