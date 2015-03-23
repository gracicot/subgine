#include "vector4.h"

#include <ostream>
#include <cmath>

using namespace std;

namespace sbg {

template<class T>
Vector<4, T>::Vector() : x(0), y(0), z(0), w(0)
{}

template<class T>
Vector<4, T>::Vector(T value) : x(value), y(value), z(value), w(value)
{}

template<class T>
Vector<4, T>::Vector(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w)
{}

template<class T>
Vector<4, T>::Vector(const Vector<4, T>& other) : x(other.x), y(other.y), z(other.z), w(other.w)
{}

template<class T>
double Vector<4, T>::getLength() const
{
	return sqrt((x*x) + (y*y) + (z*z) + (w*w));
}

template<class T>
void Vector<4, T>::setLenght(double lenght)
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

template<class T>
Vector<4, T> Vector<4, T>::project(Vector<4, T> other) const
{
	return (this->dot(other.unit())) * other;
}

template<class T>
bool Vector<4, T>::notZero() const
{
	return x != 0 || y != 0 || z != 0 || w != 0;
}

template<class T>
Vector<4, T> Vector<4, T>::unit() const
{
	if (notZero()) {
		double lenght = getLength();
		
		return Vector<4, T>(x / lenght, y / lenght,  z / lenght,  w / lenght);
	} else {
		return Vector< 4 , T >(0, 0, 0, 0);
	}
}

template<class T>
double Vector<4, T>::dot(const Vector<4, T>& vec) const
{
	return (x * vec.x) + (y * vec.y) + (z * vec.z) + (w * vec.w);
}

template<class T>
Vector<4, T>& Vector<4, T>::operator= (const Vector<4, T>& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return *this;
}

template<class T>
bool Vector<4, T>::operator== (const Vector<4, T>& other) const
{
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

template<class T>
bool Vector<4, T>::operator!= (const Vector<4, T>& other) const
{
	return !(*this == other);
}

template<class T>
bool Vector<4, T>::operator< (const Vector<4, T> &other) const
{
	return ((x * x) + (y * y) + (z * z) + (w * w)) < ((other.x * other.x) + (other.y * other.y) + (other.z * other.z) + (other.w * other.w));
}

template<class T>
bool Vector<4, T>::operator> (const Vector<4, T> &other) const
{
	return ((x * x) + (y * y) + (z * z) + (w * w)) > ((other.x * other.x) + (other.y * other.y) + (other.z * other.z) + (other.w * other.w));
}

template<class T>
bool Vector<4, T>::operator> (double length) const
{
	return ((x * x) + (y * y) + (z * z) + (w * w)) > (length * length);
}

template<class T>
bool Vector<4, T>::operator< (double length) const
{
	return ((x * x) + (y * y) + (z * z) + (w * w)) < (length * length);
}

template<class T>
Vector<4, T> operator/ (const Vector<4, T>& vec, const double& divider)
{
	return Vector<4, T>(vec.x / divider, vec.y / divider, vec.z / divider, vec.w / divider);
}

template<class T>
Vector<4, T> operator/ (const Vector<4, T>& vec1, const Vector<4, T>& vec2)
{
	return Vector<4, T>(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z, vec1.w / vec2.w);
}

template<class T>
Vector<4, T> operator* (const Vector<4, T>& vec, const double& multiplier)
{
	return Vector<4, T>(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier, vec.w * multiplier);
}

template<class T>
Vector<4, T> operator* (const double& multiplier, const Vector<4, T>& vec)
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
Vector<4, T> operator+ (const Vector<4, T>& vec1, const Vector<4, T>& vec2)
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
Vector<4, T> operator- (const Vector<4, T>& vec1, const Vector<4, T>& vec2)
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
Vector<4, T>& operator/= (Vector<4, T>& vec, const double& divider)
{
	vec.x /= divider;
	vec.y /= divider;
	vec.z /= divider;
	vec.w /= divider;
	return vec;
}

template<class T>
ostream& operator<< (ostream& out, Vector<4, T> vec)
{
	out << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
	return out;
}

template Vector<4, float> operator/ (const Vector<4, float>& vec, const double& divider);
template Vector<4, float> operator* (const Vector<4, float>& vec, const double& multiplier);
template Vector<4, float> operator* (const double& multiplier, const Vector<4, float>& vec);
template Vector<4, float>& operator*= (Vector<4, float>& vec, const double& multiplier);
template Vector<4, float> operator+ (const Vector<4, float>& vec1, const Vector<4, float>& vec2);
template Vector<4, float>& operator+= (Vector<4, float>& vec1, const Vector<4, float>& vec2);
template Vector<4, float> operator- (const Vector<4, float>& vec1, const Vector<4, float>& vec2);
template Vector<4, float>& operator-= (Vector<4, float>& vec1, const Vector<4, float>& vec2);
template Vector<4, float>& operator/= (Vector<4, float>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, float> vec);

template Vector<4, double> operator/ (const Vector<4, double>& vec, const double& divider);
template Vector<4, double> operator* (const Vector<4, double>& vec, const double& multiplier);
template Vector<4, double> operator* (const double& multiplier, const Vector<4, double>& vec);
template Vector<4, double>& operator*= (Vector<4, double>& vec, const double& multiplier);
template Vector<4, double> operator+ (const Vector<4, double>& vec1, const Vector<4, double>& vec2);
template Vector<4, double>& operator+= (Vector<4, double>& vec1, const Vector<4, double>& vec2);
template Vector<4, double> operator- (const Vector<4, double>& vec1, const Vector<4, double>& vec2);
template Vector<4, double>& operator-= (Vector<4, double>& vec1, const Vector<4, double>& vec2);
template Vector<4, double>& operator/= (Vector<4, double>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, double> vec);

template Vector<4, long double> operator/ (const Vector<4, long double>& vec, const double& divider);
template Vector<4, long double> operator* (const Vector<4, long double>& vec, const double& multiplier);
template Vector<4, long double> operator* (const double& multiplier, const Vector<4, long double>& vec);
template Vector<4, long double>& operator*= (Vector<4, long double>& vec, const double& multiplier);
template Vector<4, long double> operator+ (const Vector<4, long double>& vec1, const Vector<4, long double>& vec2);
template Vector<4, long double>& operator+= (Vector<4, long double>& vec1, const Vector<4, long double>& vec2);
template Vector<4, long double> operator- (const Vector<4, long double>& vec1, const Vector<4, long double>& vec2);
template Vector<4, long double>& operator-= (Vector<4, long double>& vec1, const Vector<4, long double>& vec2);
template Vector<4, long double>& operator/= (Vector<4, long double>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, long double> vec);

template Vector<4, int> operator/ (const Vector<4, int>& vec, const double& divider);
template Vector<4, int> operator* (const Vector<4, int>& vec, const double& multiplier);
template Vector<4, int> operator* (const double& multiplier, const Vector<4, int>& vec);
template Vector<4, int>& operator*= (Vector<4, int>& vec, const double& multiplier);
template Vector<4, int> operator+ (const Vector<4, int>& vec1, const Vector<4, int>& vec2);
template Vector<4, int>& operator+= (Vector<4, int>& vec1, const Vector<4, int>& vec2);
template Vector<4, int> operator- (const Vector<4, int>& vec1, const Vector<4, int>& vec2);
template Vector<4, int>& operator-= (Vector<4, int>& vec1, const Vector<4, int>& vec2);
template Vector<4, int>& operator/= (Vector<4, int>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, int> vec);

template Vector<4, unsigned int> operator/ (const Vector<4, unsigned int>& vec, const double& divider);
template Vector<4, unsigned int> operator* (const Vector<4, unsigned int>& vec, const double& multiplier);
template Vector<4, unsigned int> operator* (const double& multiplier, const Vector<4, unsigned int>& vec);
template Vector<4, unsigned int>& operator*= (Vector<4, unsigned int>& vec, const double& multiplier);
template Vector<4, unsigned int> operator+ (const Vector<4, unsigned int>& vec1, const Vector<4, unsigned int>& vec2);
template Vector<4, unsigned int>& operator+= (Vector<4, unsigned int>& vec1, const Vector<4, unsigned int>& vec2);
template Vector<4, unsigned int> operator- (const Vector<4, unsigned int>& vec1, const Vector<4, unsigned int>& vec2);
template Vector<4, unsigned int>& operator-= (Vector<4, unsigned int>& vec1, const Vector<4, unsigned int>& vec2);
template Vector<4, unsigned int>& operator/= (Vector<4, unsigned int>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, unsigned int> vec);

template Vector<4, long> operator/ (const Vector<4, long>& vec, const double& divider);
template Vector<4, long> operator* (const Vector<4, long>& vec, const double& multiplier);
template Vector<4, long> operator* (const double& multiplier, const Vector<4, long>& vec);
template Vector<4, long>& operator*= (Vector<4, long>& vec, const double& multiplier);
template Vector<4, long> operator+ (const Vector<4, long>& vec1, const Vector<4, long>& vec2);
template Vector<4, long>& operator+= (Vector<4, long>& vec1, const Vector<4, long>& vec2);
template Vector<4, long> operator- (const Vector<4, long>& vec1, const Vector<4, long>& vec2);
template Vector<4, long>& operator-= (Vector<4, long>& vec1, const Vector<4, long>& vec2);
template Vector<4, long>& operator/= (Vector<4, long>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, long> vec);

template Vector<4, unsigned long> operator/ (const Vector<4, unsigned long>& vec, const double& divider);
template Vector<4, unsigned long> operator* (const Vector<4, unsigned long>& vec, const double& multiplier);
template Vector<4, unsigned long> operator* (const double& multiplier, const Vector<4, unsigned long>& vec);
template Vector<4, unsigned long>& operator*= (Vector<4, unsigned long>& vec, const double& multiplier);
template Vector<4, unsigned long> operator+ (const Vector<4, unsigned long>& vec1, const Vector<4, unsigned long>& vec2);
template Vector<4, unsigned long>& operator+= (Vector<4, unsigned long>& vec1, const Vector<4, unsigned long>& vec2);
template Vector<4, unsigned long> operator- (const Vector<4, unsigned long>& vec1, const Vector<4, unsigned long>& vec2);
template Vector<4, unsigned long>& operator-= (Vector<4, unsigned long>& vec1, const Vector<4, unsigned long>& vec2);
template Vector<4, unsigned long>& operator/= (Vector<4, unsigned long>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, unsigned long> vec);

template Vector<4, short> operator/ (const Vector<4, short>& vec, const double& divider);
template Vector<4, short> operator* (const Vector<4, short>& vec, const double& multiplier);
template Vector<4, short> operator* (const double& multiplier, const Vector<4, short>& vec);
template Vector<4, short>& operator*= (Vector<4, short>& vec, const double& multiplier);
template Vector<4, short> operator+ (const Vector<4, short>& vec1, const Vector<4, short>& vec2);
template Vector<4, short>& operator+= (Vector<4, short>& vec1, const Vector<4, short>& vec2);
template Vector<4, short> operator- (const Vector<4, short>& vec1, const Vector<4, short>& vec2);
template Vector<4, short>& operator-= (Vector<4, short>& vec1, const Vector<4, short>& vec2);
template Vector<4, short>& operator/= (Vector<4, short>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, short> vec);

template Vector<4, unsigned short> operator/ (const Vector<4, unsigned short>& vec, const double& divider);
template Vector<4, unsigned short> operator* (const Vector<4, unsigned short>& vec, const double& multiplier);
template Vector<4, unsigned short> operator* (const double& multiplier, const Vector<4, unsigned short>& vec);
template Vector<4, unsigned short>& operator*= (Vector<4, unsigned short>& vec, const double& multiplier);
template Vector<4, unsigned short> operator+ (const Vector<4, unsigned short>& vec1, const Vector<4, unsigned short>& vec2);
template Vector<4, unsigned short>& operator+= (Vector<4, unsigned short>& vec1, const Vector<4, unsigned short>& vec2);
template Vector<4, unsigned short> operator- (const Vector<4, unsigned short>& vec1, const Vector<4, unsigned short>& vec2);
template Vector<4, unsigned short>& operator-= (Vector<4, unsigned short>& vec1, const Vector<4, unsigned short>& vec2);
template Vector<4, unsigned short>& operator/= (Vector<4, unsigned short>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, unsigned short> vec);

template Vector<4, char> operator/ (const Vector<4, char>& vec, const double& divider);
template Vector<4, char> operator* (const Vector<4, char>& vec, const double& multiplier);
template Vector<4, char> operator* (const double& multiplier, const Vector<4, char>& vec);
template Vector<4, char>& operator*= (Vector<4, char>& vec, const double& multiplier);
template Vector<4, char> operator+ (const Vector<4, char>& vec1, const Vector<4, char>& vec2);
template Vector<4, char>& operator+= (Vector<4, char>& vec1, const Vector<4, char>& vec2);
template Vector<4, char> operator- (const Vector<4, char>& vec1, const Vector<4, char>& vec2);
template Vector<4, char>& operator-= (Vector<4, char>& vec1, const Vector<4, char>& vec2);
template Vector<4, char>& operator/= (Vector<4, char>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, char> vec);

template Vector<4, unsigned char> operator/ (const Vector<4, unsigned char>& vec, const double& divider);
template Vector<4, unsigned char> operator* (const Vector<4, unsigned char>& vec, const double& multiplier);
template Vector<4, unsigned char> operator* (const double& multiplier, const Vector<4, unsigned char>& vec);
template Vector<4, unsigned char>& operator*= (Vector<4, unsigned char>& vec, const double& multiplier);
template Vector<4, unsigned char> operator+ (const Vector<4, unsigned char>& vec1, const Vector<4, unsigned char>& vec2);
template Vector<4, unsigned char>& operator+= (Vector<4, unsigned char>& vec1, const Vector<4, unsigned char>& vec2);
template Vector<4, unsigned char> operator- (const Vector<4, unsigned char>& vec1, const Vector<4, unsigned char>& vec2);
template Vector<4, unsigned char>& operator-= (Vector<4, unsigned char>& vec1, const Vector<4, unsigned char>& vec2);
template Vector<4, unsigned char>& operator/= (Vector<4, unsigned char>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<4, unsigned char> vec);

template class Vector<4, float>;
template class Vector<4, double>;
template class Vector<4, long double>;
template class Vector<4, int>;
template class Vector<4, unsigned int>;
template class Vector<4, long>;
template class Vector<4, unsigned long>;
template class Vector<4, short>;
template class Vector<4, unsigned short>;
template class Vector<4, char>;
template class Vector<4, unsigned char>;

}
