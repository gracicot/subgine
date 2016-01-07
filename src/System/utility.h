#pragma once

#include <cmath>
#include <type_traits>

namespace sbg {
	#if defined(__GNUC__) && !defined(__clang__)
	constexpr double tau = 8.0 * std::atan(1.0);
	constexpr double pi = tau / 2.0;
	#elif !defined(__GNUC__) || defined(__clang__)
	constexpr double tau = M_PI;
	constexpr double pi = tau / 2.0;
	#endif
	
	constexpr unsigned int freedom(unsigned int n) {
		return n * (n - 1) / 2;
	}
	
	template<unsigned int n, typename T>
	constexpr inline typename std::enable_if<(n == 0), T>::type power(T num) {
		return 1;
	}
	
	template<unsigned int n, typename T>
	constexpr inline typename std::enable_if<(n > 0), T>::type power(T num) {
		return num * power<n - 1>(num);
	}
}
