#pragma once

#include "../vector-all.h"
#include "provider.h"
#include <functional>

namespace sbg {

template<int n>
struct PositionProvider {
	PositionProvider(Provider<Vector<n, double>> position);
	Vector<n, double> getPosition() const;
	
private:
	Provider<Vector<n, double>> _position;
};

extern template struct PositionProvider<2>;
extern template struct PositionProvider<3>;

using PositionProvider2D = PositionProvider<2>;
using PositionProvider3D = PositionProvider<3>;

}