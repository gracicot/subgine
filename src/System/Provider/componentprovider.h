#pragma once

#include "positionprovider.h"
#include "../clonable.h"

namespace sbg {

template <int n>
class ComponentProvider : public virtual PositionProvider<n>, public virtual Clonable
{
public:
	virtual Vector<freedom(n), double> getOrientation() const = 0;
	virtual ComponentProvider<n>* clone() const = 0;
};

extern template class ComponentProvider<2>;
extern template class ComponentProvider<3>;

typedef ComponentProvider<2> ComponentProvider2D;
typedef ComponentProvider<3> ComponentProvider3D;

}