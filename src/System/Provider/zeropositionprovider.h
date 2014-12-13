#pragma once

#include "positionprovider.h"

namespace sbg {

template<int n>
class ZeroPositionProvider : public virtual PositionProvider<n>
{
public:
	virtual Vector<n, double> getPosition() const override;
};

extern template class ZeroPositionProvider<2>;
extern template class ZeroPositionProvider<3>;

typedef ZeroPositionProvider<2> ZeroPositionProvider2D;
typedef ZeroPositionProvider<3> ZeroPositionProvider3D;

}