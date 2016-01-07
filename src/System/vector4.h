#pragma once

#include <cmath>
#include <iosfwd>
#include <utility>
#include "type_traits.h"
#include "vector.h"

namespace sbg
{

template<typename T>
struct Vector<4, T> {
	static_assert(std::is_arithmetic<T>::value, "Vector must be aritmetic");
private:
	using MathType = typename std::conditional<std::is_floating_point<T>::value, T, double>::type;
	
public:
	constexpr Vector() : x{0}, y{0}, z{0}, w{0} {}
	constexpr explicit Vector(T value) : x{value}, y{value}, z{value}, w{value} {}
	constexpr Vector(T _x, T _y, T _z, T _w) : x{_x}, y{_y}, z{_z}, w{_w} {}
	
	template<typename O, typename std::enable_if<std::is_convertible<T, O>::value, int>::type = 0>
	constexpr inline operator Vector<4, O> () const {
		return Vector<4, O>{
			static_cast<O>(x),
			static_cast<O>(y),
			static_cast<O>(z),
			static_cast<O>(w)
		};
	}
	
	template<typename O, typename std::enable_if<!is_strictly_explicitly_convertible<T, O>::value, int>::type = 0>
	constexpr explicit inline operator Vector<4, O> () const {
		return Vector<4, O>{
			static_cast<O>(x),
			static_cast<O>(y),
			static_cast<O>(z),
			static_cast<O>(w)
		};
	}
	
	MathType length() const {
		return std::sqrt((x*x) + (y*y) + (z*z) + (w*w));
	}

	void applyLenght(double lenght) {
		if (!null()) {
			auto product = lenght / length();
			x *= product;
			y *= product;
			z *= product;
			w *= product;
		} else {
			x = lenght;
		}
	}

	Vector<4, T> project(const Vector<4, T>& other) const {
		return dot(other.unit()) * other;
	}

	constexpr bool null() const {
		return x != 0 || y != 0 || z != 0 || w != 0;
	}

	Vector<4, decltype((std::declval<T>() / std::declval<MathType>()))> unit() const {
		if (!null()) {
			auto lenght = length();
			
			return {x / lenght, y / lenght,  z / lenght,  w / lenght};
		} else {
			return Vector< 4 , T >(0, 0, 0, 0);
		}
	}

	template<typename U>
	constexpr auto dot(const Vector<4, U>& vec) const -> decltype((std::declval<T>() * std::declval<U>())) {
		return (x * vec.x) + (y * vec.y) + (z * vec.z) + (w * vec.w);
	}

	Vector<4, T>& operator=(const Vector<4, T>& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	template<typename U>
	constexpr bool operator==(const Vector<4, U>& other) const {
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	template<typename U>
	constexpr bool operator!=(const Vector<4, U>& other) const {
		return !(*this == other);
	}

	template<typename U>
	constexpr bool operator<(const Vector<4, U>& other) const {
		return ((x * x) + (y * y) + (z * z) + (w * w)) < ((other.x * other.x) + (other.y * other.y) + (other.z * other.z) + (other.w * other.w));
	}

	template<typename U>
	constexpr bool operator>(const Vector<4, U>& other) const {
		return ((x * x) + (y * y) + (z * z) + (w * w)) > ((other.x * other.x) + (other.y * other.y) + (other.z * other.z) + (other.w * other.w));
	}

	constexpr bool operator>(MathType length) const {
		return ((x * x) + (y * y) + (z * z) + (w * w)) > (length * length);
	}

	constexpr bool operator<(MathType length) const {
		return ((x * x) + (y * y) + (z * z) + (w * w)) < (length * length);
	}
	
	T x, y, z, w;
	
	constexpr static int size = 4;
	using type = T;
};

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<4, decltype(std::declval<T>() / std::declval<U>())> operator/(const Vector<4, T>& vec, U divider)
{
	return {vec.x / divider, vec.y / divider, vec.z / divider, vec.w / divider};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<4, decltype(std::declval<T>() / std::declval<U>())> operator/(U divider, const Vector<4, T>& vec)
{
	return {vec.x / divider, vec.y / divider, vec.z / divider, vec.w / divider};
}

template<typename T, typename U>
Vector<4, decltype(std::declval<T>() / std::declval<U>())> operator/(const Vector<4, T>& vec1, const Vector<4, U>& vec2)
{
	return {vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z, vec1.w / vec2.w};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<4, decltype(std::declval<T>() * std::declval<U>())> operator*(const Vector<4, T>& vec, U multiplier)
{
	return {vec.x * multiplier, vec.y * multiplier, vec.z * multiplier, vec.w * multiplier};
}

template<typename T, typename U>
Vector<4, decltype(std::declval<T>() * std::declval<U>())> operator*(U multiplier, const Vector<4, T>& vec)
{
	return {vec.x * multiplier, vec.y * multiplier, vec.z * multiplier, vec.w * multiplier};
}

template<typename T, typename U>
Vector<4, decltype(std::declval<T>() * std::declval<U>())> operator*(const Vector<4, T>& vec, U multiplier)
{
	return {vec.x * multiplier, vec.y * multiplier, vec.z * multiplier, vec.w * multiplier};
}

template<typename T, typename U, typename std::enable_if<std::is_arithmetic<U>::value, int>::type = 0>
Vector<4, T>& operator*=(Vector<4, T>& vec, U multiplier)
{
	vec.x *= multiplier;
	vec.y *= multiplier;
	vec.z *= multiplier;
	vec.w *= multiplier;
	return vec;
}

template<typename T, typename U>
Vector<4, T>& operator*=(Vector<4, T>& vec1, const Vector<4, U>& vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	vec1.z *= vec2.z;
	vec1.w *= vec2.w;
	return vec1;
}

template<typename T, typename U>
Vector<4, decltype(std::declval<T>() + std::declval<U>())> operator+(const Vector<4, T>& vec1, const Vector<4, U>& vec2)
{
	return {vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z, vec1.w + vec2.w};
}

template<typename T, typename U>
Vector<4, T>& operator+=(Vector<4, T>& vec1, const Vector<4, U>& vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	vec1.w += vec2.w;
	return vec1;
}

template<typename T, typename U>
Vector<4, decltype(std::declval<T>() - std::declval<U>())> operator-(const Vector<4, T>& vec1, const Vector<4, U>& vec2)
{
	return {vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z, vec1.w - vec2.w};
}

template<typename T, typename U>
Vector<4, T>& operator-=(Vector<4, T>& vec1, const Vector<4, U>& vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	vec1.w -= vec2.w;
	return vec1;
}

template<typename T, typename U>
Vector<4, T>& operator/=(Vector<4, T>& vec, U divider)
{
	vec.x /= divider;
	vec.y /= divider;
	vec.z /= divider;
	vec.w /= divider;
	return vec;
}

template<typename T, typename U>
Vector<4, T>& operator/=(Vector<4, T>& vec1, const Vector<4, U>& vec2)
{
	vec1.x /= vec2.x;
	vec1.y /= vec2.y;
	vec1.z /= vec2.z;
	vec1.w /= vec2.w;
	return vec1;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, Vector<4, T> vec)
{
	out << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
	return out;
}

using Vector4f = Vector<4, float>;
using Vector4d = Vector<4, double>;
using Vector4ld = Vector<4, long double>;
using Vector4i = Vector<4, int>;
using Vector4ui = Vector<4, unsigned int>;
using Vector4l = Vector<4, long>;
using Vector4ul = Vector<4, unsigned long>;
using Vector4s = Vector<4, short>;
using Vector4us = Vector<4, unsigned short>;
using Vector4c = Vector<4, char>;
using Vector4uc = Vector<4, unsigned char>;

extern template struct Vector<4, float>;
extern template struct Vector<4, double>;
extern template struct Vector<4, long double>;
extern template struct Vector<4, int>;
extern template struct Vector<4, unsigned int>;
extern template struct Vector<4, long>;
extern template struct Vector<4, unsigned long>;
extern template struct Vector<4, short>;
extern template struct Vector<4, unsigned short>;
extern template struct Vector<4, char>;
extern template struct Vector<4, unsigned char>;

}
