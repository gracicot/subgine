#pragma once

#include "vector.h"

#include <iosfwd>
#include <type_traits>

namespace sbg {

template<class T>
class Vector<1, T>
{
public:
	Vector();
	Vector(T _x);
	Vector(const Vector<1, T>& other);
	
	template<class O>
	operator Vector< 1 , O > () const
	{
		return Vector< 1 , O >(static_cast<O>(x));
	}

	double getLength() const;
	void setLength(double length);
	
	bool notZero() const;
	Vector<1, T> unit() const;
	Vector< 2 , T > cross(const Vector< 2 , T >& other);
	
	Vector<1, T>& operator= (const Vector<1, T>& other);
	Vector<1, T>& operator= (T value);
	bool operator< (const Vector<1, T>& other) const;
	bool operator> (const Vector<1, T>& other) const;
	bool operator> (double length) const;
	bool operator< (double length) const;
	bool operator== (const Vector<1, T>& other) const;
	bool operator!= (const Vector<1, T>& other) const;
	operator T () const;

	T x;
	
	constexpr static int size = 1;
	using type = T;
};

template<class T>
Vector<1, T> operator/ (const Vector<1, T>& vec, const double& divider);

template<class T>
Vector<1, T> operator/ (const Vector<1, T>& vec1, const Vector<1, T>& vec2);

template<class T>
Vector<1, T> operator* (const Vector<1, T>& vec, const double& multiplier);

template<class T>
Vector<1, T> operator* (const double& multiplier, const Vector<1, T>& vec);

template<class T>
Vector<1, T>& operator*= (Vector<1, T>& vec, const double& multiplier);

template<class T>
Vector<1, T> operator+ (const Vector<1, T>& vec1, const Vector<1, T>& vec2);

template<class T>
Vector<1, T> operator+ (const Vector<1, T>& vec1, T scalar);

template<class T>
Vector<1, T>& operator+= (Vector<1, T>& vec1, const Vector<1, T>& vec2);

template<class T>
Vector<1, T>& operator+= (Vector<1, T>& vec1, T scalar);

template<class T>
Vector<1, T> operator- (const Vector<1, T>& vec1, const Vector<1, T>& vec2);

template<class T>
Vector<1, T> operator- (const Vector<1, T>& vec1, T scalar);

template<class T>
Vector<1, T>& operator-= (Vector<1, T>& vec1, const Vector<1, T>& vec2);

template<class T>
Vector<1, T>& operator-= (Vector<1, T>& vec1, T scalar);

template<class T>
Vector<1, T>& operator/= (Vector<1, T>& vec, const double& divider);

template<class T>
std::ostream& operator<< (std::ostream& out, Vector<1, T> vec);

extern template Vector<1, float> operator/ (const Vector<1, float>& vec, const double& divider);
extern template Vector<1, float> operator/ (const Vector<1, float>& vec1, const Vector<1, float>& vec2);
extern template Vector<1, float> operator* (const Vector<1, float>& vec, const double& multiplier);
extern template Vector<1, float> operator* (const double& multiplier, const Vector<1, float>& vec);
extern template Vector<1, float>& operator*= (Vector<1, float>& vec, const double& multiplier);
extern template Vector<1, float> operator+ (const Vector<1, float>& vec1, const Vector<1, float>& vec2);
extern template Vector<1, float> operator+ (const Vector<1, float>& vec1, float scalar);
extern template Vector<1, float>& operator+= (Vector<1, float>& vec1, const Vector<1, float>& vec2);
extern template Vector<1, float>& operator+= (Vector<1, float>& vec1, float scalar);
extern template Vector<1, float> operator- (const Vector<1, float>& vec1, const Vector<1, float>& vec2);
extern template Vector<1, float> operator- (const Vector<1, float>& vec1, float scalar);
extern template Vector<1, float>& operator-= (Vector<1, float>& vec1, const Vector<1, float>& vec2);
extern template Vector<1, float>& operator-= (Vector<1, float>& vec1, float scalar);
extern template Vector<1, float>& operator/= (Vector<1, float>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, float> vec);

extern template Vector<1, double> operator/ (const Vector<1, double>& vec, const double& divider);
extern template Vector<1, double> operator/ (const Vector<1, double>& vec1, const Vector<1, double>& vec2);
extern template Vector<1, double> operator* (const Vector<1, double>& vec, const double& multiplier);
extern template Vector<1, double> operator* (const double& multiplier, const Vector<1, double>& vec);
extern template Vector<1, double>& operator*= (Vector<1, double>& vec, const double& multiplier);
extern template Vector<1, double> operator+ (const Vector<1, double>& vec1, const Vector<1, double>& vec2);
extern template Vector<1, double> operator+ (const Vector<1, double>& vec1, double scalar);
extern template Vector<1, double>& operator+= (Vector<1, double>& vec1, const Vector<1, double>& vec2);
extern template Vector<1, double>& operator+= (Vector<1, double>& vec1, double scalar);
extern template Vector<1, double> operator- (const Vector<1, double>& vec1, const Vector<1, double>& vec2);
extern template Vector<1, double> operator- (const Vector<1, double>& vec1, double scalar);
extern template Vector<1, double>& operator-= (Vector<1, double>& vec1, const Vector<1, double>& vec2);
extern template Vector<1, double>& operator-= (Vector<1, double>& vec1, double scalar);
extern template Vector<1, double>& operator/= (Vector<1, double>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, double> vec);

extern template Vector<1, long double> operator/ (const Vector<1, long double>& vec, const double& divider);
extern template Vector<1, long double> operator/ (const Vector<1, long double>& vec1, const Vector<1, long double>& vec2);
extern template Vector<1, long double> operator* (const Vector<1, long double>& vec, const double& multiplier);
extern template Vector<1, long double> operator* (const double& multiplier, const Vector<1, long double>& vec);
extern template Vector<1, long double>& operator*= (Vector<1, long double>& vec, const double& multiplier);
extern template Vector<1, long double> operator+ (const Vector<1, long double>& vec1, const Vector<1, long double>& vec2);
extern template Vector<1, long double> operator+ (const Vector<1, long double>& vec1, long double scalar);
extern template Vector<1, long double>& operator+= (Vector<1, long double>& vec1, const Vector<1, long double>& vec2);
extern template Vector<1, long double>& operator+= (Vector<1, long double>& vec1, long double scalar);
extern template Vector<1, long double> operator- (const Vector<1, long double>& vec1, const Vector<1, long double>& vec2);
extern template Vector<1, long double> operator- (const Vector<1, long double>& vec1, long double scalar);
extern template Vector<1, long double>& operator-= (Vector<1, long double>& vec1, const Vector<1, long double>& vec2);
extern template Vector<1, long double>& operator-= (Vector<1, long double>& vec1, long double scalar);
extern template Vector<1, long double>& operator/= (Vector<1, long double>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, long double> vec);

extern template Vector<1, int> operator/ (const Vector<1, int>& vec, const double& divider);
extern template Vector<1, int> operator/ (const Vector<1, int>& vec1, const Vector<1, int>& vec2);
extern template Vector<1, int> operator* (const Vector<1, int>& vec, const double& multiplier);
extern template Vector<1, int> operator* (const double& multiplier, const Vector<1, int>& vec);
extern template Vector<1, int>& operator*= (Vector<1, int>& vec, const double& multiplier);
extern template Vector<1, int> operator+ (const Vector<1, int>& vec1, const Vector<1, int>& vec2);
extern template Vector<1, int> operator+ (const Vector<1, int>& vec1, int scalar);
extern template Vector<1, int>& operator+= (Vector<1, int>& vec1, const Vector<1, int>& vec2);
extern template Vector<1, int>& operator+= (Vector<1, int>& vec1, int scalar);
extern template Vector<1, int> operator- (const Vector<1, int>& vec1, const Vector<1, int>& vec2);
extern template Vector<1, int> operator- (const Vector<1, int>& vec1, int scalar);
extern template Vector<1, int>& operator-= (Vector<1, int>& vec1, const Vector<1, int>& vec2);
extern template Vector<1, int>& operator-= (Vector<1, int>& vec1, int scalar);
extern template Vector<1, int>& operator/= (Vector<1, int>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, int> vec);

extern template Vector<1, unsigned int> operator/ (const Vector<1, unsigned int>& vec, const double& divider);
extern template Vector<1, unsigned int> operator/ (const Vector<1, unsigned int>& vec1, const Vector<1, unsigned int>& vec2);
extern template Vector<1, unsigned int> operator* (const Vector<1, unsigned int>& vec, const double& multiplier);
extern template Vector<1, unsigned int> operator* (const double& multiplier, const Vector<1, unsigned int>& vec);
extern template Vector<1, unsigned int>& operator*= (Vector<1, unsigned int>& vec, const double& multiplier);
extern template Vector<1, unsigned int> operator+ (const Vector<1, unsigned int>& vec1, const Vector<1, unsigned int>& vec2);
extern template Vector<1, unsigned int> operator+ (const Vector<1, unsigned int>& vec1, unsigned int scalar);
extern template Vector<1, unsigned int>& operator+= (Vector<1, unsigned int>& vec1, const Vector<1, unsigned int>& vec2);
extern template Vector<1, unsigned int>& operator+= (Vector<1, unsigned int>& vec1, unsigned int scalar);
extern template Vector<1, unsigned int> operator- (const Vector<1, unsigned int>& vec1, const Vector<1, unsigned int>& vec2);
extern template Vector<1, unsigned int> operator- (const Vector<1, unsigned int>& vec1, unsigned int scalar);
extern template Vector<1, unsigned int>& operator-= (Vector<1, unsigned int>& vec1, const Vector<1, unsigned int>& vec2);
extern template Vector<1, unsigned int>& operator-= (Vector<1, unsigned int>& vec1, unsigned int scalar);
extern template Vector<1, unsigned int>& operator/= (Vector<1, unsigned int>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, unsigned int> vec);

extern template Vector<1, long> operator/ (const Vector<1, long>& vec, const double& divider);
extern template Vector<1, long> operator/ (const Vector<1, long>& vec1, const Vector<1, long>& vec2);
extern template Vector<1, long> operator* (const Vector<1, long>& vec, const double& multiplier);
extern template Vector<1, long> operator* (const double& multiplier, const Vector<1, long>& vec);
extern template Vector<1, long>& operator*= (Vector<1, long>& vec, const double& multiplier);
extern template Vector<1, long> operator+ (const Vector<1, long>& vec1, const Vector<1, long>& vec2);
extern template Vector<1, long> operator+ (const Vector<1, long>& vec1, long scalar);
extern template Vector<1, long>& operator+= (Vector<1, long>& vec1, const Vector<1, long>& vec2);
extern template Vector<1, long>& operator+= (Vector<1, long>& vec1, long scalar);
extern template Vector<1, long> operator- (const Vector<1, long>& vec1, const Vector<1, long>& vec2);
extern template Vector<1, long> operator- (const Vector<1, long>& vec1, long scalar);
extern template Vector<1, long>& operator-= (Vector<1, long>& vec1, const Vector<1, long>& vec2);
extern template Vector<1, long>& operator-= (Vector<1, long>& vec1, long scalar);
extern template Vector<1, long>& operator/= (Vector<1, long>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, long> vec);

extern template Vector<1, unsigned long> operator/ (const Vector<1, unsigned long>& vec, const double& divider);
extern template Vector<1, unsigned long> operator/ (const Vector<1, unsigned long>& vec1, const Vector<1, unsigned long>& vec2);
extern template Vector<1, unsigned long> operator* (const Vector<1, unsigned long>& vec, const double& multiplier);
extern template Vector<1, unsigned long> operator* (const double& multiplier, const Vector<1, unsigned long>& vec);
extern template Vector<1, unsigned long>& operator*= (Vector<1, unsigned long>& vec, const double& multiplier);
extern template Vector<1, unsigned long> operator+ (const Vector<1, unsigned long>& vec1, const Vector<1, unsigned long>& vec2);
extern template Vector<1, unsigned long> operator+ (const Vector<1, unsigned long>& vec1, unsigned long scalar);
extern template Vector<1, unsigned long>& operator+= (Vector<1, unsigned long>& vec1, const Vector<1, unsigned long>& vec2);
extern template Vector<1, unsigned long>& operator+= (Vector<1, unsigned long>& vec1, unsigned long scalar);
extern template Vector<1, unsigned long> operator- (const Vector<1, unsigned long>& vec1, const Vector<1, unsigned long>& vec2);
extern template Vector<1, unsigned long> operator- (const Vector<1, unsigned long>& vec1, unsigned long scalar);
extern template Vector<1, unsigned long>& operator-= (Vector<1, unsigned long>& vec1, const Vector<1, unsigned long>& vec2);
extern template Vector<1, unsigned long>& operator-= (Vector<1, unsigned long>& vec1, unsigned long scalar);
extern template Vector<1, unsigned long>& operator/= (Vector<1, unsigned long>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, unsigned long> vec);

extern template Vector<1, short> operator/ (const Vector<1, short>& vec, const double& divider);
extern template Vector<1, short> operator/ (const Vector<1, short>& vec1, const Vector<1, short>& vec2);
extern template Vector<1, short> operator* (const Vector<1, short>& vec, const double& multiplier);
extern template Vector<1, short> operator* (const double& multiplier, const Vector<1, short>& vec);
extern template Vector<1, short>& operator*= (Vector<1, short>& vec, const double& multiplier);
extern template Vector<1, short> operator+ (const Vector<1, short>& vec1, const Vector<1, short>& vec2);
extern template Vector<1, short> operator+ (const Vector<1, short>& vec1, short scalar);
extern template Vector<1, short>& operator+= (Vector<1, short>& vec1, const Vector<1, short>& vec2);
extern template Vector<1, short>& operator+= (Vector<1, short>& vec1, short scalar);
extern template Vector<1, short> operator- (const Vector<1, short>& vec1, const Vector<1, short>& vec2);
extern template Vector<1, short> operator- (const Vector<1, short>& vec1, short scalar);
extern template Vector<1, short>& operator-= (Vector<1, short>& vec1, const Vector<1, short>& vec2);
extern template Vector<1, short>& operator-= (Vector<1, short>& vec1, short scalar);
extern template Vector<1, short>& operator/= (Vector<1, short>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, short> vec);

extern template Vector<1, unsigned short> operator/ (const Vector<1, unsigned short>& vec, const double& divider);
extern template Vector<1, unsigned short> operator/ (const Vector<1, unsigned short>& vec1, const Vector<1, unsigned short>& vec2);
extern template Vector<1, unsigned short> operator* (const Vector<1, unsigned short>& vec, const double& multiplier);
extern template Vector<1, unsigned short> operator* (const double& multiplier, const Vector<1, unsigned short>& vec);
extern template Vector<1, unsigned short>& operator*= (Vector<1, unsigned short>& vec, const double& multiplier);
extern template Vector<1, unsigned short> operator+ (const Vector<1, unsigned short>& vec1, const Vector<1, unsigned short>& vec2);
extern template Vector<1, unsigned short> operator+ (const Vector<1, unsigned short>& vec1, unsigned short scalar);
extern template Vector<1, unsigned short>& operator+= (Vector<1, unsigned short>& vec1, const Vector<1, unsigned short>& vec2);
extern template Vector<1, unsigned short>& operator+= (Vector<1, unsigned short>& vec1, unsigned short scalar);
extern template Vector<1, unsigned short> operator- (const Vector<1, unsigned short>& vec1, const Vector<1, unsigned short>& vec2);
extern template Vector<1, unsigned short> operator- (const Vector<1, unsigned short>& vec1, unsigned short scalar);
extern template Vector<1, unsigned short>& operator-= (Vector<1, unsigned short>& vec1, const Vector<1, unsigned short>& vec2);
extern template Vector<1, unsigned short>& operator-= (Vector<1, unsigned short>& vec1, unsigned short scalar);
extern template Vector<1, unsigned short>& operator/= (Vector<1, unsigned short>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, unsigned short> vec);

extern template Vector<1, char> operator/ (const Vector<1, char>& vec, const double& divider);
extern template Vector<1, char> operator/ (const Vector<1, char>& vec1, const Vector<1, char>& vec2);
extern template Vector<1, char> operator* (const Vector<1, char>& vec, const double& multiplier);
extern template Vector<1, char> operator* (const double& multiplier, const Vector<1, char>& vec);
extern template Vector<1, char>& operator*= (Vector<1, char>& vec, const double& multiplier);
extern template Vector<1, char> operator+ (const Vector<1, char>& vec1, const Vector<1, char>& vec2);
extern template Vector<1, char> operator+ (const Vector<1, char>& vec1, char scalar);
extern template Vector<1, char>& operator+= (Vector<1, char>& vec1, const Vector<1, char>& vec2);
extern template Vector<1, char>& operator+= (Vector<1, char>& vec1, char scalar);
extern template Vector<1, char> operator- (const Vector<1, char>& vec1, const Vector<1, char>& vec2);
extern template Vector<1, char> operator- (const Vector<1, char>& vec1, char scalar);
extern template Vector<1, char>& operator-= (Vector<1, char>& vec1, const Vector<1, char>& vec2);
extern template Vector<1, char>& operator-= (Vector<1, char>& vec1, char scalar);
extern template Vector<1, char>& operator/= (Vector<1, char>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, char> vec);

extern template Vector<1, unsigned char> operator/ (const Vector<1, unsigned char>& vec, const double& divider);
extern template Vector<1, unsigned char> operator/ (const Vector<1, unsigned char>& vec1, const Vector<1, unsigned char>& vec2);
extern template Vector<1, unsigned char> operator* (const Vector<1, unsigned char>& vec, const double& multiplier);
extern template Vector<1, unsigned char> operator* (const double& multiplier, const Vector<1, unsigned char>& vec);
extern template Vector<1, unsigned char>& operator*= (Vector<1, unsigned char>& vec, const double& multiplier);
extern template Vector<1, unsigned char> operator+ (const Vector<1, unsigned char>& vec1, const Vector<1, unsigned char>& vec2);
extern template Vector<1, unsigned char> operator+ (const Vector<1, unsigned char>& vec1, unsigned char scalar);
extern template Vector<1, unsigned char>& operator+= (Vector<1, unsigned char>& vec1, const Vector<1, unsigned char>& vec2);
extern template Vector<1, unsigned char>& operator+= (Vector<1, unsigned char>& vec1, unsigned char scalar);
extern template Vector<1, unsigned char> operator- (const Vector<1, unsigned char>& vec1, const Vector<1, unsigned char>& vec2);
extern template Vector<1, unsigned char> operator- (const Vector<1, unsigned char>& vec1, unsigned char scalar);
extern template Vector<1, unsigned char>& operator-= (Vector<1, unsigned char>& vec1, const Vector<1, unsigned char>& vec2);
extern template Vector<1, unsigned char>& operator-= (Vector<1, unsigned char>& vec1, unsigned char scalar);
extern template Vector<1, unsigned char>& operator/= (Vector<1, unsigned char>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<1, unsigned char> vec);

extern template class Vector<1, float>;
extern template class Vector<1, double>;
extern template class Vector<1, long double>;
extern template class Vector<1, int>;
extern template class Vector<1, unsigned int>;
extern template class Vector<1, long>;
extern template class Vector<1, unsigned long>;
extern template class Vector<1, short>;
extern template class Vector<1, unsigned short>;
extern template class Vector<1, char>;
extern template class Vector<1, unsigned char>;

typedef Vector<1, float> Vector1f;
typedef Vector<1, double> Vector1d;
typedef Vector<1, long double> Vector1ld;
typedef Vector<1, int> Vector1i;
typedef Vector<1, unsigned int> Vector1ui;
typedef Vector<1, long> Vector1l;
typedef Vector<1, unsigned long> Vector1ul;
typedef Vector<1, short> Vector1s;
typedef Vector<1, unsigned short> Vector1us;
typedef Vector<1, char> Vector1c;
typedef Vector<1, unsigned char> Vector1uc;

}
