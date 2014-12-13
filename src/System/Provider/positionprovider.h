#pragma once

#include "../vector-all.h"

namespace sbg {

template<int n>
class PositionProvider
{
public:
	virtual Vector<n, double> getPosition() const = 0;
};

extern template class PositionProvider<2>;
extern template class PositionProvider<3>;

typedef PositionProvider<2> PositionProvider2D;
typedef PositionProvider<3> PositionProvider3D;

}