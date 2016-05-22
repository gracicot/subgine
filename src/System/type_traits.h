#pragma once

#include <type_traits>

namespace sbg {

template<typename...>
struct voider {
	using type = void;
};

template<typename... Ts>
using void_t = typename voider<Ts...>::type;

template<typename From, typename To, typename = void>
struct is_explicitly_convertible : std::false_type {};

template<typename... Args>
void test(Args...);

template<typename From, typename To>
struct is_explicitly_convertible<From, To, void_t<decltype(test<To>(static_cast<To>(std::declval<From>())))>> : std::true_type {};

template<typename From, typename To>
struct is_strictly_explicitly_convertible : 
	std::integral_constant<bool, !std::is_convertible<From, To>::value && is_explicitly_convertible<From, To>::value>
	{};

}
