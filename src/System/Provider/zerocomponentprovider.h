#pragma once

#include "componentprovider.h"

namespace sbg {

template<int n>
ComponentProvider<n> makeZeroComponentProvider();

constexpr auto makeZeroComponentProvider2D = makeZeroComponentProvider<2>;
constexpr auto makeZeroComponentProvider3D = makeZeroComponentProvider<3>;

extern template ComponentProvider<2> makeZeroComponentProvider<2>();
extern template ComponentProvider<3> makeZeroComponentProvider<3>();


}
