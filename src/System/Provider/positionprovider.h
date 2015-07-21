#pragma once

#include "../vector-all.h"
#include "valueprovider.h"
#include <functional>

namespace sbg {

template<int n>
struct PositionProvider {
	PositionProvider(ValueProvider<Vector<n, double>> position);
	Vector<n, double> getPosition() const;
	
private:
	ValueProvider<Vector<n, double>> _position;
};

extern template class PositionProvider<2>;
extern template class PositionProvider<3>;

using PositionProvider2D = PositionProvider<2>;
using PositionProvider3D = PositionProvider<3>;

}