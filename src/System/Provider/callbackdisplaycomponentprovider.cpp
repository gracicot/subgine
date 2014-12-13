#include "callbackdisplaycomponentprovider.h"

using namespace std;

namespace sbg {

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	function<Vector<n, double>()> position,
	function<Vector<freedom(n), double>()> orientation,
	function<double()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	Vector<n, double> position,
	function<Vector<freedom(n), double>()> orientation,
	function<double()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	function<Vector<n, double>()> position,
	Vector<freedom(n), double> orientation,
	function<double()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	Vector<n, double> position,
	Vector<freedom(n), double> orientation,
	function<double()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	function<Vector<n, double>()> position,
	function<Vector<freedom(n), double>()> orientation,
	double scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale([scale]() {
		return scale;
	})
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	Vector<n, double> position,
	function<Vector<freedom(n), double>()> orientation,
	double scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale([scale]() {
		return scale;
	})
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	function<Vector<n, double>()> position,
	Vector<freedom(n), double> orientation,
	double scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale([scale]() {
		return scale;
	})
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	Vector<n, double> position,
	Vector<freedom(n), double> orientation,
	double scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale([scale]() {
		return scale;
	})
{
	
}

template <int n>
void CallbackDisplayComponentProvider<n>::setScale(double scale)
{
	_scale = [scale]() {
		return scale;
	};
}

template <int n>
void CallbackDisplayComponentProvider<n>::setScale(function<double()> scale)
{
	_scale = scale;
}

template <int n>
double CallbackDisplayComponentProvider<n>::getScale() const
{
	return _scale();
}

template class CallbackDisplayComponentProvider<2>;
template class CallbackDisplayComponentProvider<3>;

}
