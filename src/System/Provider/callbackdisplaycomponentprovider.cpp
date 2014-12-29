#include "callbackdisplaycomponentprovider.h"

using namespace std;

namespace sbg {

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	function<Vector<n, double>()> position,
	function<Vector<freedom(n), double>()> orientation,
	function<Vector<n, double>()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	Vector<n, double> position,
	function<Vector<freedom(n), double>()> orientation,
	function<Vector<n, double>()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	function<Vector<n, double>()> position,
	Vector<freedom(n), double> orientation,
	function<Vector<n, double>()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	Vector<n, double> position,
	Vector<freedom(n), double> orientation,
	function<Vector<n, double>()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	function<Vector<n, double>()> position,
	function<Vector<freedom(n), double>()> orientation,
	Vector<n, double> scale
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
	Vector<n, double> scale
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
	Vector<n, double> scale
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
	Vector<n, double> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale([scale]() {
		return scale;
	})
{
	
}

template <int n>
void CallbackDisplayComponentProvider<n>::setScale(Vector<n, double> scale)
{
	_scale = [scale]() {
		return scale;
	};
}

template <int n>
void CallbackDisplayComponentProvider<n>::setScale(function<Vector<n, double>()> scale)
{
	_scale = scale;
}

template <int n>
Vector<n, double> CallbackDisplayComponentProvider<n>::getScale() const
{
	return _scale();
}

template <int n>
CallbackDisplayComponentProvider<n>* CallbackDisplayComponentProvider<n>::clone() const
{
	return new CallbackDisplayComponentProvider<n>(*this);
}

template class CallbackDisplayComponentProvider<2>;
template class CallbackDisplayComponentProvider<3>;

}
