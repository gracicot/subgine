#include "callbackdisplaycomponentprovider.h"

namespace subgine {

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	std::function<Vector<n, double>()> position,
	std::function<Vector<freedom(n), double>()> orientation,
	std::function<double()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	Vector<n, double> position,
	std::function<Vector<freedom(n), double>()> orientation,
	std::function<double()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	std::function<Vector<n, double>()> position,
	Vector<freedom(n), double> orientation,
	std::function<double()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	Vector<n, double> position,
	Vector<freedom(n), double> orientation,
	std::function<double()> scale
) : 
	CallbackComponentProvider<n>(position, orientation),
	_scale(scale)
{
	
}

template <int n>
CallbackDisplayComponentProvider<n>::CallbackDisplayComponentProvider(
	std::function<Vector<n, double>()> position,
	std::function<Vector<freedom(n), double>()> orientation,
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
	std::function<Vector<freedom(n), double>()> orientation,
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
	std::function<Vector<n, double>()> position,
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
void CallbackDisplayComponentProvider<n>::setScale(std::function<double()> scale)
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
