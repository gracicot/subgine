#pragma once

#include <memory>

#if __cplusplus < 201402L
#ifndef _MSC_VER
namespace std {
template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}
}
#endif
#endif
