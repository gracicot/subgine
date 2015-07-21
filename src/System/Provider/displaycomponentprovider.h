#pragma once

#include "../vector-all.h"
#include "valueprovider.h"
#include <functional>

namespace sbg {

template <int n>
struct DisplayComponentProvider {
	DisplayComponentProvider(
		ValueProvider<Vector<n, double>> position,
		ValueProvider<Vector<freedom(n), double>> orientation,
		ValueProvider<Vector<n, double>> scale
	);
	
	Vector<n, double> getScale() const;
	Vector<freedom(n), double> getOrientation() const;
	Vector<n, double> getPosition() const;
	
private:
	ValueProvider<Vector<n, double>> _scale;
	ValueProvider<Vector<freedom(n), double>> _orientation;
	ValueProvider<Vector<n, double>> _position;
	
};

extern template class DisplayComponentProvider<2>;
extern template class DisplayComponentProvider<3>;

using DisplayComponentProvider2D = DisplayComponentProvider<2>;
using DisplayComponentProvider3D = DisplayComponentProvider<3>;

}