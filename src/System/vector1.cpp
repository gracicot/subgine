#include "vector1.h"

#include "vector2.h"

#include <ostream>
#include <cmath>

using namespace std;

namespace sbg {

template<class T>
Vector<1, T>::Vector() : x(0)
{}

template<class T>
Vector<1, T>::Vector(T _x) : x(_x)
{}

template<class T>
Vector<1, T>::Vector(const Vector<1, T>& other) : x(other.x)
{}

template<class T>
inline double Vector<1, T>::getLength() const
{
	return abs(x);
}

template<class T>
void Vector<1, T>::setLength(double length)
{
	if (x >= 0) {
		x = length;
	} else {
		x = -1 * length;
	}
}

template<class T>
inline bool Vector<1, T>::notZero() const
{
	return x != 0;
}

template<class T>
Vector<1, T> Vector<1, T>::unit() const
{
	if (notZero()) {
		return Vector< 1 , T >(x / abs(x));
	} else {
		return Vector< 1 , T >(0);
	}
}

template<class T>
Vector< 2 , T > Vector<1, T>::cross(const Vector< 2 , T >& other)
{
	return Vector< 2 , T >(-x * other.y, x * other.x);
}

template<class T>
Vector<1, T>& Vector<1, T>::operator= (const Vector<1, T>& other)
{
	x = other.x;
	return *this;
}

template<class T>
Vector<1, T>& Vector<1, T>::operator= (T value)
{
	x = value;
	return *this;
}

template<class T>
inline bool Vector<1, T>::operator< (const Vector<1, T>& other) const
{
	return x < other.x;
}

template<class T>
inline bool Vector<1, T>::operator> (const Vector<1, T>& other) const
{
	return x > other.x;
}

template<class T>
inline bool Vector<1, T>::operator> (double length) const
{
	return x > length;
}

template<class T>
inline bool Vector<1, T>::operator< (double length) const
{
	return x < length;
}

template<class T>
inline Vector<1, T>::operator T() const
{
	return x;
}

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
inline ostream& operator<< (ostream& out, Vector<1, T> vec)
{
	out << vec.x;
	return out;
}

template Vector<1, double> operator/ (const Vector<1, double>& vec, const double& divider);
template Vector<1, double> operator/ (const Vector<1, double>& vec1, const Vector<1, double>& vec2);
template Vector<1, double> operator* (const Vector<1, double>& vec, const double& multiplier);
template Vector<1, double> operator* (const double& multiplier, const Vector<1, double>& vec);
template Vector<1, double>& operator*= (Vector<1, double>& vec, const double& multiplier);
template Vector<1, double> operator+ (const Vector<1, double>& vec1, const Vector<1, double>& vec2);
template Vector<1, double> operator+ (const Vector<1, double>& vec1, double scalar);
template Vector<1, double>& operator+= (Vector<1, double>& vec1, const Vector<1, double>& vec2);
template Vector<1, double>& operator+= (Vector<1, double>& vec1, double scalar);
template Vector<1, double> operator- (const Vector<1, double>& vec1, const Vector<1, double>& vec2);
template Vector<1, double> operator- (const Vector<1, double>& vec1, double scalar);
template Vector<1, double>& operator-= (Vector<1, double>& vec1, const Vector<1, double>& vec2);
template Vector<1, double>& operator-= (Vector<1, double>& vec1, double scalar);
template Vector<1, double>& operator/= (Vector<1, double>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, double> vec);

template Vector<1, float> operator/ (const Vector<1, float>& vec, const double& divider);
template Vector<1, float> operator/ (const Vector<1, float>& vec1, const Vector<1, float>& vec2);
template Vector<1, float> operator* (const Vector<1, float>& vec, const double& multiplier);
template Vector<1, float> operator* (const double& multiplier, const Vector<1, float>& vec);
template Vector<1, float>& operator*= (Vector<1, float>& vec, const double& multiplier);
template Vector<1, float> operator+ (const Vector<1, float>& vec1, const Vector<1, float>& vec2);
template Vector<1, float> operator+ (const Vector<1, float>& vec1, float scalar);
template Vector<1, float>& operator+= (Vector<1, float>& vec1, const Vector<1, float>& vec2);
template Vector<1, float>& operator+= (Vector<1, float>& vec1, float scalar);
template Vector<1, float> operator- (const Vector<1, float>& vec1, const Vector<1, float>& vec2);
template Vector<1, float> operator- (const Vector<1, float>& vec1, float scalar);
template Vector<1, float>& operator-= (Vector<1, float>& vec1, const Vector<1, float>& vec2);
template Vector<1, float>& operator-= (Vector<1, float>& vec1, float scalar);
template Vector<1, float>& operator/= (Vector<1, float>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, float> vec);

template Vector<1, long double> operator/ (const Vector<1, long double>& vec, const double& divider);
template Vector<1, long double> operator/ (const Vector<1, long double>& vec1, const Vector<1, long double>& vec2);
template Vector<1, long double> operator* (const Vector<1, long double>& vec, const double& multiplier);
template Vector<1, long double> operator* (const double& multiplier, const Vector<1, long double>& vec);
template Vector<1, long double>& operator*= (Vector<1, long double>& vec, const double& multiplier);
template Vector<1, long double> operator+ (const Vector<1, long double>& vec1, const Vector<1, long double>& vec2);
template Vector<1, long double> operator+ (const Vector<1, long double>& vec1, long double scalar);
template Vector<1, long double>& operator+= (Vector<1, long double>& vec1, const Vector<1, long double>& vec2);
template Vector<1, long double>& operator+= (Vector<1, long double>& vec1, long double scalar);
template Vector<1, long double> operator- (const Vector<1, long double>& vec1, const Vector<1, long double>& vec2);
template Vector<1, long double> operator- (const Vector<1, long double>& vec1, long double scalar);
template Vector<1, long double>& operator-= (Vector<1, long double>& vec1, const Vector<1, long double>& vec2);
template Vector<1, long double>& operator-= (Vector<1, long double>& vec1, long double scalar);
template Vector<1, long double>& operator/= (Vector<1, long double>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, long double> vec);

template Vector<1, int> operator/ (const Vector<1, int>& vec, const double& divider);
template Vector<1, int> operator/ (const Vector<1, int>& vec1, const Vector<1, int>& vec2);
template Vector<1, int> operator* (const Vector<1, int>& vec, const double& multiplier);
template Vector<1, int> operator* (const double& multiplier, const Vector<1, int>& vec);
template Vector<1, int>& operator*= (Vector<1, int>& vec, const double& multiplier);
template Vector<1, int> operator+ (const Vector<1, int>& vec1, const Vector<1, int>& vec2);
template Vector<1, int> operator+ (const Vector<1, int>& vec1, int scalar);
template Vector<1, int>& operator+= (Vector<1, int>& vec1, const Vector<1, int>& vec2);
template Vector<1, int>& operator+= (Vector<1, int>& vec1, int scalar);
template Vector<1, int> operator- (const Vector<1, int>& vec1, const Vector<1, int>& vec2);
template Vector<1, int> operator- (const Vector<1, int>& vec1, int scalar);
template Vector<1, int>& operator-= (Vector<1, int>& vec1, const Vector<1, int>& vec2);
template Vector<1, int>& operator-= (Vector<1, int>& vec1, int scalar);
template Vector<1, int>& operator/= (Vector<1, int>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, int> vec);

template Vector<1, unsigned int> operator/ (const Vector<1, unsigned int>& vec, const double& divider);
template Vector<1, unsigned int> operator/ (const Vector<1, unsigned int>& vec1, const Vector<1, unsigned int>& vec2);
template Vector<1, unsigned int> operator* (const Vector<1, unsigned int>& vec, const double& multiplier);
template Vector<1, unsigned int> operator* (const double& multiplier, const Vector<1, unsigned int>& vec);
template Vector<1, unsigned int>& operator*= (Vector<1, unsigned int>& vec, const double& multiplier);
template Vector<1, unsigned int> operator+ (const Vector<1, unsigned int>& vec1, const Vector<1, unsigned int>& vec2);
template Vector<1, unsigned int> operator+ (const Vector<1, unsigned int>& vec1, unsigned int scalar);
template Vector<1, unsigned int>& operator+= (Vector<1, unsigned int>& vec1, const Vector<1, unsigned int>& vec2);
template Vector<1, unsigned int>& operator+= (Vector<1, unsigned int>& vec1, unsigned int scalar);
template Vector<1, unsigned int> operator- (const Vector<1, unsigned int>& vec1, const Vector<1, unsigned int>& vec2);
template Vector<1, unsigned int> operator- (const Vector<1, unsigned int>& vec1, unsigned int scalar);
template Vector<1, unsigned int>& operator-= (Vector<1, unsigned int>& vec1, const Vector<1, unsigned int>& vec2);
template Vector<1, unsigned int>& operator-= (Vector<1, unsigned int>& vec1, unsigned int scalar);
template Vector<1, unsigned int>& operator/= (Vector<1, unsigned int>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, unsigned int> vec);

template Vector<1, long> operator/ (const Vector<1, long>& vec, const double& divider);
template Vector<1, long> operator/ (const Vector<1, long>& vec1, const Vector<1, long>& vec2);
template Vector<1, long> operator* (const Vector<1, long>& vec, const double& multiplier);
template Vector<1, long> operator* (const double& multiplier, const Vector<1, long>& vec);
template Vector<1, long>& operator*= (Vector<1, long>& vec, const double& multiplier);
template Vector<1, long> operator+ (const Vector<1, long>& vec1, const Vector<1, long>& vec2);
template Vector<1, long> operator+ (const Vector<1, long>& vec1, long scalar);
template Vector<1, long>& operator+= (Vector<1, long>& vec1, const Vector<1, long>& vec2);
template Vector<1, long>& operator+= (Vector<1, long>& vec1, long scalar);
template Vector<1, long> operator- (const Vector<1, long>& vec1, const Vector<1, long>& vec2);
template Vector<1, long> operator- (const Vector<1, long>& vec1, long scalar);
template Vector<1, long>& operator-= (Vector<1, long>& vec1, const Vector<1, long>& vec2);
template Vector<1, long>& operator-= (Vector<1, long>& vec1, long scalar);
template Vector<1, long>& operator/= (Vector<1, long>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, long> vec);

template Vector<1, unsigned long> operator/ (const Vector<1, unsigned long>& vec, const double& divider);
template Vector<1, unsigned long> operator/ (const Vector<1, unsigned long>& vec1, const Vector<1, unsigned long>& vec2);
template Vector<1, unsigned long> operator* (const Vector<1, unsigned long>& vec, const double& multiplier);
template Vector<1, unsigned long> operator* (const double& multiplier, const Vector<1, unsigned long>& vec);
template Vector<1, unsigned long>& operator*= (Vector<1, unsigned long>& vec, const double& multiplier);
template Vector<1, unsigned long> operator+ (const Vector<1, unsigned long>& vec1, const Vector<1, unsigned long>& vec2);
template Vector<1, unsigned long> operator+ (const Vector<1, unsigned long>& vec1, unsigned long scalar);
template Vector<1, unsigned long>& operator+= (Vector<1, unsigned long>& vec1, const Vector<1, unsigned long>& vec2);
template Vector<1, unsigned long>& operator+= (Vector<1, unsigned long>& vec1, unsigned long scalar);
template Vector<1, unsigned long> operator- (const Vector<1, unsigned long>& vec1, const Vector<1, unsigned long>& vec2);
template Vector<1, unsigned long> operator- (const Vector<1, unsigned long>& vec1, unsigned long scalar);
template Vector<1, unsigned long>& operator-= (Vector<1, unsigned long>& vec1, const Vector<1, unsigned long>& vec2);
template Vector<1, unsigned long>& operator-= (Vector<1, unsigned long>& vec1, unsigned long scalar);
template Vector<1, unsigned long>& operator/= (Vector<1, unsigned long>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, unsigned long> vec);

template Vector<1, short> operator/ (const Vector<1, short>& vec, const double& divider);
template Vector<1, short> operator/ (const Vector<1, short>& vec1, const Vector<1, short>& vec2);
template Vector<1, short> operator* (const Vector<1, short>& vec, const double& multiplier);
template Vector<1, short> operator* (const double& multiplier, const Vector<1, short>& vec);
template Vector<1, short>& operator*= (Vector<1, short>& vec, const double& multiplier);
template Vector<1, short> operator+ (const Vector<1, short>& vec1, const Vector<1, short>& vec2);
template Vector<1, short> operator+ (const Vector<1, short>& vec1, short scalar);
template Vector<1, short>& operator+= (Vector<1, short>& vec1, const Vector<1, short>& vec2);
template Vector<1, short>& operator+= (Vector<1, short>& vec1, short scalar);
template Vector<1, short> operator- (const Vector<1, short>& vec1, const Vector<1, short>& vec2);
template Vector<1, short> operator- (const Vector<1, short>& vec1, short scalar);
template Vector<1, short>& operator-= (Vector<1, short>& vec1, const Vector<1, short>& vec2);
template Vector<1, short>& operator-= (Vector<1, short>& vec1, short scalar);
template Vector<1, short>& operator/= (Vector<1, short>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, short> vec);

template Vector<1, unsigned short> operator/ (const Vector<1, unsigned short>& vec, const double& divider);
template Vector<1, unsigned short> operator/ (const Vector<1, unsigned short>& vec1, const Vector<1, unsigned short>& vec2);
template Vector<1, unsigned short> operator* (const Vector<1, unsigned short>& vec, const double& multiplier);
template Vector<1, unsigned short> operator* (const double& multiplier, const Vector<1, unsigned short>& vec);
template Vector<1, unsigned short>& operator*= (Vector<1, unsigned short>& vec, const double& multiplier);
template Vector<1, unsigned short> operator+ (const Vector<1, unsigned short>& vec1, const Vector<1, unsigned short>& vec2);
template Vector<1, unsigned short> operator+ (const Vector<1, unsigned short>& vec1, unsigned short scalar);
template Vector<1, unsigned short>& operator+= (Vector<1, unsigned short>& vec1, const Vector<1, unsigned short>& vec2);
template Vector<1, unsigned short>& operator+= (Vector<1, unsigned short>& vec1, unsigned short scalar);
template Vector<1, unsigned short> operator- (const Vector<1, unsigned short>& vec1, const Vector<1, unsigned short>& vec2);
template Vector<1, unsigned short> operator- (const Vector<1, unsigned short>& vec1, unsigned short scalar);
template Vector<1, unsigned short>& operator-= (Vector<1, unsigned short>& vec1, const Vector<1, unsigned short>& vec2);
template Vector<1, unsigned short>& operator-= (Vector<1, unsigned short>& vec1, unsigned short scalar);
template Vector<1, unsigned short>& operator/= (Vector<1, unsigned short>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, unsigned short> vec);

template Vector<1, char> operator/ (const Vector<1, char>& vec, const double& divider);
template Vector<1, char> operator/ (const Vector<1, char>& vec1, const Vector<1, char>& vec2);
template Vector<1, char> operator* (const Vector<1, char>& vec, const double& multiplier);
template Vector<1, char> operator* (const double& multiplier, const Vector<1, char>& vec);
template Vector<1, char>& operator*= (Vector<1, char>& vec, const double& multiplier);
template Vector<1, char> operator+ (const Vector<1, char>& vec1, const Vector<1, char>& vec2);
template Vector<1, char> operator+ (const Vector<1, char>& vec1, char scalar);
template Vector<1, char>& operator+= (Vector<1, char>& vec1, const Vector<1, char>& vec2);
template Vector<1, char>& operator+= (Vector<1, char>& vec1, char scalar);
template Vector<1, char> operator- (const Vector<1, char>& vec1, const Vector<1, char>& vec2);
template Vector<1, char> operator- (const Vector<1, char>& vec1, char scalar);
template Vector<1, char>& operator-= (Vector<1, char>& vec1, const Vector<1, char>& vec2);
template Vector<1, char>& operator-= (Vector<1, char>& vec1, char scalar);
template Vector<1, char>& operator/= (Vector<1, char>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, char> vec);

template Vector<1, unsigned char> operator/ (const Vector<1, unsigned char>& vec, const double& divider);
template Vector<1, unsigned char> operator/ (const Vector<1, unsigned char>& vec1, const Vector<1, unsigned char>& vec2);
template Vector<1, unsigned char> operator* (const Vector<1, unsigned char>& vec, const double& multiplier);
template Vector<1, unsigned char> operator* (const double& multiplier, const Vector<1, unsigned char>& vec);
template Vector<1, unsigned char>& operator*= (Vector<1, unsigned char>& vec, const double& multiplier);
template Vector<1, unsigned char> operator+ (const Vector<1, unsigned char>& vec1, const Vector<1, unsigned char>& vec2);
template Vector<1, unsigned char> operator+ (const Vector<1, unsigned char>& vec1, unsigned char scalar);
template Vector<1, unsigned char>& operator+= (Vector<1, unsigned char>& vec1, const Vector<1, unsigned char>& vec2);
template Vector<1, unsigned char>& operator+= (Vector<1, unsigned char>& vec1, unsigned char scalar);
template Vector<1, unsigned char> operator- (const Vector<1, unsigned char>& vec1, const Vector<1, unsigned char>& vec2);
template Vector<1, unsigned char> operator- (const Vector<1, unsigned char>& vec1, unsigned char scalar);
template Vector<1, unsigned char>& operator-= (Vector<1, unsigned char>& vec1, const Vector<1, unsigned char>& vec2);
template Vector<1, unsigned char>& operator-= (Vector<1, unsigned char>& vec1, unsigned char scalar);
template Vector<1, unsigned char>& operator/= (Vector<1, unsigned char>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<1, unsigned char> vec);

template class Vector<1, float>;
template class Vector<1, double>;
template class Vector<1, long double>;
template class Vector<1, int>;
template class Vector<1, unsigned int>;
template class Vector<1, long>;
template class Vector<1, unsigned long>;
template class Vector<1, short>;
template class Vector<1, unsigned short>;
template class Vector<1, char>;
template class Vector<1, unsigned char>;

}