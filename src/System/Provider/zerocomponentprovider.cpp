#include "zerocomponentprovider.h"

using namespace std;

namespace sbg {

template<int n>
Vector<freedom(n), double> ZeroComponentProvider<n>::getOrientation() const
{
	return {};
}

template class ZeroComponentProvider<2>;
template class ZeroComponentProvider<3>;

}