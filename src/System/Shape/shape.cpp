#include "shape.h"

using namespace std;

namespace sbg {
namespace shape {

template<int n>
Shape<n>::~Shape()
{

}

template struct Shape<2>;
template struct Shape<3>;

}
}