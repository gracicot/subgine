#pragma once

#include "../../system.hpp"

namespace sbg {

template<int i> struct PhysicBody;

template<int n>
DisplayComponentProvider<n> makePhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, Provider<Vector<n, double>> scale = Vector<n, double>{1});

constexpr auto makePhysicBody2DDisplayComponentProvider = makePhysicBodyDisplayComponentProvider<2>;
constexpr auto makePhysicBody3DDisplayComponentProvider = makePhysicBodyDisplayComponentProvider<3>;

extern template DisplayComponentProvider<2> makePhysicBodyDisplayComponentProvider(const PhysicBody<2>&, Provider<Vector<2, double>>);
extern template DisplayComponentProvider<3> makePhysicBodyDisplayComponentProvider(const PhysicBody<3>&, Provider<Vector<3, double>>);

}
