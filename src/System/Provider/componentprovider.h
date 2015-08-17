#pragma once

#include "../vector-all.h"
#include "provider.h"
#include <functional>

namespace sbg {

template <int n>
struct ComponentProvider {
	ComponentProvider(Provider<Vector<n, double>> position, Provider<Vector<freedom(n), double>> orientation);
	
	Vector<freedom(n), double> getOrientation() const;
	Vector<n, double> getPosition() const;
	
private:
	Provider<Vector<freedom(n), double>> _orientation;
	Provider<Vector<n, double>> _position;
};

extern template class ComponentProvider<2>;
extern template class ComponentProvider<3>;

using ComponentProvider2D = ComponentProvider<2>;
using ComponentProvider3D = ComponentProvider<3>;

}
