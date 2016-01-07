#pragma once

#include "../vector-all.h"
#include "provider.h"
#include <functional>

namespace sbg {

template <int n>
struct DisplayComponentProvider {
	DisplayComponentProvider(
		Provider<Vector<n, double>> position,
		Provider<Vector<freedom(n), double>> orientation,
		Provider<Vector<n, double>> scale
	);
	
	Vector<n, double> getScale() const;
	Vector<freedom(n), double> getOrientation() const;
	Vector<n, double> getPosition() const;
	
private:
	Provider<Vector<n, double>> _scale;
	Provider<Vector<freedom(n), double>> _orientation;
	Provider<Vector<n, double>> _position;
	
};

extern template struct DisplayComponentProvider<2>;
extern template struct DisplayComponentProvider<3>;

using DisplayComponentProvider2D = DisplayComponentProvider<2>;
using DisplayComponentProvider3D = DisplayComponentProvider<3>;

}