#pragma once

#include "../../system.hpp"

#include <memory>
#include <functional>

namespace sbg {

template<int n> struct PhysicPoint;

template<int n>
ComponentProvider<n> makePhysicPointComponentProvider(const PhysicPoint<n>& physicPoint, Provider<Vector<freedom(n), double>> orientation = Vector<freedom(n), double>{});

constexpr auto makePhysicPoint2DComponentProvider = makePhysicPointComponentProvider<2>;
constexpr auto makePhysicPoint3DComponentProvider = makePhysicPointComponentProvider<3>;

extern template ComponentProvider<2> makePhysicPointComponentProvider<2>(const PhysicPoint<2>&, Provider<Vector<freedom(2), double>>);
extern template ComponentProvider<3> makePhysicPointComponentProvider<3>(const PhysicPoint<3>&, Provider<Vector<freedom(3), double>>);

}