#include "zerodisplaycomponentprovider.h"

using namespace std;

namespace sbg {

template<int n>
double ZeroDisplayComponentProvider<n>::getScale() const
{
	return 0;
}

template class ZeroDisplayComponentProvider<2>;
template class ZeroDisplayComponentProvider<3>;

}