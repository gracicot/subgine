#include "positionprovider.h"

using namespace std;

namespace sbg {

template<int n>
PositionProvider<n>::PositionProvider(Provider<Vector<n, double>> position) : _position{move(position)}
{
	
}

template<int n>
Vector<n, double> PositionProvider<n>::getPosition() const
{
	return _position();
}

template struct PositionProvider<2>;
template struct PositionProvider<3>;

}