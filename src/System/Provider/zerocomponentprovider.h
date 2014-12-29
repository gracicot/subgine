#pragma once

#include "componentprovider.h"
#include "zeropositionprovider.h"

namespace sbg {

template<int n>
class ZeroComponentProvider : public virtual ComponentProvider<n>, public virtual ZeroPositionProvider<n>
{
public:
	Vector<freedom(n), double> getOrientation() const override;
	ZeroComponentProvider<n>* clone() const override;
};

extern template class ZeroComponentProvider<2>;
extern template class ZeroComponentProvider<3>;

typedef ZeroComponentProvider<2> ZeroComponentProvider2D;
typedef ZeroComponentProvider<3> ZeroComponentProvider3D;

}
