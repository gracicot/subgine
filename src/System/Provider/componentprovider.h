#pragma once

#include "../vector-all.h"

#include <functional>

namespace sbg {

template <int n>
struct ComponentProvider {
	ComponentProvider(std::function<Vector<n, double>()> position, std::function<Vector<freedom(n), double>()> orientation);
	ComponentProvider(Vector<n, double> position, std::function<Vector<freedom(n), double>()> orientation);
	ComponentProvider(std::function<Vector<n, double>()> position, Vector<freedom(n), double> orientation);
	ComponentProvider(Vector<n, double> position, Vector<freedom(n), double> orientation);
	
	Vector<freedom(n), double> getOrientation() const;
	Vector<n, double> getPosition() const;
	
private:
	std::function<Vector<freedom(n), double>()> _orientation;
	std::function<Vector<n, double>()> _position;
};

extern template class ComponentProvider<2>;
extern template class ComponentProvider<3>;

typedef ComponentProvider<2> ComponentProvider2D;
typedef ComponentProvider<3> ComponentProvider3D;

}
