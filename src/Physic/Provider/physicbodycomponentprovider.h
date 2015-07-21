#pragma once

#include "../../system.hpp"

#include <memory>

namespace sbg {

template<int n> class PhysicBody;

template<int n>
ComponentProvider<n> makePhysicBodyComponentProvider(const PhysicBody<n>& physicBody);

extern template ComponentProvider<2> makePhysicBodyComponentProvider<2>(const PhysicBody<2>&);
extern template ComponentProvider<3> makePhysicBodyComponentProvider<3>(const PhysicBody<3>&);

constexpr auto makePhysicBody2DComponentProvider = makePhysicBodyComponentProvider<2>;
constexpr auto makePhysicBody3DComponentProvider = makePhysicBodyComponentProvider<3>;

}