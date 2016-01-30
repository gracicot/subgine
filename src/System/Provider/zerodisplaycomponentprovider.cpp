#include "zerodisplaycomponentprovider.h"

using namespace std;

namespace sbg {

template<int n>
DisplayComponentProvider<n> makeZeroDisplayComponentProvier()
{
	return {Vector<n, double>(), Vector<freedom(n), double>(), Vector<n, double>{1}};
}

template DisplayComponentProvider<2> makeZeroDisplayComponentProvier<2>();
template DisplayComponentProvider<3> makeZeroDisplayComponentProvier<3>();

}