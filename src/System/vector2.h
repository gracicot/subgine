#pragma once

#include <ostream>
#include <cmath>

#include "vector.h"

namespace sbg
{
	
template<class T>
class Vector<2, T>
{
public:
	Vector();
	Vector(T _x, T _y);
	Vector(const Vector<2, T>& other);
	
	template <class O>
	operator Vector< 2 , O > () const
	{
		return Vector< 2 , O >(
			static_cast<O>(x),
			static_cast<O>(y)
		);
	}
	
	double getAngle() const;
	double getLength() const;
	void setAngle(double angle);
	void setLenght(double lenght);
	
	Vector<2, T> project(const Vector<2, T>& other) const;
	bool notZero() const;
	Vector<2, T> unit() const;
	Vector<2, T> angle(double angle) const;
	double dot(const Vector<2, T>& vec) const;
	Vector< 1 , T > cross(const Vector<2, T>& other) const;
	Vector< 2 , T > cross(const double multiplier) const;
	
	Vector<2, T>& operator= (const Vector<2, T>& other);
	bool operator< (const Vector<2, T>& other) const;
	bool operator> (const Vector<2, T>& other) const;
	bool operator> (double length) const;
	bool operator< (double length) const;
	
	T x, y;
	
	constexpr static int size = 2;
	using type = T;
};

template<class T>
Vector<2, T> operator/ (const Vector<2, T>& vec, const double& divider);

template<class T>
Vector<2, T> operator* (const Vector<2, T>& vec, const double& multiplier);

template<class T>
Vector<2, T> operator* (const double& multiplier, const Vector<2, T>& vec);

template<class T>
Vector<2, T>& operator*= (Vector<2, T>& vec, const double& multiplier);

template<class T>
Vector<2, T> operator+ (const Vector<2, T>& vec1, const Vector<2, T>& vec2);

template<class T>
Vector<2, T>& operator+= (Vector<2, T>& vec1, const Vector<2, T>& vec2);

template<class T>
Vector<2, T> operator- (const Vector<2, T>& vec1, const Vector<2, T>& vec2);

template<class T>
Vector<2, T>& operator-= (Vector<2, T>& vec1, const Vector<2, T>& vec2);

template<class T>
Vector<2, T>& operator/= (Vector<2, T>& vec, const double& divider);

template<class T>
std::ostream& operator<< (std::ostream& out, Vector<2, T> vec);

extern template Vector<2, float> operator/ (const Vector<2, float>& vec, const double& divider);
extern template Vector<2, float> operator* (const Vector<2, float>& vec, const double& multiplier);
extern template Vector<2, float> operator* (const double& multiplier, const Vector<2, float>& vec);
extern template Vector<2, float>& operator*= (Vector<2, float>& vec, const double& multiplier);
extern template Vector<2, float> operator+ (const Vector<2, float>& vec1, const Vector<2, float>& vec2);
extern template Vector<2, float>& operator+= (Vector<2, float>& vec1, const Vector<2, float>& vec2);
extern template Vector<2, float> operator- (const Vector<2, float>& vec1, const Vector<2, float>& vec2);
extern template Vector<2, float>& operator-= (Vector<2, float>& vec1, const Vector<2, float>& vec2);
extern template Vector<2, float>& operator/= (Vector<2, float>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, float> vec);

extern template Vector<2, double> operator/ (const Vector<2, double>& vec, const double& divider);
extern template Vector<2, double> operator* (const Vector<2, double>& vec, const double& multiplier);
extern template Vector<2, double> operator* (const double& multiplier, const Vector<2, double>& vec);
extern template Vector<2, double>& operator*= (Vector<2, double>& vec, const double& multiplier);
extern template Vector<2, double> operator+ (const Vector<2, double>& vec1, const Vector<2, double>& vec2);
extern template Vector<2, double>& operator+= (Vector<2, double>& vec1, const Vector<2, double>& vec2);
extern template Vector<2, double> operator- (const Vector<2, double>& vec1, const Vector<2, double>& vec2);
extern template Vector<2, double>& operator-= (Vector<2, double>& vec1, const Vector<2, double>& vec2);
extern template Vector<2, double>& operator/= (Vector<2, double>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, double> vec);

extern template Vector<2, long double> operator/ (const Vector<2, long double>& vec, const double& divider);
extern template Vector<2, long double> operator* (const Vector<2, long double>& vec, const double& multiplier);
extern template Vector<2, long double> operator* (const double& multiplier, const Vector<2, long double>& vec);
extern template Vector<2, long double>& operator*= (Vector<2, long double>& vec, const double& multiplier);
extern template Vector<2, long double> operator+ (const Vector<2, long double>& vec1, const Vector<2, long double>& vec2);
extern template Vector<2, long double>& operator+= (Vector<2, long double>& vec1, const Vector<2, long double>& vec2);
extern template Vector<2, long double> operator- (const Vector<2, long double>& vec1, const Vector<2, long double>& vec2);
extern template Vector<2, long double>& operator-= (Vector<2, long double>& vec1, const Vector<2, long double>& vec2);
extern template Vector<2, long double>& operator/= (Vector<2, long double>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, long double> vec);

extern template Vector<2, int> operator/ (const Vector<2, int>& vec, const double& divider);
extern template Vector<2, int> operator* (const Vector<2, int>& vec, const double& multiplier);
extern template Vector<2, int> operator* (const double& multiplier, const Vector<2, int>& vec);
extern template Vector<2, int>& operator*= (Vector<2, int>& vec, const double& multiplier);
extern template Vector<2, int> operator+ (const Vector<2, int>& vec1, const Vector<2, int>& vec2);
extern template Vector<2, int>& operator+= (Vector<2, int>& vec1, const Vector<2, int>& vec2);
extern template Vector<2, int> operator- (const Vector<2, int>& vec1, const Vector<2, int>& vec2);
extern template Vector<2, int>& operator-= (Vector<2, int>& vec1, const Vector<2, int>& vec2);
extern template Vector<2, int>& operator/= (Vector<2, int>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, int> vec);

extern template Vector<2, unsigned int> operator/ (const Vector<2, unsigned int>& vec, const double& divider);
extern template Vector<2, unsigned int> operator* (const Vector<2, unsigned int>& vec, const double& multiplier);
extern template Vector<2, unsigned int> operator* (const double& multiplier, const Vector<2, unsigned int>& vec);
extern template Vector<2, unsigned int>& operator*= (Vector<2, unsigned int>& vec, const double& multiplier);
extern template Vector<2, unsigned int> operator+ (const Vector<2, unsigned int>& vec1, const Vector<2, unsigned int>& vec2);
extern template Vector<2, unsigned int>& operator+= (Vector<2, unsigned int>& vec1, const Vector<2, unsigned int>& vec2);
extern template Vector<2, unsigned int> operator- (const Vector<2, unsigned int>& vec1, const Vector<2, unsigned int>& vec2);
extern template Vector<2, unsigned int>& operator-= (Vector<2, unsigned int>& vec1, const Vector<2, unsigned int>& vec2);
extern template Vector<2, unsigned int>& operator/= (Vector<2, unsigned int>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, unsigned int> vec);

extern template Vector<2, long> operator/ (const Vector<2, long>& vec, const double& divider);
extern template Vector<2, long> operator* (const Vector<2, long>& vec, const double& multiplier);
extern template Vector<2, long> operator* (const double& multiplier, const Vector<2, long>& vec);
extern template Vector<2, long>& operator*= (Vector<2, long>& vec, const double& multiplier);
extern template Vector<2, long> operator+ (const Vector<2, long>& vec1, const Vector<2, long>& vec2);
extern template Vector<2, long>& operator+= (Vector<2, long>& vec1, const Vector<2, long>& vec2);
extern template Vector<2, long> operator- (const Vector<2, long>& vec1, const Vector<2, long>& vec2);
extern template Vector<2, long>& operator-= (Vector<2, long>& vec1, const Vector<2, long>& vec2);
extern template Vector<2, long>& operator/= (Vector<2, long>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, long> vec);

extern template Vector<2, unsigned long> operator/ (const Vector<2, unsigned long>& vec, const double& divider);
extern template Vector<2, unsigned long> operator* (const Vector<2, unsigned long>& vec, const double& multiplier);
extern template Vector<2, unsigned long> operator* (const double& multiplier, const Vector<2, unsigned long>& vec);
extern template Vector<2, unsigned long>& operator*= (Vector<2, unsigned long>& vec, const double& multiplier);
extern template Vector<2, unsigned long> operator+ (const Vector<2, unsigned long>& vec1, const Vector<2, unsigned long>& vec2);
extern template Vector<2, unsigned long>& operator+= (Vector<2, unsigned long>& vec1, const Vector<2, unsigned long>& vec2);
extern template Vector<2, unsigned long> operator- (const Vector<2, unsigned long>& vec1, const Vector<2, unsigned long>& vec2);
extern template Vector<2, unsigned long>& operator-= (Vector<2, unsigned long>& vec1, const Vector<2, unsigned long>& vec2);
extern template Vector<2, unsigned long>& operator/= (Vector<2, unsigned long>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, unsigned long> vec);

extern template Vector<2, short> operator/ (const Vector<2, short>& vec, const double& divider);
extern template Vector<2, short> operator* (const Vector<2, short>& vec, const double& multiplier);
extern template Vector<2, short> operator* (const double& multiplier, const Vector<2, short>& vec);
extern template Vector<2, short>& operator*= (Vector<2, short>& vec, const double& multiplier);
extern template Vector<2, short> operator+ (const Vector<2, short>& vec1, const Vector<2, short>& vec2);
extern template Vector<2, short>& operator+= (Vector<2, short>& vec1, const Vector<2, short>& vec2);
extern template Vector<2, short> operator- (const Vector<2, short>& vec1, const Vector<2, short>& vec2);
extern template Vector<2, short>& operator-= (Vector<2, short>& vec1, const Vector<2, short>& vec2);
extern template Vector<2, short>& operator/= (Vector<2, short>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, short> vec);

extern template Vector<2, unsigned short> operator/ (const Vector<2, unsigned short>& vec, const double& divider);
extern template Vector<2, unsigned short> operator* (const Vector<2, unsigned short>& vec, const double& multiplier);
extern template Vector<2, unsigned short> operator* (const double& multiplier, const Vector<2, unsigned short>& vec);
extern template Vector<2, unsigned short>& operator*= (Vector<2, unsigned short>& vec, const double& multiplier);
extern template Vector<2, unsigned short> operator+ (const Vector<2, unsigned short>& vec1, const Vector<2, unsigned short>& vec2);
extern template Vector<2, unsigned short>& operator+= (Vector<2, unsigned short>& vec1, const Vector<2, unsigned short>& vec2);
extern template Vector<2, unsigned short> operator- (const Vector<2, unsigned short>& vec1, const Vector<2, unsigned short>& vec2);
extern template Vector<2, unsigned short>& operator-= (Vector<2, unsigned short>& vec1, const Vector<2, unsigned short>& vec2);
extern template Vector<2, unsigned short>& operator/= (Vector<2, unsigned short>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, unsigned short> vec);

extern template Vector<2, char> operator/ (const Vector<2, char>& vec, const double& divider);
extern template Vector<2, char> operator* (const Vector<2, char>& vec, const double& multiplier);
extern template Vector<2, char> operator* (const double& multiplier, const Vector<2, char>& vec);
extern template Vector<2, char>& operator*= (Vector<2, char>& vec, const double& multiplier);
extern template Vector<2, char> operator+ (const Vector<2, char>& vec1, const Vector<2, char>& vec2);
extern template Vector<2, char>& operator+= (Vector<2, char>& vec1, const Vector<2, char>& vec2);
extern template Vector<2, char> operator- (const Vector<2, char>& vec1, const Vector<2, char>& vec2);
extern template Vector<2, char>& operator-= (Vector<2, char>& vec1, const Vector<2, char>& vec2);
extern template Vector<2, char>& operator/= (Vector<2, char>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, char> vec);

extern template Vector<2, unsigned char> operator/ (const Vector<2, unsigned char>& vec, const double& divider);
extern template Vector<2, unsigned char> operator* (const Vector<2, unsigned char>& vec, const double& multiplier);
extern template Vector<2, unsigned char> operator* (const double& multiplier, const Vector<2, unsigned char>& vec);
extern template Vector<2, unsigned char>& operator*= (Vector<2, unsigned char>& vec, const double& multiplier);
extern template Vector<2, unsigned char> operator+ (const Vector<2, unsigned char>& vec1, const Vector<2, unsigned char>& vec2);
extern template Vector<2, unsigned char>& operator+= (Vector<2, unsigned char>& vec1, const Vector<2, unsigned char>& vec2);
extern template Vector<2, unsigned char> operator- (const Vector<2, unsigned char>& vec1, const Vector<2, unsigned char>& vec2);
extern template Vector<2, unsigned char>& operator-= (Vector<2, unsigned char>& vec1, const Vector<2, unsigned char>& vec2);
extern template Vector<2, unsigned char>& operator/= (Vector<2, unsigned char>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<2, unsigned char> vec);

extern template class Vector<2, float>;
extern template class Vector<2, double>;
extern template class Vector<2, long double>;
extern template class Vector<2, int>;
extern template class Vector<2, unsigned int>;
extern template class Vector<2, long>;
extern template class Vector<2, unsigned long>;
extern template class Vector<2, short>;
extern template class Vector<2, unsigned short>;
extern template class Vector<2, char>;
extern template class Vector<2, unsigned char>;

typedef Vector<2, float> Vector2f;
typedef Vector<2, double> Vector2d;
typedef Vector<2, long double> Vector2ld;
typedef Vector<2, int> Vector2i;
typedef Vector<2, unsigned int> Vector2ui;
typedef Vector<2, long> Vector2l;
typedef Vector<2, unsigned long> Vector2ul;
typedef Vector<2, short> Vector2s;
typedef Vector<2, unsigned short> Vector2us;
typedef Vector<2, char> Vector2c;
typedef Vector<2, unsigned char> Vector2uc;

}
