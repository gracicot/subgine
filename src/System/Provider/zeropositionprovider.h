#pragma once

#include "positionprovider.h"

namespace sbg {

template<int n>
PositionProvider<n> makeZeroPositionProvider();

constexpr auto makeZeroPositionProvider2D = makeZeroPositionProvider<2>;
constexpr auto makeZeroPositionProvider3D = makeZeroPositionProvider<3>;

extern template PositionProvider<2> makeZeroPositionProvider<2>();
extern template PositionProvider<3> makeZeroPositionProvider<3>();

}
