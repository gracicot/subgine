#include "callbackcomponentprovider.h"

namespace subgine {

template <int n>
CallbackComponentProvider<n>::CallbackComponentProvider(std::function<Vector<n, double>()> position, std::function<Vector<freedom(n), double>()> orientation) : 
	CallbackPositionProvider<n>(position),
	_orientation(orientation)
{
	
}

template <int n>
CallbackComponentProvider<n>::CallbackComponentProvider(Vector<n, double> position, std::function<Vector<freedom(n), double>()> orientation) :
	CallbackPositionProvider<n>(position),
	_orientation(orientation)
{
	
}

template <int n>
CallbackComponentProvider<n>::CallbackComponentProvider(std::function<Vector<n, double>()> position, Vector<freedom(n), double> orientation) :
	CallbackPositionProvider<n>(position),
	_orientation([orientation]() {
		return orientation;
	})
{
	
}

template <int n>
CallbackComponentProvider<n>::CallbackComponentProvider(Vector<n, double> position, Vector<freedom(n), double> orientation) :
	CallbackPositionProvider<n>(position),
	_orientation([orientation]() {
		return orientation;
	})
{
	
}

template <int n>
void CallbackComponentProvider<n>::setOrientation(std::function<Vector<freedom(n), double>()> orientation)
{
	_orientation = orientation;
}

template <int n>
void CallbackComponentProvider<n>::setOrientation(Vector<freedom(n), double> orientation)
{
	_orientation = [orientation]() {
		return orientation;
	};
}

template <int n>
Vector <freedom(n), double> CallbackComponentProvider<n>::getOrientation() const
{
	return _orientation();
}

template class CallbackComponentProvider<2>;
template class CallbackComponentProvider<3>;

}
