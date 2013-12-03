#pragma once

#include "const.h"
#include "vector.h"

namespace subgine
{
	
	template<class T>
	class Vector<2, T>
	{
	public:
		Vector(T _x = 0, T _y = 0) : x(_x), y(_y)
		{
			
		}
		
		Vector(const Vector<2, T>& other) : x(other.x), y(other.y)
		{
			
		}
		
		double getAngle() const
		{
			double angle = atan2(y, x);
			
			if (angle < 0) {
				angle += 2 * pi;
			}
			
			return angle;
		}
		
		double getLength() const
		{
			return sqrt((x*x) + (y*y));
		}
		
		void setAngle(double angle)
		{
			if (x != 0 || y != 0) {
				double lenght = getLength();
				x = cos(angle) * lenght;
				y = sin(angle) * lenght;
			}
		}
		
		void setLenght(double lenght)
		{
			if (x != 0 || y != 0) {
				double product = lenght / getLength();
				x *= product;
				y *= product;
			} else {
				x = lenght;
			}
		}
		
		Vector<2, T> project(Vector<2, T> other) const
		{
			return (this->dot(other.unit())) * other;
		}
		
		Vector<2, T> unit() const
		{
			double lenght = getLength();
			return Vector<2, T>(x / lenght, y / lenght);
		}
		
		double dot(const Vector<2, T>& vec) const
		{
			return (x * vec.x) + (y * vec.y);
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

}
