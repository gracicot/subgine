#pragma once

#include "../vector-all.h"

#include <functional>

namespace sbg {

template<int n>
struct PositionProvider {
	PositionProvider(std::function<Vector<n, double>()> position);
	PositionProvider(Vector<n, double> position = Vector<n, double>());

	Vector<n, double> getPosition() const;
private:
	std::function<Vector<n, double>()> _position;
};

extern template class PositionProvider<2>;
extern template class PositionProvider<3>;

typedef PositionProvider<2> PositionProvider2D;
typedef PositionProvider<3> PositionProvider3D;

}