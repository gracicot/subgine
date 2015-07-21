#pragma once

#include "../../system.hpp"

namespace sbg {

template<int n> class PhysicPoint;

template<int n>
DisplayComponentProvider<n> makePhysicPointDisplayComponentProvider(const PhysicPoint<n>& physicPoint, ValueProvider<Vector<freedom(n), double>> orientation = Vector<freedom(n), double>{}, ValueProvider<Vector<n, double>> scale = Vector<n, double>{});

constexpr auto makePhysicPoint2DDisplayComponentProvider = makePhysicPointDisplayComponentProvider<2>;
constexpr auto makePhysicPoint3DDisplayComponentProvider = makePhysicPointDisplayComponentProvider<3>;

extern template DisplayComponentProvider<2> makePhysicPointDisplayComponentProvider<2>(const PhysicPoint<2>&, ValueProvider<Vector<freedom(2), double>>, ValueProvider<Vector<2, double>>);
extern template DisplayComponentProvider<3> makePhysicPointDisplayComponentProvider<3>(const PhysicPoint<3>&, ValueProvider<Vector<freedom(3), double>>, ValueProvider<Vector<3, double>>);

}
