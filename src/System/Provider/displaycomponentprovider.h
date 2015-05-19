#pragma once

#include "../vector-all.h"

#include <functional>

namespace sbg {

template <int n>
struct DisplayComponentProvider {
	DisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		std::function<Vector<freedom(n), double>()> orientation,
		std::function<Vector<n, double>()> scale
	);
	
	DisplayComponentProvider(
		Vector<n, double> position,
		std::function<Vector<freedom(n), double>()> orientation,
		std::function<Vector<n, double>()> scale
	);
	
	DisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		Vector<freedom(n), double> orientation,
		std::function<Vector<n, double>()> scale
	);
	
	DisplayComponentProvider(
		Vector<n, double> position,
		Vector<freedom(n), double> orientation,
		std::function<Vector<n, double>()> scale
	);
	
	DisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		std::function<Vector<freedom(n), double>()> orientation,
		Vector<n, double> scale = {1}
	);
	
	DisplayComponentProvider(
		Vector<n, double> position,
		std::function<Vector<freedom(n), double>()> orientation,
		Vector<n, double> scale = {1}
	);
	
	DisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		Vector<freedom(n), double> orientation = Vector<freedom(n), double>(),
		Vector<n, double> scale = {1}
	);
	
	DisplayComponentProvider(
		Vector<n, double> position = Vector<n, double>(),
		Vector<freedom(n), double> orientation = Vector<freedom(n), double>(),
		Vector<n, double> scale = {1}
	);
	
	Vector<n, double> getScale() const;
	Vector<freedom(n), double> getOrientation() const;
	Vector<n, double> getPosition() const;
	
private:
	std::function<Vector<n, double>()> _scale;
	std::function<Vector<freedom(n), double>()> _orientation;
	std::function<Vector<n, double>()> _position;
	
};

extern template class DisplayComponentProvider<2>;
extern template class DisplayComponentProvider<3>;

typedef DisplayComponentProvider<2> DisplayComponentProvider2D;
typedef DisplayComponentProvider<3> DisplayComponentProvider3D;

}