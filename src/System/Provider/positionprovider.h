#pragma once

#include "../vector-all.h"
#include "provider.h"
#include <functional>

namespace sbg {

template<int n>
struct PositionProvider {
	PositionProvider(Provider<Vector<n, double>> position);
	
	template<typename T, typename std::enable_if<std::is_constructible<Provider<Vector<n, double>>, T>::value, int>::type = 0>
	PositionProvider(T position) : _position{position} {}
	
	Vector<n, double> getPosition() const;
	
private:
	Provider<Vector<n, double>> _position;
};

extern template struct PositionProvider<2>;
extern template struct PositionProvider<3>;

using PositionProvider2D = PositionProvider<2>;
using PositionProvider3D = PositionProvider<3>;

}