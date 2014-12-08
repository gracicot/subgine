#include "zerocomponentprovider.h"

namespace subgine {

template<int n>
Vector<freedom(n), double> ZeroComponentProvider<n>::getOrientation() const
{
	return {};
}

template<int n>
Vector<n, double> ZeroComponentProvider<n>::getPosition() const
{
	return {};
}

template class ZeroComponentProvider<2>;
template class ZeroComponentProvider<3>;

}