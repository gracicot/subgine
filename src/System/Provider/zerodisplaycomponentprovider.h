#pragma once

#include "displaycomponentprovider.h"

namespace sbg {

template<int n>
DisplayComponentProvider<n> makeZeroDisplayComponentProvier();

constexpr auto makeZeroDisplayComponentProvier2D = makeZeroDisplayComponentProvier<2>;
constexpr auto makeZeroDisplayComponentProvier3D = makeZeroDisplayComponentProvier<3>;

extern template DisplayComponentProvider<2> makeZeroDisplayComponentProvier<2>();
extern template DisplayComponentProvider<3> makeZeroDisplayComponentProvier<3>();

}
