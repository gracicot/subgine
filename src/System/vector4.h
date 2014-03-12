#pragma once

#include <ostream>
#include <cmath>
#include "vector.h"

namespace subgine
{
	
	template<class T>
	class Vector<4, T>
	{
	public:
		Vector() : x(0), y(0), z(0), w(0)
		{
			
		}
		
		Vector(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w)
		{
			
		}
		
		Vector(const Vector<4, T>& other) : x(other.x), y(other.y), z(other.z), w(other.w)
		{
			
		}
		
		template<class O>
		operator Vector< 4 , O >(){
			return Vector< 4 , O >((O)x, (O)y, (O)z, (O)w);
		}
		
		inline double getLength() const
		{
			return sqrt((x*x) + (y*y) + (z*z) + (w*w));
		}
		
		void setLenght(double lenght)
		{
			if (notZero()) {
				double product = lenght / getLength();
				x *= product;
				y *= product;
				z *= product;
				w *= product;
			} else {
				x = lenght;
			}
		}
		
		inline Vector<4, T> project(Vector<4, T> other) const
		{
			return (this->dot(other.unit())) * other;
		}
		
		bool notZero() const
		{
			return x != 0 || y != 0 || z != 0 || w != 0;
		}
		
		Vector<4, T> unit() const
		{
			if (notZero()) {
				double lenght = getLength();
				
				return Vector<4, T>(x / lenght, y / lenght,  z / lenght,  w / lenght);
			} else {
				return Vector< 4 , T >(0, 0, 0, 0);
			}
		}
		
		inline double dot(const Vector<4, T>& vec) const
		{
			return (x * vec.x) + (y * vec.y) + (z * vec.z) + (w * vec.w);
		}
		
		Vector<4, T>& operator= (const Vector<4, T>& other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			w = other.w;
			return *this;
		}
		
		T x, y, z, w;
	};
	
	template<class T>
	inline Vector<4, T> operator/ (const Vector<4, T>& vec, const double& divider)
	{
		return Vector<4, T>(vec.x / divider, vec.y / divider, vec.z / divider, vec.w / divider);
	}
	
	template<class T>
	inline Vector<4, T> operator/ (const Vector<4, T>& vec1, const Vector<4, T>& vec2)
	{
		return Vector<4, T>(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z, vec1.w / vec2.w);
	}
	
	template<class T>
	inline Vector<4, T> operator* (const Vector<4, T>& vec, const double& multiplier)
	{
		return Vector<4, T>(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier, vec.w * multiplier);
	}
	
	template<class T>
	inline Vector<4, T> operator* (const double& multiplier, const Vector<4, T>& vec)
	{
		return Vector<4, T>(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier, vec.w * multiplier);
	}
	
	template<class T>
	Vector<4, T>& operator*= (Vector<4, T>& vec, const double& multiplier)
	{
		vec.x *= multiplier;
		vec.y *= multiplier;
		vec.z *= multiplier;
		vec.w *= multiplier;
		return vec;
	}
	
	template<class T>
	inline Vector<4, T> operator+ (const Vector<4, T>& vec1, const Vector<4, T>& vec2)
	{
		return Vector<4, T>(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z, vec1.w + vec2.w);
	}
	
	template<class T>
	Vector<4, T>& operator+= (Vector<4, T>& vec1, const Vector<4, T>& vec2)
	{
		vec1.x += vec2.x;
		vec1.y += vec2.y;
		vec1.z += vec2.z;
		vec1.w += vec2.w;
		return vec1;
	}
	
	template<class T>
	inline Vector<4, T> operator- (const Vector<4, T>& vec1, const Vector<4, T>& vec2)
	{
		return Vector<4, T>(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z, vec1.w - vec2.w);
	}
	
	template<class T>
	Vector<4, T>& operator-= (Vector<4, T>& vec1, const Vector<4, T>& vec2)
	{
		vec1.x -= vec2.x;
		vec1.y -= vec2.y;
		vec1.z -= vec2.z;
		vec1.w -= vec2.w;
		return vec1;
	}
	
	template<class T>
	inline Vector<4, T> operator* (const Vector<4, T>& vec1, const Vector<4, T>& vec2)
	{
		return Vector<4, T>(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z, vec1.w * vec2.w);
	}
	
	template<class T>
	Vector<4, T>& operator/= (Vector<4, T>& vec, const double& divider)
	{
		vec.x /= divider;
		vec.y /= divider;
		vec.z /= divider;
		vec.w /= divider;
		return vec;
	}

	template<class T>
	inline std::ostream& operator<< (std::ostream& out, Vector<4, T> vec)
	{
		out << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
		return out;
	}
	
	
	typedef Vector<4> Vector4;
	typedef Vector<4, float> Vector4f;
	typedef Vector<4, double> Vector4d;
	typedef Vector<4, int> Vector4i;
	typedef Vector<4, unsigned int> Vector4ui;
}
