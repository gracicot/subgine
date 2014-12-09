#include "zeropositionprovider.h"

namespace subgine {

template<int n>
Vector<n, double> ZeroPositionProvider<n>::getPosition() const
{
	return {};
}

template class ZeroPositionProvider<2>;
template class ZeroPositionProvider<3>;

}