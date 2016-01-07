#pragma once

#include "vector.h"

#include <cmath>
#include <iosfwd>
#include <utility>
#include "type_traits.h"

namespace sbg {

template<typename T>
struct Vector<1, T> {
	static_assert(std::is_arithmetic<T>::value, "Vector must be aritmetic");
private:
	using MathType = typename std::conditional<std::is_floating_point<T>::value, T, double>::type;
	
public:
	constexpr inline Vector(T _x = 0) : x{_x} {}
	constexpr inline Vector(const Vector<1, T>& other) : x{other.x} {}
	
	template<typename O, typename std::enable_if<std::is_convertible<T, O>::value, int>::type = 0>
	constexpr inline operator Vector<1, O> () const {
		return {static_cast<O>(x)};
	}
	
	template<typename O, typename std::enable_if<!is_strictly_explicitly_convertible<T, O>::value, int>::type = 0>
	constexpr explicit inline operator Vector<1, O> () const {
		return {static_cast<O>(x)};
	}

	template<typename U = T, typename std::enable_if<std::is_signed<U>::value, int>::type = 0>
	constexpr inline MathType length() const {
		static_assert(std::is_same<U, T>::value, "Template parameter 'U' is only for sfinae purposes");
		return std::abs(x);
	}

	template<typename U = T, typename std::enable_if<!std::is_signed<U>::value, int>::type = 0>
	constexpr inline MathType length() const {
		static_assert(std::is_same<U, T>::value, "Template parameter 'U' is only for sfinae purposes");
		return x;
	}

	template<typename U = T, typename std::enable_if<std::is_signed<U>::value, int>::type = 0>
	inline void applyLength(T length) {
		static_assert(std::is_same<U, T>::value, "Template parameter 'U' is only for sfinae purposes");
		if (x >= 0) {
			x = length;
		} else {
			x = -1 * length;
		}
	}

	template<typename U = T, typename std::enable_if<!std::is_signed<U>::value, int>::type = 0>
	inline void applyLength(T length) {
		static_assert(std::is_same<U, T>::value, "Template parameter 'U' is only for sfinae purposes");
		x = length;
	}

	constexpr inline MathType length(MathType toLength) const {
		return toLength * x / length();
	}

	constexpr inline bool null() const {
		return x == 0;
	}

	template<typename U = T, typename std::enable_if<std::is_signed<U>::value, int>::type = 0>
	constexpr inline Vector<1, T> unit() const {
		static_assert(std::is_same<U, T>::value, "Template parameter 'U' is only for sfinae purposes");
		return {null() ? 0 : x / length()};
	}

	template<typename U = T, typename std::enable_if<!std::is_signed<U>::value, int>::type = 0>
	constexpr inline Vector<1, T> unit() const {
		static_assert(std::is_same<U, T>::value, "Template parameter 'U' is only for sfinae purposes");
		return {null() ? 0 : 1};
	}

	template<typename U = T, typename std::enable_if<std::is_signed<U>::value, int>::type = 0>
	constexpr inline Vector<2, decltype(std::declval<T>() * std::declval<T>())> cross(const Vector<2, T>& other) const {
		static_assert(std::is_same<U, T>::value, "Template parameter 'U' is only for sfinae purposes");
		return {-x * other.y, x * other.x};
	}

	constexpr inline Vector<1, decltype(std::declval<T>() * std::declval<T>())> dot(const Vector<1, T>& other) const {
		return {x * other.x};
	}

	Vector<1, T>& operator=(const Vector<1, T>& other) {
		x = other.x;
		return *this;
	}

	template<typename U>
	Vector<1, T>& operator=(U&& value) {
		x = std::forward<U>(value);
		return *this;
	}

	template<typename U>
	constexpr inline bool operator==(const Vector<1, U>& other) const {
		return x == other.x;
	}

	template<typename U>
	constexpr inline bool operator!=(const Vector<1, U>& other) const {
		return !(*this == other);
	}

	template<typename U>
	constexpr inline bool operator<(const Vector<1, U>& other) const {
		return x < other.x;
	}

	template<typename U>
	constexpr inline bool operator>(const Vector<1, U>& other) const {
		return x > other.x;
	}

	template<typename U>
	constexpr inline bool operator>(U&& length) const {
		return x > std::forward<U>(length);
	}

	template<typename U>
	constexpr inline bool operator<(U&& length) const {
		return x < std::forward<U>(length);
	}

	constexpr inline operator T() const {
		return x;
	}

	T x;
	
	constexpr static int size = 1;
	using type = T;
};

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr Vector<1, decltype(std::declval<T>() / std::declval<U>())> operator/(const Vector<1, T>& vec, U divider)
{
	return {vec.x / divider};
}

template<typename T, typename U>
constexpr Vector<1, decltype(std::declval<T>() / std::declval<U>())> operator/(const Vector<1, T>& vec1, const Vector<1, U>& vec2)
{
	return {vec1.x / vec2.x};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr Vector<1, decltype(std::declval<T>() * std::declval<U>())> operator*(const Vector<1, T>& vec, U multiplier)
{
	return {vec.x * multiplier};
}

template<typename T, typename U>
constexpr Vector<1, decltype(std::declval<T>() * std::declval<U>())> operator*(U multiplier, const Vector<1, T>& vec)
{
	return {vec.x * multiplier};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<1, T>& operator*=(Vector<1, T>& vec, U multiplier)
{
	vec.x *= multiplier;
	return vec;
}

template<typename T, typename U>
constexpr Vector<1, decltype(std::declval<T>() + std::declval<U>())> operator+(const Vector<1, T>& vec1, const Vector<1, U>& vec2)
{
	return {vec1.x + vec2.x};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr Vector<1, decltype(std::declval<T>() + std::declval<U>())> operator+(const Vector<1, T>& vec1, U scalar)
{
	return {vec1.x + scalar};
}

template<typename T, typename U>
Vector<1, T>& operator+=(Vector<1, T>& vec1, const Vector<1, U>& vec2)
{
	vec1.x += vec2.x;
	return vec1;
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<1, T>& operator+=(Vector<1, T>& vec1, U scalar)
{
	vec1.x += scalar;
	return vec1;
}

template<typename T, typename U>
constexpr Vector<1, decltype(std::declval<T>() - std::declval<U>())> operator-(const Vector<1, T>& vec1, const Vector<1, U>& vec2)
{
	return {vec1.x - vec2.x};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr Vector<1, decltype(std::declval<T>() - std::declval<U>())> operator-(const Vector<1, T>& vec1, U scalar)
{
	return {vec1.x - scalar};
}

template<typename T, typename U>
Vector<1, T>& operator-=(Vector<1, T>& vec1, const Vector<1, U>& vec2)
{
	vec1.x -= vec2.x;
	return vec1;
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<1, T>& operator-=(Vector<1, T>& vec1, U scalar)
{
	vec1.x -= scalar;
	return vec1;
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<1, T>& operator/=(Vector<1, T>& vec, U divider)
{
	vec.x /= divider;
	return vec;
}

template<typename T, typename U>
Vector<1, T>& operator/=(Vector<1, T>& vec1, const Vector<1, U>& vec2)
{
	vec1.x /= vec2.x;
	return vec1;
}

template<typename T, typename U>
Vector<1, T>& operator*=(Vector<1, T>& vec1, const Vector<1, U>& vec2)
{
	vec1.x *= vec2.x;
	return vec1;
}

template<typename T>
constexpr Vector<1, T> operator-(const Vector<1, T>& vec)
{
	return {-vec.x};
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Vector<1, T>& vec)
{
	out << vec.x;
	return out;
}

extern template struct Vector<1, float>;
extern template struct Vector<1, double>;
extern template struct Vector<1, long double>;
extern template struct Vector<1, int>;
extern template struct Vector<1, unsigned int>;
extern template struct Vector<1, long>;
extern template struct Vector<1, unsigned long>;
extern template struct Vector<1, short>;
extern template struct Vector<1, unsigned short>;
extern template struct Vector<1, char>;
extern template struct Vector<1, unsigned char>;

using Vector1f = Vector<1, float>;
using Vector1d = Vector<1, double>;
using Vector1ld = Vector<1, long double>;
using Vector1i = Vector<1, int>;
using Vector1ui = Vector<1, unsigned int>;
using Vector1l = Vector<1, long>;
using Vector1ul = Vector<1, unsigned long>;
using Vector1s = Vector<1, short>;
using Vector1us = Vector<1, unsigned short>;
using Vector1c = Vector<1, char>;
using Vector1uc = Vector<1, unsigned char>;

}
