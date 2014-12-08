#pragma once

#include "componentprovider.h"

namespace subgine {

template<int n>
class ZeroComponentProvider : public virtual ComponentProvider<n>
{
public:
	virtual Vector<freedom(n), double> getOrientation() const override;
	virtual Vector<n, double> getPosition() const override;
};

extern template class ZeroComponentProvider<2>;
extern template class ZeroComponentProvider<3>;

typedef ZeroComponentProvider<2> ZeroComponentProvider2D;
typedef ZeroComponentProvider<3> ZeroComponentProvider3D;

}
