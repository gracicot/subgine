#include "abstractshapeinfo.h"

namespace sbg {

template<int n>
AbstractShapeInfo<n>::~AbstractShapeInfo()
{

}

template struct AbstractShapeInfo<2>;
template struct AbstractShapeInfo<3>;

}
