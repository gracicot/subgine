#include "displaycomponentprovider.h"

using namespace std;

namespace sbg {

template <int n>
DisplayComponentProvider<n>::DisplayComponentProvider(
	function<Vector<n, double>()> position,
	function<Vector<freedom(n), double>()> orientation,
	function<Vector<n, double>()> scale
) : 
	_position{position},
	_orientation{orientation},
	_scale{scale}
{
	
}

template <int n>
DisplayComponentProvider<n>::DisplayComponentProvider(
	Vector<n, double> position,
	function<Vector<freedom(n), double>()> orientation,
	function<Vector<n, double>()> scale
) : 
	_position{[position]{ return position; }},
	_orientation{orientation},
	_scale{scale}
{
	
}

template <int n>
DisplayComponentProvider<n>::DisplayComponentProvider(
	function<Vector<n, double>()> position,
	Vector<freedom(n), double> orientation,
	function<Vector<n, double>()> scale
) : 
	_position{position},
	_orientation{[orientation]{ return orientation; }},
	_scale{scale}
{
	
}

template <int n>
DisplayComponentProvider<n>::DisplayComponentProvider(
	Vector<n, double> position,
	Vector<freedom(n), double> orientation,
	function<Vector<n, double>()> scale
) : 
	_position{[position]{ return position; }},
	_orientation{[orientation]{ return orientation; }},
	_scale{scale}
{
	
}

template <int n>
DisplayComponentProvider<n>::DisplayComponentProvider(
	function<Vector<n, double>()> position,
	function<Vector<freedom(n), double>()> orientation,
	Vector<n, double> scale
) : 
	_position{position},
	_orientation{orientation},
	_scale{[scale]{ return scale; }}
{
	
}

template <int n>
DisplayComponentProvider<n>::DisplayComponentProvider(
	Vector<n, double> position,
	function<Vector<freedom(n), double>()> orientation,
	Vector<n, double> scale
) : 
	_position{[position]{ return position; }},
	_orientation{orientation},
	_scale{[scale]{ return scale; }}
{
	
}

template <int n>
DisplayComponentProvider<n>::DisplayComponentProvider(
	function<Vector<n, double>()> position,
	Vector<freedom(n), double> orientation,
	Vector<n, double> scale
) : 
	_position{position},
	_orientation{[orientation]{ return orientation; }},
	_scale{[scale]{ return scale; }}
{
	
}

template <int n>
DisplayComponentProvider<n>::DisplayComponentProvider(
	Vector<n, double> position,
	Vector<freedom(n), double> orientation,
	Vector<n, double> scale
) : 
	_position{[position]{ return position; }},
	_orientation{[orientation]{ return orientation; }},
	_scale{[scale]{ return scale; }}
{
	
}

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
