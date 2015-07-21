#include "positionprovider.h"

using namespace std;

namespace sbg {

template<int n>
PositionProvider<n>::PositionProvider(ValueProvider<Vector<n, double>> position) : _position{move(position)}
{
	
}

template<int n>
Vector<n, double> PositionProvider<n>::getPosition() const
{
	return _position();
}

template class PositionProvider<2>;
template class PositionProvider<3>;

}