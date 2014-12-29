#include "zerocomponentprovider.h"

using namespace std;

namespace sbg {

template<int n>
Vector<freedom(n), double> ZeroComponentProvider<n>::getOrientation() const
{
	return {};
}

template<int n>
ZeroComponentProvider<n>* ZeroComponentProvider<n>::clone() const
{
	return new ZeroComponentProvider<n>(*this);
}

template class ZeroComponentProvider<2>;
template class ZeroComponentProvider<3>;

}