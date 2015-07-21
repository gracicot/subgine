#pragma once

#include "../../system.hpp"

namespace sbg {

template<int i> class PhysicBody;

template<int n>
DisplayComponentProvider<n> makePhysicBodyDisplayComponentProvider(const PhysicBody<n>& physicBody, ValueProvider<Vector<n, double>> scale = Vector<n, double>{1});

constexpr auto makePhysicBody2DDisplayComponentProvider = makePhysicBodyDisplayComponentProvider<2>;
constexpr auto makePhysicBody3DDisplayComponentProvider = makePhysicBodyDisplayComponentProvider<3>;

extern template DisplayComponentProvider<2> makePhysicBodyDisplayComponentProvider(const PhysicBody<2>&, ValueProvider<Vector<2, double>>);
extern template DisplayComponentProvider<3> makePhysicBodyDisplayComponentProvider(const PhysicBody<3>&, ValueProvider<Vector<3, double>>);

}
