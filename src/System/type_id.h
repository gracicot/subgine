#pragma once

namespace sbg {

using type_id_t = void(*)();

template <typename T>
void type_id() {}

}