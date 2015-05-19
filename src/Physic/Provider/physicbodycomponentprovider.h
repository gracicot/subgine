#pragma once

#include "../../system.hpp"

#include <memory>

namespace sbg {

template<int n> class PhysicBody;

template<int n>
PositionProvider<n> makePhysicBodyComponentProvider(std::weak_ptr<const PhysicBody<n>> physicBody);

constexpr auto makePhysicBody2DComponentProvider = makePhysicBodyComponentProvider<2>;
constexpr auto makePhysicBody3DComponentProvider = makePhysicBodyComponentProvider<3>;

extern template PositionProvider<2> makePhysicBodyComponentProvider<2>(std::weak_ptr<const PhysicBody<2>>);
extern template PositionProvider<3> makePhysicBodyComponentProvider<3>(std::weak_ptr<const PhysicBody<3>>);

}