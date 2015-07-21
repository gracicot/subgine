#pragma once

#include "../vector-all.h"
#include "valueprovider.h"
#include <functional>

namespace sbg {

template <int n>
struct ComponentProvider {
	ComponentProvider(ValueProvider<Vector<n, double>> position, ValueProvider<Vector<freedom(n), double>> orientation);
	
	Vector<freedom(n), double> getOrientation() const;
	Vector<n, double> getPosition() const;
	
private:
	ValueProvider<Vector<freedom(n), double>> _orientation;
	ValueProvider<Vector<n, double>> _position;
};

extern template class ComponentProvider<2>;
extern template class ComponentProvider<3>;

using ComponentProvider2D = ComponentProvider<2>;
using ComponentProvider3D = ComponentProvider<3>;

}
