#pragma once

#include "vector-all.h"

namespace subgine {

template <int n>
class ComponentProvider
{
public:
	virtual Vector<freedom(n), double> getOrientation() const = 0;
	virtual Vector<n, double> getPosition() const = 0;
};

extern template class ComponentProvider<2>;
extern template class ComponentProvider<3>;

typedef ComponentProvider<2> ComponentProvider2D;
typedef ComponentProvider<3> ComponentProvider3D;

}