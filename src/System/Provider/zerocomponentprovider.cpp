#include "zerocomponentprovider.h"

using namespace std;

namespace sbg {

template<int n>
ComponentProvider<n> makeZeroComponentProvider()
{
	return {Vector<n, double>{0}, Vector<freedom(n), double>{0}};
}

template ComponentProvider<2> makeZeroComponentProvider<2>();
template ComponentProvider<3> makeZeroComponentProvider<3>();

}