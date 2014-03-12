#pragma once

#include <ostream>
#include <cmath>
#include "vector.h"
#include "vector2.h"

namespace subgine
{
	template<class T>
	class Vector<3, T>
	{
	public:
		Vector() : x(0), y(0), z(0)
		{
			
		}
		
		Vector(T _x, T _y, T _z) : x(_x), y(_y), z(_z)
		{
			
		}
		
		Vector(const Vector<3, T>& other) : x(other.x), y(other.y), z(other.z)
		{
			
		}
		
		template<class O>
		operator Vector< 3 , O >(){
			return Vector< 3 , O >((O)x, (O)y, (O)z);
		}
		
		inline Vector<2, double> getAngles() const
		{
			return Vector<2, double>(atan(y / x), acos(z / getLength()));
		}
		
		inline double getLength() const
		{
			return sqrt((x*x) + (y*y) + (z*z));
		}
		
		void setAngles(const Vector<2, double> angles)
		{
			if (notZero()) {
				double lenght = getLength();
				x = sin(angles.y) * cos(angles.x) * lenght;
				y = sin(angles.x) * sin(angles.y) * lenght;
				z = cos(angles.y) * lenght;
			}
		}
		
		void setLenght(double lenght)
		{
			if (notZero()) {
				double product = lenght / getLength();
				x *= product;
				y *= product;
				z *= product;
			} else {
				x = lenght;
			}
		}
		
		inline Vector<3, T> project(Vector<3, T> other) const
		{
			return (this->dot(other.unit())) * other;
		}
		
		bool notZero() const
		{
			return x != 0 || y != 0 || z != 0;
		}
		
		Vector<3, T> unit() const
		{
			if (notZero()) {
				double lenght = getLength();
				
				return Vector<3, T>(x / lenght, y / lenght, z / lenght);
			} else {
				return Vector< 3 , T >(0, 0, 0);
			}
		}
		
		inline double dot(const Vector<3, T>& vec) const
		{
			return (x * vec.x) + (y * vec.y) + (z * vec.z);
		}
		
		//Operators
		
		Vector<3, T>& operator= (const Vector<3, T>& other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			return *this;
		}
		
		T x, y, z;
	};
	
	template<class T>
	inline Vector<3, T> operator/ (const Vector<3, T>& vec, const double& divider)
	{
		return Vector<3, T>(vec.x / divider, vec.y / divider, vec.z / divider);
	}
	
	template<class T>
	inline Vector<3, T> operator* (const Vector<3, T>& vec, const double& multiplier)
	{
		return Vector<3, T>(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier);
	}
	
	template<class T>
	inline Vector<3, T> operator* (const double& multiplier, const Vector<3, T>& vec)
	{
		return Vector<3, T>(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier);
	}
	
	template<class T>
	Vector<3, T>& operator*= (Vector<3, T>& vec, const double& multiplier)
	{
		vec.x *= multiplier;
		vec.y *= multiplier;
		vec.z *= multiplier;
		return vec;
	}
	
	template<class T>
	inline Vector<3, T> operator+ (const Vector<3, T>& vec1, const Vector<3, T>& vec2)
	{
		return Vector<3, T>(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
	}
	
	template<class T>
	Vector<3, T>& operator+= (Vector<3, T>& vec1, const Vector<3, T>& vec2)
	{
		vec1.x += vec2.x;
		vec1.y += vec2.y;
		vec1.z += vec2.z;
		return vec1;
	}
	
	template<class T>
	inline Vector<3, T> operator- (const Vector<3, T>& vec1, const Vector<3, T>& vec2)
	{
		return Vector<3, T>(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
	}
	
	template<class T>
	Vector<3, T>& operator-= (Vector<3, T>& vec1, const Vector<3, T>& vec2)
	{
		vec1.x -= vec2.x;
		vec1.y -= vec2.y;
		vec1.z -= vec2.z;
		return vec1;
	}
	
	template<class T>
	Vector<3, T>& operator/= (Vector<3, T>& vec, const double& divider)
	{
		vec.x /= divider;
		vec.y /= divider;
		vec.z /= divider;
		return vec;
	}
	
	template<class T>
	inline Vector<3, T> operator* (const Vector<3, T>& vec1, const Vector<3, T>& vec2)
	{
		return Vector<3, T>(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z);
	}
	
	template<class T>
	inline Vector<3, T> operator- (const Vector<3, T>& vec)
	{
		return Vector<3, T>(-vec.x, -vec.y, -vec.z);
	}
	
	template<class T>
	inline std::ostream& operator<< (std::ostream& out, Vector<3, T> vec)
	{
		out << vec.x << ", " << vec.y << ", " << vec.z;
		return out;
	}
	
	typedef Vector<3> Vector3;
	typedef Vector<3, float> Vector3f;
	typedef Vector<3, double> Vector3d;
	typedef Vector<3, int> Vector3i;
	typedef Vector<3, unsigned int> Vector3ui;
}
