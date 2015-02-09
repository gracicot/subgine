#pragma once

#include <ostream>
#include <cmath>
#include "vector.h"

namespace sbg
{

template<class T>
class Vector<4, T>
{
public:
	Vector();
	Vector(T _x, T _y, T _z, T _w);
	Vector(const Vector<4, T>& other);
	
	template<class O>
	operator Vector< 4 , O >() const
	{
		return Vector< 4 , O >(
			static_cast<O>(x),
			static_cast<O>(y),
			static_cast<O>(z),
			static_cast<O>(w)
		);
	}
	
	double getLength() const;
	void setLenght(double lenght);
	Vector<4, T> project(Vector<4, T> other) const;
	bool notZero() const;
	Vector<4, T> unit() const;
	double dot(const Vector<4, T>& vec) const;
	
	Vector<4, T>& operator= (const Vector<4, T>& other);
	
	bool operator< (const Vector<4, T>& other) const;
	bool operator> (const Vector<4, T>& other) const;
	bool operator> (double length) const;
	bool operator< (double length) const;
	bool operator== (const Vector<4, T>& other) const;
	bool operator!= (const Vector<4, T>& other) const;
	
	T x, y, z, w;
	
	constexpr static int size = 4;
	using type = T;
};

template<class T> Vector<4, T> operator/ (const Vector<4, T>& vec, const double& divider);
template<class T> Vector<4, T> operator/ (const Vector<4, T>& vec1, const Vector<4, T>& vec2);
template<class T> Vector<4, T> operator* (const Vector<4, T>& vec, const double& multiplier);
template<class T> Vector<4, T> operator* (const double& multiplier, const Vector<4, T>& vec);
template<class T> Vector<4, T>& operator*= (Vector<4, T>& vec, const double& multiplier);
template<class T> Vector<4, T> operator+ (const Vector<4, T>& vec1, const Vector<4, T>& vec2);
template<class T> Vector<4, T>& operator+= (Vector<4, T>& vec1, const Vector<4, T>& vec2);
template<class T> Vector<4, T> operator- (const Vector<4, T>& vec1, const Vector<4, T>& vec2);
template<class T> Vector<4, T>& operator-= (Vector<4, T>& vec1, const Vector<4, T>& vec2);
template<class T> Vector<4, T>& operator/= (Vector<4, T>& vec, const double& divider);
template<class T> std::ostream& operator<< (std::ostream& out, Vector<4, T> vec);

extern template Vector<4, float> operator/ (const Vector<4, float>& vec, const double& divider);
extern template Vector<4, float> operator* (const Vector<4, float>& vec, const double& multiplier);
extern template Vector<4, float> operator* (const double& multiplier, const Vector<4, float>& vec);
extern template Vector<4, float>& operator*= (Vector<4, float>& vec, const double& multiplier);
extern template Vector<4, float> operator+ (const Vector<4, float>& vec1, const Vector<4, float>& vec2);
extern template Vector<4, float>& operator+= (Vector<4, float>& vec1, const Vector<4, float>& vec2);
extern template Vector<4, float> operator- (const Vector<4, float>& vec1, const Vector<4, float>& vec2);
extern template Vector<4, float>& operator-= (Vector<4, float>& vec1, const Vector<4, float>& vec2);
extern template Vector<4, float>& operator/= (Vector<4, float>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, float> vec);

extern template Vector<4, double> operator/ (const Vector<4, double>& vec, const double& divider);
extern template Vector<4, double> operator* (const Vector<4, double>& vec, const double& multiplier);
extern template Vector<4, double> operator* (const double& multiplier, const Vector<4, double>& vec);
extern template Vector<4, double>& operator*= (Vector<4, double>& vec, const double& multiplier);
extern template Vector<4, double> operator+ (const Vector<4, double>& vec1, const Vector<4, double>& vec2);
extern template Vector<4, double>& operator+= (Vector<4, double>& vec1, const Vector<4, double>& vec2);
extern template Vector<4, double> operator- (const Vector<4, double>& vec1, const Vector<4, double>& vec2);
extern template Vector<4, double>& operator-= (Vector<4, double>& vec1, const Vector<4, double>& vec2);
extern template Vector<4, double>& operator/= (Vector<4, double>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, double> vec);

extern template Vector<4, long double> operator/ (const Vector<4, long double>& vec, const double& divider);
extern template Vector<4, long double> operator* (const Vector<4, long double>& vec, const double& multiplier);
extern template Vector<4, long double> operator* (const double& multiplier, const Vector<4, long double>& vec);
extern template Vector<4, long double>& operator*= (Vector<4, long double>& vec, const double& multiplier);
extern template Vector<4, long double> operator+ (const Vector<4, long double>& vec1, const Vector<4, long double>& vec2);
extern template Vector<4, long double>& operator+= (Vector<4, long double>& vec1, const Vector<4, long double>& vec2);
extern template Vector<4, long double> operator- (const Vector<4, long double>& vec1, const Vector<4, long double>& vec2);
extern template Vector<4, long double>& operator-= (Vector<4, long double>& vec1, const Vector<4, long double>& vec2);
extern template Vector<4, long double>& operator/= (Vector<4, long double>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, long double> vec);

extern template Vector<4, int> operator/ (const Vector<4, int>& vec, const double& divider);
extern template Vector<4, int> operator* (const Vector<4, int>& vec, const double& multiplier);
extern template Vector<4, int> operator* (const double& multiplier, const Vector<4, int>& vec);
extern template Vector<4, int>& operator*= (Vector<4, int>& vec, const double& multiplier);
extern template Vector<4, int> operator+ (const Vector<4, int>& vec1, const Vector<4, int>& vec2);
extern template Vector<4, int>& operator+= (Vector<4, int>& vec1, const Vector<4, int>& vec2);
extern template Vector<4, int> operator- (const Vector<4, int>& vec1, const Vector<4, int>& vec2);
extern template Vector<4, int>& operator-= (Vector<4, int>& vec1, const Vector<4, int>& vec2);
extern template Vector<4, int>& operator/= (Vector<4, int>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, int> vec);

extern template Vector<4, unsigned int> operator/ (const Vector<4, unsigned int>& vec, const double& divider);
extern template Vector<4, unsigned int> operator* (const Vector<4, unsigned int>& vec, const double& multiplier);
extern template Vector<4, unsigned int> operator* (const double& multiplier, const Vector<4, unsigned int>& vec);
extern template Vector<4, unsigned int>& operator*= (Vector<4, unsigned int>& vec, const double& multiplier);
extern template Vector<4, unsigned int> operator+ (const Vector<4, unsigned int>& vec1, const Vector<4, unsigned int>& vec2);
extern template Vector<4, unsigned int>& operator+= (Vector<4, unsigned int>& vec1, const Vector<4, unsigned int>& vec2);
extern template Vector<4, unsigned int> operator- (const Vector<4, unsigned int>& vec1, const Vector<4, unsigned int>& vec2);
extern template Vector<4, unsigned int>& operator-= (Vector<4, unsigned int>& vec1, const Vector<4, unsigned int>& vec2);
extern template Vector<4, unsigned int>& operator/= (Vector<4, unsigned int>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, unsigned int> vec);

extern template Vector<4, long> operator/ (const Vector<4, long>& vec, const double& divider);
extern template Vector<4, long> operator* (const Vector<4, long>& vec, const double& multiplier);
extern template Vector<4, long> operator* (const double& multiplier, const Vector<4, long>& vec);
extern template Vector<4, long>& operator*= (Vector<4, long>& vec, const double& multiplier);
extern template Vector<4, long> operator+ (const Vector<4, long>& vec1, const Vector<4, long>& vec2);
extern template Vector<4, long>& operator+= (Vector<4, long>& vec1, const Vector<4, long>& vec2);
extern template Vector<4, long> operator- (const Vector<4, long>& vec1, const Vector<4, long>& vec2);
extern template Vector<4, long>& operator-= (Vector<4, long>& vec1, const Vector<4, long>& vec2);
extern template Vector<4, long>& operator/= (Vector<4, long>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, long> vec);

extern template Vector<4, unsigned long> operator/ (const Vector<4, unsigned long>& vec, const double& divider);
extern template Vector<4, unsigned long> operator* (const Vector<4, unsigned long>& vec, const double& multiplier);
extern template Vector<4, unsigned long> operator* (const double& multiplier, const Vector<4, unsigned long>& vec);
extern template Vector<4, unsigned long>& operator*= (Vector<4, unsigned long>& vec, const double& multiplier);
extern template Vector<4, unsigned long> operator+ (const Vector<4, unsigned long>& vec1, const Vector<4, unsigned long>& vec2);
extern template Vector<4, unsigned long>& operator+= (Vector<4, unsigned long>& vec1, const Vector<4, unsigned long>& vec2);
extern template Vector<4, unsigned long> operator- (const Vector<4, unsigned long>& vec1, const Vector<4, unsigned long>& vec2);
extern template Vector<4, unsigned long>& operator-= (Vector<4, unsigned long>& vec1, const Vector<4, unsigned long>& vec2);
extern template Vector<4, unsigned long>& operator/= (Vector<4, unsigned long>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, unsigned long> vec);

extern template Vector<4, short> operator/ (const Vector<4, short>& vec, const double& divider);
extern template Vector<4, short> operator* (const Vector<4, short>& vec, const double& multiplier);
extern template Vector<4, short> operator* (const double& multiplier, const Vector<4, short>& vec);
extern template Vector<4, short>& operator*= (Vector<4, short>& vec, const double& multiplier);
extern template Vector<4, short> operator+ (const Vector<4, short>& vec1, const Vector<4, short>& vec2);
extern template Vector<4, short>& operator+= (Vector<4, short>& vec1, const Vector<4, short>& vec2);
extern template Vector<4, short> operator- (const Vector<4, short>& vec1, const Vector<4, short>& vec2);
extern template Vector<4, short>& operator-= (Vector<4, short>& vec1, const Vector<4, short>& vec2);
extern template Vector<4, short>& operator/= (Vector<4, short>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, short> vec);

extern template Vector<4, unsigned short> operator/ (const Vector<4, unsigned short>& vec, const double& divider);
extern template Vector<4, unsigned short> operator* (const Vector<4, unsigned short>& vec, const double& multiplier);
extern template Vector<4, unsigned short> operator* (const double& multiplier, const Vector<4, unsigned short>& vec);
extern template Vector<4, unsigned short>& operator*= (Vector<4, unsigned short>& vec, const double& multiplier);
extern template Vector<4, unsigned short> operator+ (const Vector<4, unsigned short>& vec1, const Vector<4, unsigned short>& vec2);
extern template Vector<4, unsigned short>& operator+= (Vector<4, unsigned short>& vec1, const Vector<4, unsigned short>& vec2);
extern template Vector<4, unsigned short> operator- (const Vector<4, unsigned short>& vec1, const Vector<4, unsigned short>& vec2);
extern template Vector<4, unsigned short>& operator-= (Vector<4, unsigned short>& vec1, const Vector<4, unsigned short>& vec2);
extern template Vector<4, unsigned short>& operator/= (Vector<4, unsigned short>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, unsigned short> vec);

extern template Vector<4, char> operator/ (const Vector<4, char>& vec, const double& divider);
extern template Vector<4, char> operator* (const Vector<4, char>& vec, const double& multiplier);
extern template Vector<4, char> operator* (const double& multiplier, const Vector<4, char>& vec);
extern template Vector<4, char>& operator*= (Vector<4, char>& vec, const double& multiplier);
extern template Vector<4, char> operator+ (const Vector<4, char>& vec1, const Vector<4, char>& vec2);
extern template Vector<4, char>& operator+= (Vector<4, char>& vec1, const Vector<4, char>& vec2);
extern template Vector<4, char> operator- (const Vector<4, char>& vec1, const Vector<4, char>& vec2);
extern template Vector<4, char>& operator-= (Vector<4, char>& vec1, const Vector<4, char>& vec2);
extern template Vector<4, char>& operator/= (Vector<4, char>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, char> vec);

extern template Vector<4, unsigned char> operator/ (const Vector<4, unsigned char>& vec, const double& divider);
extern template Vector<4, unsigned char> operator* (const Vector<4, unsigned char>& vec, const double& multiplier);
extern template Vector<4, unsigned char> operator* (const double& multiplier, const Vector<4, unsigned char>& vec);
extern template Vector<4, unsigned char>& operator*= (Vector<4, unsigned char>& vec, const double& multiplier);
extern template Vector<4, unsigned char> operator+ (const Vector<4, unsigned char>& vec1, const Vector<4, unsigned char>& vec2);
extern template Vector<4, unsigned char>& operator+= (Vector<4, unsigned char>& vec1, const Vector<4, unsigned char>& vec2);
extern template Vector<4, unsigned char> operator- (const Vector<4, unsigned char>& vec1, const Vector<4, unsigned char>& vec2);
extern template Vector<4, unsigned char>& operator-= (Vector<4, unsigned char>& vec1, const Vector<4, unsigned char>& vec2);
extern template Vector<4, unsigned char>& operator/= (Vector<4, unsigned char>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<4, unsigned char> vec);

extern template class Vector<4, float>;
extern template class Vector<4, double>;
extern template class Vector<4, long double>;
extern template class Vector<4, int>;
extern template class Vector<4, unsigned int>;
extern template class Vector<4, long>;
extern template class Vector<4, unsigned long>;
extern template class Vector<4, short>;
extern template class Vector<4, unsigned short>;
extern template class Vector<4, char>;
extern template class Vector<4, unsigned char>;

typedef Vector<4, float> Vector4f;
typedef Vector<4, double> Vector4d;
typedef Vector<4, long double> Vector4ld;
typedef Vector<4, int> Vector4i;
typedef Vector<4, unsigned int> Vector4ui;
typedef Vector<4, long> Vector4l;
typedef Vector<4, unsigned long> Vector4ul;
typedef Vector<4, short> Vector4s;
typedef Vector<4, unsigned short> Vector4us;
typedef Vector<4, char> Vector4c;
typedef Vector<4, unsigned char> Vector4uc;

}
