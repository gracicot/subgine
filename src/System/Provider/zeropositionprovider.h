#pragma once

#include "positionprovider.h"

namespace sbg {

template<int n>
class ZeroPositionProvider : public virtual PositionProvider<n>
{
public:
	Vector<n, double> getPosition() const override;
	ZeroPositionProvider<n>* clone() const override;
};

extern template class ZeroPositionProvider<2>;
extern template class ZeroPositionProvider<3>;

typedef ZeroPositionProvider<2> ZeroPositionProvider2D;
typedef ZeroPositionProvider<3> ZeroPositionProvider3D;

}