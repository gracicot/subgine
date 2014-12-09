#include "callbackpositionprovider.h"

namespace subgine {

template<int n>
CallbackPositionProvider<n>::CallbackPositionProvider(std::function<Vector<n, double>()> position) : _position(position)
{
	
}

template<int n>
CallbackPositionProvider<n>::CallbackPositionProvider(Vector<n, double> position) : 
	_position([position]() {
		return position;
	})
{
	
}

template<int n>
void CallbackPositionProvider<n>::setPosition(std::function<Vector<n, double>()> position)
{
	_position = position;
}

template<int n>
void CallbackPositionProvider<n>::setPosition(Vector<n, double> position)
{
	_position = [position]() {
		return position;
	};
}

template<int n>
Vector<n, double> CallbackPositionProvider<n>::getPosition() const
{
	return _position();
}

template class CallbackPositionProvider<2>;
template class CallbackPositionProvider<3>;

}