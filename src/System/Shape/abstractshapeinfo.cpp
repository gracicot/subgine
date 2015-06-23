#include "abstractshapeinfo.h"

namespace sbg {

template<int n>
AbstractShapeInfo<n>::~AbstractShapeInfo()
{

}

template class AbstractShapeInfo<2>;
template class AbstractShapeInfo<3>;

}
