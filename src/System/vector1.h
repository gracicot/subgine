#pragma once

#include <ostream>
#include <cmath>

#include "vector.h"
#include "vector2.h"

namespace subgine {

template<class T>
class Vector<1, T>
{
public:
	Vector() : x(0)
	{}

	Vector(T _x) : x(_x)
	{}

	Vector(const Vector<1, T>& other) : x(other.x)
	{}

	template<class O>
	operator Vector< 1 , O > () const
	{
		return Vector< 1 , O >(static_cast<O>(x));
	}

	inline double getLength() const
	{
		return std::abs(x);
	}

	void setLength(double length)
	{
		if (x >= 0) {
			x = length;
		} else {
			x = -1 * length;
		}
	}

	inline bool notZero() const 
	{
		return x != 0;
	}

	Vector<1, T> unit() const
	{
		if (notZero()) {
			return Vector< 1 , T >(x / std::abs(x));
		} else {
			return Vector< 1 , T >(0);
		}
	}
	
	Vector< 2 , T > cross(const Vector< 2 , T >& other)
	{
		return Vector< 2 , T >( -x * other.y, x * other.x );
	}

	Vector<1, T>& operator= (const Vector<1, T>& other)
	{
		x = other.x;
		return *this;
	}

	Vector<1, T>& operator= (T value)
	{
		x = value;
		return *this;
	}

	inline bool operator< (const Vector<1, T>& other) const
	{
		return x < other.x;
	}

	inline bool operator> (const Vector<1, T>& other) const
	{
		return x > other.x;
	}

	inline bool operator> (double length) const
	{
		return x > length;
	}

	inline bool operator< (double length) const
	{
		return x < length;
	}

	inline operator T () const
	{
		return x;
	}

	T x;
};

template<class T>
Vector<1, T> operator/ (const Vector<1, T>& vec, const double& divider)
{
	return Vector<1, T>(vec.x / divider);
}

template<class T>
Vector<1, T> operator/ (const Vector<1, T>& vec1, const Vector<1, T>& vec2)
{
	return Vector<1, T>(vec1.x / vec2.x);
}

template<class T>
Vector<1, T> operator* (const Vector<1, T>& vec, const double& multiplier)
{
	return Vector<1, T>(vec.x * multiplier);
}

template<class T>
Vector<1, T> operator* (const double& multiplier, const Vector<1, T>& vec)
{
	return Vector<1, T>(vec.x * multiplier);
}

template<class T>
Vector<1, T>& operator*= (Vector<1, T>& vec, const double& multiplier)
{
	vec.x *= multiplier;
	return vec;
}

template<class T>
Vector<1, T> operator+ (const Vector<1, T>& vec1, const Vector<1, T>& vec2)
{
	return Vector<1, T>(vec1.x + vec2.x);
}

template<class T>
Vector<1, T> operator+ (const Vector<1, T>& vec1, T scalar)
{
	return Vector<1, T>(vec1.x + scalar);
}

template<class T>
Vector<1, T>& operator+= (Vector<1, T>& vec1, const Vector<1, T>& vec2)
{
	vec1.x += vec2.x;
	return vec1;
}

template<class T>
Vector<1, T>& operator+= (Vector<1, T>& vec1, T scalar)
{
	vec1.x += scalar;
	return vec1;
}

template<class T>
Vector<1, T> operator- (const Vector<1, T>& vec1, const Vector<1, T>& vec2)
{
	return Vector<1, T>(vec1.x - vec2.x);
}

template<class T>
Vector<1, T> operator- (const Vector<1, T>& vec1, T scalar)
{
	return Vector<1, T>(vec1.x - scalar);
}

template<class T>
Vector<1, T>& operator-= (Vector<1, T>& vec1, const Vector<1, T>& vec2)
{
	vec1.x -= vec2.x;
	return vec1;
}

template<class T>
Vector<1, T>& operator-= (Vector<1, T>& vec1, T scalar)
{
	vec1.x -= scalar;
	return vec1;
}

template<class T>
Vector<1, T>& operator/= (Vector<1, T>& vec, const double& divider)
{
	vec.x /= divider;
	return vec;
}

template<class T>
inline std::ostream& operator<< (std::ostream& out, Vector<1, T> vec)
{
	out << vec.x;
	return out;
}

typedef Vector<1, float> Vector1f;
typedef Vector<1, double> Vector1d;
typedef Vector<1, int> Vector1i;
typedef Vector<1, unsigned int> Vector1ui;
}
