#include "zeropositionprovider.h"

using namespace std;

namespace sbg {

template<int n>
PositionProvider<n> makeZeroPositionProvider()
{
	return {Vector<n, double>{0}};
}

template PositionProvider<2> makeZeroPositionProvider<2>();
template PositionProvider<3> makeZeroPositionProvider<3>();

}
