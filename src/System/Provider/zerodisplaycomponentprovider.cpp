#include "zerodisplaycomponentprovider.h"

using namespace std;

namespace sbg {

template<int n>
Vector<n, double> ZeroDisplayComponentProvider<n>::getScale() const
{
	return {};
}

template class ZeroDisplayComponentProvider<2>;
template class ZeroDisplayComponentProvider<3>;

}