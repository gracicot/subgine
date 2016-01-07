#pragma once

#include <iosfwd>
#include <cmath>
#include <utility>

#include "vector.h"
#include "type_traits.h"

namespace sbg {
	
template<typename T>
struct Vector<2, T> {
	static_assert(std::is_arithmetic<T>::value, "Vector must be aritmetic");
private:
	using MathType = typename std::conditional<std::is_floating_point<T>::value, T, double>::type;
	
public:
	constexpr Vector() : x{0}, y{0} {}
	constexpr explicit Vector(T value) : x{value}, y{value} {}
	constexpr Vector(T _x, T _y) : x{_x}, y{_y} {}
	
	template<typename O, typename std::enable_if<std::is_convertible<T, O>::value, int>::type = 0>
	constexpr inline operator Vector<2, O> () const {
		return Vector<2, O>{
			static_cast<O>(x),
			static_cast<O>(y)
		};
	}
	
	template<typename O, typename std::enable_if<!is_strictly_explicitly_convertible<T, O>::value, int>::type = 0>
	constexpr explicit inline operator Vector<2, O> () const {
		return Vector<2, O>{
			static_cast<O>(x),
			static_cast<O>(y)
		};
	}

	MathType angle() const {
		auto angle = std::atan2(y, x);

		if (angle < 0) {
			angle += tau;
		}

		return angle;
	}

	MathType length() const {
		return std::sqrt(power<2>(x) + power<2>(y));
	}

	void applyAngle(MathType angle) {
		if (!null()) {
			auto lenght = length();
			x = std::cos(angle) * lenght;
			y = std::sin(angle) * lenght;
		}
	}

	void applyLenght(MathType lenght) {
		if (!null()) {
			auto product = lenght / length();
			x *= product;
			y *= product;
		} else {
			x = lenght;
		}
	}
	
	template<typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
	inline Vector<2, decltype(std::declval<T>() * std::declval<U>())> lenght(U lenght) {
		auto product = std::forward<U>(lenght) / length();
		return {x * product, y * product};
	}

	inline Vector<2, T> project(const Vector<2, T>& other) const {
		return dot(other.unit()) * other;
	}

	constexpr bool null() const {
		return x == 0 && y == 0;
	}

	Vector<2, decltype(std::declval<T>() / std::declval<MathType>())> unit() const {
		if (!null()) {
			auto lenght = length();
			return {x / lenght, y / lenght};
		} else {
			return {0, 0};
		}
	}

	Vector<2, T> angle(MathType angle) const {
		Vector<2, T> temp;

		if (!null()) {
			auto lenght = length();
			temp.x = std::cos(angle) * lenght;
			temp.y = std::sin(angle) * lenght;
		}
		
		return temp;
	}

	template<typename U>
	constexpr inline auto dot(const Vector<2, U>& vec) const -> decltype((std::declval<T>() * std::declval<U>())) {
		return (x * vec.x) + (y * vec.y);
	}

	template<typename U>
	constexpr inline Vector<1, decltype((std::declval<T>() * std::declval<U>()))> cross(const Vector<2, U>& other) const {
		return {(x * other.y) - (y * other.x)};
	}

	template<typename U>
	constexpr inline Vector<2, decltype((std::declval<U>() * std::declval<T>()))> cross(U multiplier) const {
		return {multiplier * y, -multiplier * x};
	}

	template<typename U>
	constexpr inline Vector<2, decltype((std::declval<U>() * std::declval<T>()))> cross(const Vector<1, U>& multiplier) const {
		return {multiplier * y, -multiplier * x};
	}

	Vector<2, T>& operator=(const Vector<2, T>& other) {
		x = other.x;
		y = other.y;
		return *this;
	}

	template<typename U>
	constexpr inline bool operator==(const Vector<2, U>& other) const {
		return x == other.x && y == other.y;
	}

	template<typename U>
	constexpr inline bool operator!=(const Vector<2, U>& other) const {
		return !(*this == other);
	}

	template<typename U>
	constexpr inline bool operator<(const Vector<2, U>& other) const {
		return (power<2>(x) + power<2>(y)) < ((other.x * other.x) + (other.y * other.y));
	}

	template<typename U>
	constexpr inline bool operator>(const Vector<2, U>& other) const {
		return (power<2>(x) + power<2>(y)) > ((other.x * other.x) + (other.y * other.y));
	}

	constexpr inline bool operator>(MathType length) const {
		return (power<2>(x) + power<2>(y)) > (length * length);
	}

	constexpr inline bool operator<(MathType length) const {
		return (power<2>(x) + power<2>(y)) < (length * length);
	}
	
	T x, y;
	
	constexpr static int size = 2;
	using type = T;
};

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr inline Vector<2, decltype(std::declval<T>() / std::declval<U>())> operator/(const Vector<2, T>& vec, U divider)
{
	return {vec.x / divider, vec.y / divider};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr inline Vector<2, decltype(std::declval<T>() / std::declval<U>())> operator/(U divider, const Vector<2, T>& vec)
{
	return {vec.x / divider, vec.y / divider};
}

template<typename T, typename U>
constexpr Vector<2, decltype(std::declval<T>() / std::declval<U>())> operator/(const Vector<2, T>& vec1, const Vector<2, U>& vec2)
{
	return {vec1.x / vec2.x, vec1.y / vec2.y};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr inline Vector<2, decltype(std::declval<T>() * std::declval<U>())> operator*(const Vector<2, T>& vec, U multiplier)
{
	return {vec.x * multiplier, vec.y * multiplier};
}

template<typename T, typename U>
constexpr Vector<2, decltype(std::declval<T>() * std::declval<U>())> operator*(const Vector<2, T>& vec1, const Vector<2, U>& vec2)
{
	return {vec1.x * vec2.x, vec1.y * vec2.y};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr inline Vector<2, decltype(std::declval<T>() * std::declval<U>())> operator*(U multiplier, const Vector<2, T>& vec)
{
	return {vec.x * multiplier, vec.y * multiplier};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<2, T>& operator*=(Vector<2, T>& vec, U multiplier)
{
	vec.x *= multiplier;
	vec.y *= multiplier;
	return vec;
}

template<typename T, typename U>
constexpr inline Vector<2, decltype(std::declval<T>() + std::declval<U>())> operator+(const Vector<2, T>& vec1, const Vector<2, U>& vec2)
{
	return {vec1.x + vec2.x, vec1.y + vec2.y};
}

template<typename T, typename U>
Vector<2, T>& operator+=(Vector<2, T>& vec1, const Vector<2, U>& vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	return vec1;
}

template<typename T, typename U>
constexpr inline Vector<2, decltype(std::declval<T>() - std::declval<U>())> operator-(const Vector<2, T>& vec1, const Vector<2, U>& vec2)
{
	return {vec1.x - vec2.x, vec1.y - vec2.y};
}

template<typename T, typename U>
Vector<2, T>& operator-=(Vector<2, T>& vec1, const Vector<2, U>& vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	return vec1;
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<2, T>& operator/= (Vector<2, T>& vec, U divider)
{
	vec.x /= divider;
	vec.y /= divider;
	return vec;
}

template<typename T, typename U>
Vector<2, T>& operator/=(Vector<2, T>& vec1, const Vector<2, U>& vec2)
{
	vec1.x /= vec2.x;
	vec1.y /= vec2.y;
	return vec1;
}

template<typename T, typename U>
Vector<2, T>& operator*=(Vector<2, T>& vec1, const Vector<2, U>& vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	return vec1;
}

template<typename T>
constexpr Vector<2, T> operator-(const Vector<2, T>& vec)
{
	return {-vec.x, -vec.y};
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const Vector<2, T>& vec) {
	out << vec.x << ", " << vec.y;
	return out;
}

extern template struct Vector<2, float>;
extern template struct Vector<2, double>;
extern template struct Vector<2, long double>;
extern template struct Vector<2, int>;
extern template struct Vector<2, unsigned int>;
extern template struct Vector<2, long>;
extern template struct Vector<2, unsigned long>;
extern template struct Vector<2, short>;
extern template struct Vector<2, unsigned short>;
extern template struct Vector<2, char>;
extern template struct Vector<2, unsigned char>;

using Vector2f = Vector<2, float>;
using Vector2d = Vector<2, double>;
using Vector2ld = Vector<2, long double>;
using Vector2i = Vector<2, int>;
using Vector2ui = Vector<2, unsigned int>;
using Vector2l = Vector<2, long>;
using Vector2ul = Vector<2, unsigned long>;
using Vector2s = Vector<2, short>;
using Vector2us = Vector<2, unsigned short>;
using Vector2c = Vector<2, char>;
using Vector2uc = Vector<2, unsigned char>;

}
