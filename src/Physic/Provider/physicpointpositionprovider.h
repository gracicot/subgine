#pragma once

#include "../../system.hpp"

#include <memory>

namespace sbg {

template<int n> class PhysicPoint;

template<int n>
PositionProvider<n> makePhysicPointPositionProvider(std::weak_ptr<const PhysicPoint<n>> physicPointRef);

constexpr auto makePhysicPoint2DPositionProvider = makePhysicPointPositionProvider<2>;
constexpr auto makePhysicPoint3DPositionProvider = makePhysicPointPositionProvider<3>;

extern template PositionProvider<2> makePhysicPointPositionProvider<2>(std::weak_ptr<const PhysicPoint<2>>);
extern template PositionProvider<3> makePhysicPointPositionProvider<3>(std::weak_ptr<const PhysicPoint<3>>);

}
