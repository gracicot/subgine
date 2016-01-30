#pragma once

#include "../../system.hpp"

#include <memory>

namespace sbg {

template<int n> struct PhysicPoint;

template<int n>
PositionProvider<n> makePhysicPointPositionProvider(const PhysicPoint<n>& physicPointRef);

constexpr auto makePhysicPoint2DPositionProvider = makePhysicPointPositionProvider<2>;
constexpr auto makePhysicPoint3DPositionProvider = makePhysicPointPositionProvider<3>;

extern template PositionProvider<2> makePhysicPointPositionProvider<2>(const PhysicPoint<2>&);
extern template PositionProvider<3> makePhysicPointPositionProvider<3>(const PhysicPoint<3>&);

}
