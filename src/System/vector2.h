#pragma once

#include <ostream>
#include <cmath>

#include "vector.h"

namespace subgine
{
	
	template<class T>
	class Vector<2, T>
	{
	public:
		Vector() : x(0), y(0)
		{
			
		}
		
		Vector(T _x, T _y) : x(_x), y(_y)
		{
			
		}
		
		Vector(const Vector<2, T>& other) : x(other.x), y(other.y)
		{
			
		}
		
		template<class O>
		operator Vector< 2 , O > () const {
			return Vector< 2 , O >((O)x, (O)y);
		}
		
		template<class O>
		operator Vector< 2 , O > () {
			return Vector< 2 , O >((O)x, (O)y);
		}
		
		inline double getAngle() const
		{
			double angle = std::atan2(y, x);
			
			if (angle < 0) {
				angle += tau;
			}
			
			return angle;
		}
		
		inline double getLength() const
		{
			return std::sqrt((x*x) + (y*y));
		}
		
		void setAngle(double angle)
		{
			if (notZero()) {
				double lenght = getLength();
				x = std::cos(angle) * lenght;
				y = std::sin(angle) * lenght;
			}
		}
		
		void setLenght(double lenght)
		{
			if (notZero()) {
				double product = lenght / getLength();
				x *= product;
				y *= product;
			} else {
				x = lenght;
			}
		}
		
		Vector<2, T> project(const Vector<2, T>& other) const
		{
			return (this->dot(other.unit())) * other;
		}
		
		inline bool notZero() const
		{
			return x != 0 || y != 0;
		}
		
		Vector<2, T> unit() const
		{
			if (notZero()) {
				double lenght = getLength();
				
				return Vector<2, T>(x / lenght, y / lenght);
			} else {
				return Vector< 2 , T >(0, 0);
			}
		}
		
		inline double dot(const Vector<2, T>& vec) const
		{
			return (x * vec.x) + (y * vec.y);
		}
		
		inline double cross(const Vector<2, T>& other)
		{
			return (x * other.y) - (y * other.x);
		}
		
		inline Vector< 2 , T > cross(double multiplier)
		{
			return Vector< 2 , T >(multiplier * y, -multiplier * x);
		}
		
		Vector<2, T>& operator= (const Vector<2, T>& other)
		{
			x = other.x;
			y = other.y;
			return *this;
		}
		
		T x, y;
	};
	
	template<class T>
	Vector<2, T> operator/ (const Vector<2, T>& vec, const double& divider)
	{
		return Vector<2, T>(vec.x / divider, vec.y / divider);
	}
	
	template<class T>
	Vector<2, T> operator/ (const Vector<2, T>& vec1, const Vector<2, T>& vec2)
	{
		return Vector<2, T>(vec1.x / vec2.x, vec1.y / vec2.y);
	}
	
	template<class T>
	Vector<2, T> operator* (const Vector<2, T>& vec, const double& multiplier)
	{
		return Vector<2, T>(vec.x * multiplier, vec.y * multiplier);
	}
	
	template<class T>
	Vector<2, T> operator* (const double& multiplier, const Vector<2, T>& vec)
	{
		return Vector<2, T>(vec.x * multiplier, vec.y * multiplier);
	}
	
	template<class T>
	Vector<2, T>& operator*= (Vector<2, T>& vec, const double& multiplier)
	{
		vec.x *= multiplier;
		vec.y *= multiplier;
		return vec;
	}
	
	template<class T>
	Vector<2, T> operator+ (const Vector<2, T>& vec1, const Vector<2, T>& vec2)
	{
		return Vector<2, T>(vec1.x + vec2.x, vec1.y + vec2.y);
	}
	
	template<class T>
	Vector<2, T>& operator+= (Vector<2, T>& vec1, const Vector<2, T>& vec2)
	{
		vec1.x += vec2.x;
		vec1.y += vec2.y;
		return vec1;
	}
	
	template<class T>
	Vector<2, T> operator- (const Vector<2, T>& vec1, const Vector<2, T>& vec2)
	{
		return Vector<2, T>(vec1.x - vec2.x, vec1.y - vec2.y);
	}
	
	template<class T>
	Vector<2, T>& operator-= (Vector<2, T>& vec1, const Vector<2, T>& vec2)
	{
		vec1.x -= vec2.x;
		vec1.y -= vec2.y;
		return vec1;
	}
	
	template<class T>
	Vector<2, T> operator* (const Vector<2, T>& vec1, const Vector<2, T>& vec2)
	{
		return Vector<2, T>(vec1.x * vec2.x, vec1.y * vec2.y);
	}
	
	template<class T>
	Vector<2, T>& operator/= (Vector<2, T>& vec, const double& divider)
	{
		vec.x /= divider;
		vec.y /= divider;
		return vec;
	}

	template<class T>
	inline std::ostream& operator<< (std::ostream& out, Vector<2, T> vec)
	{
		out << vec.x << ", " << vec.y;
		return out;
	}
	
	
	typedef Vector<2> Vector2;
	typedef Vector<2, float> Vector2f;
	typedef Vector<2, double> Vector2d;
	typedef Vector<2, int> Vector2i;
	typedef Vector<2, unsigned int> Vector2ui;
}
