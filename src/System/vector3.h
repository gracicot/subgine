#pragma once

#include <iosfwd>
#include <cmath>
#include "vector.h"
#include "vector2.h"

namespace sbg {

template<typename T>
struct Vector<3, T> {
	static_assert(std::is_arithmetic<T>::value, "Vector must be aritmetic");
	using MathType = typename std::conditional<std::is_floating_point<T>::value, T, double>::type;
	
	constexpr Vector() : x{0}, y{0}, z{0} {}
	constexpr explicit Vector(T value) : x{value}, y{value}, z{value} {}
	constexpr Vector(T _x, T _y, T _z) : x{_x}, y{_y}, z{_z} {}
	
	template<typename O, typename std::enable_if<std::is_convertible<T, O>::value, int>::type = 0>
	constexpr inline operator Vector<3, O> () const {
		return Vector<3, O>{
			static_cast<O>(x),
			static_cast<O>(y),
			static_cast<O>(z)
		};
	}
	
	template<typename O, typename std::enable_if<is_strictly_explicitly_convertible<T, O>::value, int>::type = 0>
	constexpr explicit inline operator Vector<3, O> () const {
		return Vector<3, O>{
			static_cast<O>(x),
			static_cast<O>(y),
			static_cast<O>(z)
		};
	}
	
	Vector<2, MathType> angle() const {
		return Vector<2, double>(std::atan(y / x), std::acos(z / length()));
	}

	MathType length() const {
		return std::sqrt(power<2>(x) + power<2>(y) + power<2>(z));
	}

	void applyAngle(const Vector<2, MathType> angles) {
		if (!null()) {
			auto lenght = length();
			x = static_cast<T>(std::sin(angles.y) * std::cos(angles.x) * lenght);
			y = static_cast<T>(std::sin(angles.x) * std::sin(angles.y) * lenght);
			z = static_cast<T>(std::cos(angles.y) * lenght);
		}
	}

	Vector<3, T> angle(const Vector<2, MathType> angles) const {
		Vector<3, T> temp;

		if (!null()) {
			auto lenght = length();
			temp.x = static_cast<T>(std::sin(angles.y) * std::cos(angles.x) * lenght);
			temp.y = static_cast<T>(std::sin(angles.x) * std::sin(angles.y) * lenght);
			temp.z = static_cast<T>(std::cos(angles.y) * lenght);
		}
		
		return temp;
	}

	void applyLenght(MathType lenght) {
		if (!null()) {
			auto product = lenght / length();
			x *= static_cast<T>(product);
			y *= static_cast<T>(product);
			z *= static_cast<T>(product);
		} else {
			x = static_cast<T>(lenght);
		}
	}

	Vector<3, decltype(std::declval<T>() * std::declval<MathType>())> lenght(MathType lenght) {
		auto product = lenght / length();
		return {
			x * product,
			y * product,
			z * product
		};
	}

	Vector<3, T> project(const Vector<3, T>& other) const {
		return dot(other.unit()) * other;
	}

	bool null() const {
		return x == 0 && y == 0 && z == 0;
	}

	Vector<3, decltype((std::declval<T>() / std::declval<MathType>()))> unit() const {
		if (!null()) {
			auto lenght = length();

			return {x / lenght, y / lenght, z / lenght};
		} else {
			return {0, 0, 0};
		}
	}

	template<typename U>
	constexpr Vector<3, decltype((std::declval<T>() * std::declval<U>()))> cross(const Vector<3, U>& other) const {
		return {y * other.z - z * other.y, -1 * x * other.z + z * other.x, x * other.y - y * other.x};
	}

	template<typename U>
	constexpr auto dot(const Vector<3, U>& vec) const -> decltype((std::declval<T>() * std::declval<U>())) {
		return (x * vec.x) + (y * vec.y) + (z * vec.z);
	}

	Vector<3, T>& operator=(const Vector<3, T>& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	template<typename U>
	constexpr bool operator==(const Vector<3, U>& other) const {
		return x == other.x && y == other.y && z == other.z;
	}

	template<typename U>
	constexpr bool operator!=(const Vector<3, U>& other) const {
		return !(*this == other);
	}

	template<typename U>
	constexpr bool operator<(const Vector<3, U>& other) const {
		return ((x * x) + (y * y) + (z * z)) < ((other.x * other.x) + (other.y * other.y) + (other.z * other.z));
	}

	template<typename U>
	constexpr bool operator>(const Vector<3, U>& other) const {
		return ((x * x) + (y * y) + (z * z)) > ((other.x * other.x) + (other.y * other.y) + (other.z * other.z));
	}

	constexpr bool operator>(MathType length) const {
		return ((x * x) + (y * y) + (z * z)) > (length * length);
	}

	constexpr bool operator<(MathType length) const {
		return ((x * x) + (y * y) + (z * z)) < (length * length);
	}
	
	T x, y, z;
	
	constexpr static int size = 3;
	using type = T;
};

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr bool operator<(const Vector<3, T>& vec, U length)
{
	return power<2>(vec.x) + power<2>(vec.y) + power<2>(vec.z) < static_cast<typename Vector<3, T>::MathType>(length * length);
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr bool operator>(const Vector<3, T>& vec, U length)
{
	return power<2>(vec.x) + power<2>(vec.y) + power<2>(vec.z) > static_cast<typename Vector<3, T>::MathType>(length * length);
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr bool operator<(U length, const Vector<3, T>& vec)
{
	return static_cast<typename Vector<3, T>::MathType>(length * length) < power<2>(vec.x) + power<2>(vec.y) + power<2>(vec.z);
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr bool operator>(U length, const Vector<3, T>& vec)
{
	return static_cast<typename Vector<3, T>::MathType>(length * length) > power<2>(vec.x) + power<2>(vec.y) + power<2>(vec.z);
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr Vector<3, decltype(std::declval<T>() / std::declval<U>())> operator/(const Vector<3, T>& vec, U divider)
{
	return {vec.x / divider, vec.y / divider, vec.z / divider};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr Vector<3, decltype(std::declval<T>() / std::declval<U>())> operator/(U divider, const Vector<3, T>& vec)
{
	return {divider / vec.x, divider / vec.y, divider / vec.z};
}

template<typename T, typename U>
constexpr Vector<3, decltype(std::declval<T>() / std::declval<U>())> operator/(const Vector<3, T>& vec1, const Vector<3, U>& vec2)
{
	return {vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr Vector<3, decltype(std::declval<T>() * std::declval<U>())> operator*(const Vector<3, T>& vec, U multiplier)
{
	return {vec.x * multiplier, vec.y * multiplier, vec.z * multiplier};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
constexpr Vector<3, decltype(std::declval<T>() * std::declval<U>())> operator*(U multiplier, const Vector<3, T>& vec)
{
	return {vec.x * multiplier, vec.y * multiplier, vec.z * multiplier};
}

template<typename T, typename U>
constexpr Vector<3, decltype(std::declval<T>() * std::declval<U>())> operator*(const Vector<3, T>& vec1, const Vector<3, U>& vec2)
{
	return {vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<3, T>& operator*=(Vector<3, T>& vec, U multiplier)
{
	vec.x *= multiplier;
	vec.y *= multiplier;
	vec.z *= multiplier;
	return vec;
}

template<typename T, typename U>
Vector<3, T>& operator/=(Vector<3, T>& vec1, const Vector<3, U>& vec2)
{
	vec1.x /= vec2.x;
	vec1.y /= vec2.y;
	vec1.z /= vec2.z;
	return vec1;
}

template<typename T, typename U>
Vector<3, T>& operator*=(Vector<3, T>& vec1, const Vector<3, U>& vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	vec1.z *= vec2.z;
	return vec1;
}

template<typename T, typename U>
constexpr Vector<3, decltype(std::declval<T>() + std::declval<U>())> operator+(const Vector<3, T> vec1, const Vector<3, U>& vec2)
{
	return {vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z};
}

template<typename T, typename U>
Vector<3, T>& operator+=(Vector<3, T> &vec1, const Vector<3, U>& vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	return vec1;
}

template<typename T, typename U>
constexpr Vector<3, decltype(std::declval<T>() - std::declval<U>())> operator-(const Vector<3, T>& vec1, const Vector<3, U>& vec2)
{
	return {vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z};
}

template<typename T>
constexpr Vector<3, T> operator-(const Vector<3, T>& vec)
{
	return {-vec.x, -vec.y, -vec.z};
}

template<typename T, typename U>
Vector<3, T>& operator-=(Vector<3, T>& vec1, const Vector<3, U> vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	return vec1;
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<3, T>& operator/=(Vector<3, T> &vec, U divider)
{
	vec.x /= divider;
	vec.y /= divider;
	vec.z /= divider;
	return vec;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Vector<3, T>& vec)
{
	out << vec.x << ", " << vec.y << ", " << vec.z;
	return out;
}

using Vector3f = Vector<3, float>;
using Vector3d = Vector<3, double>;
using Vector3ld = Vector<3, long double>;
using Vector3i = Vector<3, int>;
using Vector3ui = Vector<3, unsigned int>;
using Vector3l = Vector<3, long>;
using Vector3ul = Vector<3, unsigned long>;
using Vector3s = Vector<3, short>;
using Vector3us = Vector<3, unsigned short>;
using Vector3c = Vector<3, char>;
using Vector3uc = Vector<3, unsigned char>;

extern template struct Vector<3, float>;
extern template struct Vector<3, double>;
extern template struct Vector<3, long double>;
extern template struct Vector<3, int>;
extern template struct Vector<3, unsigned int>;
extern template struct Vector<3, long>;
extern template struct Vector<3, unsigned long>;
extern template struct Vector<3, short>;
extern template struct Vector<3, unsigned short>;
extern template struct Vector<3, char>;
extern template struct Vector<3, unsigned char>;

}
