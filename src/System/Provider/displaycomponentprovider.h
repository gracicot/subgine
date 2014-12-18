#pragma once

#include "componentprovider.h"

#include "../vector-all.h"

namespace sbg {

template<int n>
class DisplayComponentProvider : public virtual ComponentProvider<n>
{
public:
	virtual Vector<n, double> getScale() const = 0;
};

extern template class DisplayComponentProvider<2>;
extern template class DisplayComponentProvider<3>;

typedef DisplayComponentProvider<2> DisplayComponentProvider2D;
typedef DisplayComponentProvider<3> DisplayComponentProvider3D;

}
