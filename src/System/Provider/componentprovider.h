#pragma once

#include "positionprovider.h"

namespace subgine {

template <int n>
class ComponentProvider : public virtual PositionProvider<n>
{
public:
	virtual Vector<freedom(n), double> getOrientation() const = 0;
};

extern template class ComponentProvider<2>;
extern template class ComponentProvider<3>;

typedef ComponentProvider<2> ComponentProvider2D;
typedef ComponentProvider<3> ComponentProvider3D;

}