#include "zerodisplaycomponentprovider.h"

namespace subgine {

template<int n>
double ZeroDisplayComponentProvider<n>::getScale() const
{
	return 0;
}

template class ZeroDisplayComponentProvider<2>;
template class ZeroDisplayComponentProvider<3>;

}