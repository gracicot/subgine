#include "callbackpositionprovider.h"

using namespace std;

namespace sbg {

template<int n>
CallbackPositionProvider<n>::CallbackPositionProvider(function<Vector<n, double>()> position) : _position(position)
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
void CallbackPositionProvider<n>::setPosition(function<Vector<n, double>()> position)
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

template<int n>
CallbackPositionProvider<n>* CallbackPositionProvider<n>::clone() const
{
	return new CallbackPositionProvider<n>(*this);
}

template class CallbackPositionProvider<2>;
template class CallbackPositionProvider<3>;

}