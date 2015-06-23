#pragma once

#include <cmath>
#include <type_traits>

namespace sbg {
	constexpr double tau = 8.0 * std::atan(1.0);
	constexpr double pi = tau / 2.0;
	
	constexpr unsigned int freedom(unsigned int n) {
		return n * (n - 1) / 2;
	}
	
	template<unsigned int n, typename T>
	constexpr inline typename std::enable_if<(n == 0), typename std::remove_reference<T>::type>::type power(T&& num) {
		return 1;
	}
	
	template<unsigned int n, typename T>
	constexpr inline typename std::enable_if<(n > 0), typename std::remove_reference<T>::type>::type power(T&& num) {
		return num * power<n - 1>(num);
	}
}
