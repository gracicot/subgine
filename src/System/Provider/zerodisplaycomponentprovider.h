#pragma once

#include "displaycomponentprovider.h"
#include "zerocomponentprovider.h"

namespace sbg {

template<int n>
class ZeroDisplayComponentProvider : public virtual ZeroComponentProvider<n>, public virtual DisplayComponentProvider<n>
{
public:
	Vector<n, double> getScale() const override;
};

extern template class ZeroDisplayComponentProvider<2>;
extern template class ZeroDisplayComponentProvider<3>;

typedef ZeroDisplayComponentProvider<2> ZeroDisplayComponentProvider2D;
typedef ZeroDisplayComponentProvider<3> ZeroDisplayComponentProvider3D;

}
