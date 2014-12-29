#include "zeropositionprovider.h"

using namespace std;

namespace sbg {

template<int n>
Vector<n, double> ZeroPositionProvider<n>::getPosition() const
{
	return {};
}

template<int n>
ZeroPositionProvider<n>* ZeroPositionProvider<n>::clone() const
{
	return new ZeroPositionProvider<n>(*this);
}

template class ZeroPositionProvider<2>;
template class ZeroPositionProvider<3>;

}