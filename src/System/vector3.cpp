#include "vector3.h"

#include "vector2.h"

using namespace std;

namespace sbg {

template<class T>
Vector<3, T>::Vector() : x(0), y(0), z(0)
{}

template<class T>
Vector<3, T>::Vector(T value) : x(value), y(value), z(value)
{}

template<class T>
Vector<3, T>::Vector(T _x, T _y, T _z) : x(_x), y(_y), z(_z)
{}

template<class T>
Vector<3, T>::Vector(const Vector<3, T> &other) : x(other.x), y(other.y), z(other.z)
{}

template<class T>
Vector<2, double> Vector<3, T>::getAngle() const
{
	return Vector<2, double>(atan(y / x), acos(z / getLength()));
}

template<class T>
double Vector<3, T>::getLength() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}

template<class T>
void Vector<3, T>::setAngle(const Vector<3, double> angles)
{
	if (notZero()) {
		double lenght = getLength();
		x = sin(angles.y) * cos(angles.x) * lenght;
		y = sin(angles.x) * sin(angles.y) * lenght;
		z = cos(angles.y) * lenght;
	}
}

template<class T>
void Vector<3, T>::setLenght(double lenght)
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

template<class T>
Vector<3, T> Vector<3, T>::project(Vector<3, T> other) const
{
	return (this->dot(other.unit())) * other;
}

template<class T>
bool Vector<3, T>::notZero() const
{
	return x != 0 || y != 0 || z != 0;
}

template<class T>
Vector<3, T> Vector<3, T>::unit() const
{
	if (notZero()) {
		double lenght = getLength();

		return Vector<3, T>(x / lenght, y / lenght, z / lenght);
	} else {
		return Vector< 3 , T >(0, 0, 0);
	}
}

template<class T>
Vector<3, T> Vector<3, T>::cross(Vector<3, T> &other) const
{
	return Vector< 3 , T >(y * other.z - z * other.y, -1 * x * other.z + z * other.x, x * other.y - y * other.x);
}

template<class T>
double Vector<3, T>::dot(const Vector<3, T> &vec) const
{
	return (x * vec.x) + (y * vec.y) + (z * vec.z);
}

//Operators

template<class T>
Vector<3, T>& Vector<3, T>::operator= (const Vector<3, T> &other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

template<class T>
bool Vector<3, T>::operator== (const Vector<3, T>& other) const
{
	return x == other.x && y == other.y && z == other.z;
}

template<class T>
bool Vector<3, T>::operator!= (const Vector<3, T>& other) const
{
	return !(*this == other);
}

template<class T>
bool Vector<3, T>::operator< (const Vector<3, T> &other) const
{
	return ((x * x) + (y * y) + (z * z)) < ((other.x * other.x) + (other.y * other.y) + (other.z * other.z));
}

template<class T>
bool Vector<3, T>::operator> (const Vector<3, T> &other) const
{
	return ((x * x) + (y * y) + (z * z)) > ((other.x * other.x) + (other.y * other.y) + (other.z * other.z));
}

template<class T>
bool Vector<3, T>::operator> (double length) const
{
	return ((x * x) + (y * y) + (z * z)) > (length * length);
}

template<class T>
bool Vector<3, T>::operator< (double length) const
{
	return ((x * x) + (y * y) + (z * z)) < (length * length);
}

template<class T>
Vector<3, T> operator/ (const Vector<3, T> &vec, const double &divider)
{
	return Vector<3, T>(vec.x / divider, vec.y / divider, vec.z / divider);
}

template<class T>
Vector<3, T> operator* (const Vector<3, T> &vec, const double &multiplier)
{
	return Vector<3, T>(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier);
}

template<class T>
Vector<3, T> operator* (const double &multiplier, const Vector<3, T> &vec)
{
	return Vector<3, T>(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier);
}

template<class T>
Vector<3, T> &operator*= (Vector<3, T> &vec, const double &multiplier)
{
	vec.x *= multiplier;
	vec.y *= multiplier;
	vec.z *= multiplier;
	return vec;
}

template<class T>
Vector<3, T> operator+ (const Vector<3, T> &vec1, const Vector<3, T> &vec2)
{
	return Vector<3, T>(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
}

template<class T>
Vector<3, T> &operator+= (Vector<3, T> &vec1, const Vector<3, T> &vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	return vec1;
}

template<class T>
Vector<3, T> operator- (const Vector<3, T> &vec1, const Vector<3, T> &vec2)
{
	return Vector<3, T>(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}

template<class T>
Vector<3, T> &operator-= (Vector<3, T> &vec1, const Vector<3, T> &vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	return vec1;
}

template<class T>
Vector<3, T> &operator/= (Vector<3, T> &vec, const double &divider)
{
	vec.x /= divider;
	vec.y /= divider;
	vec.z /= divider;
	return vec;
}

template<class T>
Vector<3, T> operator- (const Vector<3, T> &vec)
{
	return Vector<3, T>(-vec.x, -vec.y, -vec.z);
}

template<class T>
ostream &operator<< (ostream &out, Vector<3, T> vec)
{
	out << vec.x << ", " << vec.y << ", " << vec.z;
	return out;
}

template Vector<3, float> operator/ (const Vector<3, float>& vec, const double& divider);
template Vector<3, float> operator* (const Vector<3, float>& vec, const double& multiplier);
template Vector<3, float> operator* (const double& multiplier, const Vector<3, float>& vec);
template Vector<3, float>& operator*= (Vector<3, float>& vec, const double& multiplier);
template Vector<3, float> operator+ (const Vector<3, float>& vec1, const Vector<3, float>& vec2);
template Vector<3, float>& operator+= (Vector<3, float>& vec1, const Vector<3, float>& vec2);
template Vector<3, float> operator- (const Vector<3, float>& vec1, const Vector<3, float>& vec2);
template Vector<3, float>& operator-= (Vector<3, float>& vec1, const Vector<3, float>& vec2);
template Vector<3, float>& operator/= (Vector<3, float>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, float> vec);

template Vector<3, double> operator/ (const Vector<3, double>& vec, const double& divider);
template Vector<3, double> operator* (const Vector<3, double>& vec, const double& multiplier);
template Vector<3, double> operator* (const double& multiplier, const Vector<3, double>& vec);
template Vector<3, double>& operator*= (Vector<3, double>& vec, const double& multiplier);
template Vector<3, double> operator+ (const Vector<3, double>& vec1, const Vector<3, double>& vec2);
template Vector<3, double>& operator+= (Vector<3, double>& vec1, const Vector<3, double>& vec2);
template Vector<3, double> operator- (const Vector<3, double>& vec1, const Vector<3, double>& vec2);
template Vector<3, double>& operator-= (Vector<3, double>& vec1, const Vector<3, double>& vec2);
template Vector<3, double>& operator/= (Vector<3, double>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, double> vec);

template Vector<3, long double> operator/ (const Vector<3, long double>& vec, const double& divider);
template Vector<3, long double> operator* (const Vector<3, long double>& vec, const double& multiplier);
template Vector<3, long double> operator* (const double& multiplier, const Vector<3, long double>& vec);
template Vector<3, long double>& operator*= (Vector<3, long double>& vec, const double& multiplier);
template Vector<3, long double> operator+ (const Vector<3, long double>& vec1, const Vector<3, long double>& vec2);
template Vector<3, long double>& operator+= (Vector<3, long double>& vec1, const Vector<3, long double>& vec2);
template Vector<3, long double> operator- (const Vector<3, long double>& vec1, const Vector<3, long double>& vec2);
template Vector<3, long double>& operator-= (Vector<3, long double>& vec1, const Vector<3, long double>& vec2);
template Vector<3, long double>& operator/= (Vector<3, long double>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, long double> vec);

template Vector<3, int> operator/ (const Vector<3, int>& vec, const double& divider);
template Vector<3, int> operator* (const Vector<3, int>& vec, const double& multiplier);
template Vector<3, int> operator* (const double& multiplier, const Vector<3, int>& vec);
template Vector<3, int>& operator*= (Vector<3, int>& vec, const double& multiplier);
template Vector<3, int> operator+ (const Vector<3, int>& vec1, const Vector<3, int>& vec2);
template Vector<3, int>& operator+= (Vector<3, int>& vec1, const Vector<3, int>& vec2);
template Vector<3, int> operator- (const Vector<3, int>& vec1, const Vector<3, int>& vec2);
template Vector<3, int>& operator-= (Vector<3, int>& vec1, const Vector<3, int>& vec2);
template Vector<3, int>& operator/= (Vector<3, int>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, int> vec);

template Vector<3, unsigned int> operator/ (const Vector<3, unsigned int>& vec, const double& divider);
template Vector<3, unsigned int> operator* (const Vector<3, unsigned int>& vec, const double& multiplier);
template Vector<3, unsigned int> operator* (const double& multiplier, const Vector<3, unsigned int>& vec);
template Vector<3, unsigned int>& operator*= (Vector<3, unsigned int>& vec, const double& multiplier);
template Vector<3, unsigned int> operator+ (const Vector<3, unsigned int>& vec1, const Vector<3, unsigned int>& vec2);
template Vector<3, unsigned int>& operator+= (Vector<3, unsigned int>& vec1, const Vector<3, unsigned int>& vec2);
template Vector<3, unsigned int> operator- (const Vector<3, unsigned int>& vec1, const Vector<3, unsigned int>& vec2);
template Vector<3, unsigned int>& operator-= (Vector<3, unsigned int>& vec1, const Vector<3, unsigned int>& vec2);
template Vector<3, unsigned int>& operator/= (Vector<3, unsigned int>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, unsigned int> vec);

template Vector<3, long> operator/ (const Vector<3, long>& vec, const double& divider);
template Vector<3, long> operator* (const Vector<3, long>& vec, const double& multiplier);
template Vector<3, long> operator* (const double& multiplier, const Vector<3, long>& vec);
template Vector<3, long>& operator*= (Vector<3, long>& vec, const double& multiplier);
template Vector<3, long> operator+ (const Vector<3, long>& vec1, const Vector<3, long>& vec2);
template Vector<3, long>& operator+= (Vector<3, long>& vec1, const Vector<3, long>& vec2);
template Vector<3, long> operator- (const Vector<3, long>& vec1, const Vector<3, long>& vec2);
template Vector<3, long>& operator-= (Vector<3, long>& vec1, const Vector<3, long>& vec2);
template Vector<3, long>& operator/= (Vector<3, long>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, long> vec);

template Vector<3, unsigned long> operator/ (const Vector<3, unsigned long>& vec, const double& divider);
template Vector<3, unsigned long> operator* (const Vector<3, unsigned long>& vec, const double& multiplier);
template Vector<3, unsigned long> operator* (const double& multiplier, const Vector<3, unsigned long>& vec);
template Vector<3, unsigned long>& operator*= (Vector<3, unsigned long>& vec, const double& multiplier);
template Vector<3, unsigned long> operator+ (const Vector<3, unsigned long>& vec1, const Vector<3, unsigned long>& vec2);
template Vector<3, unsigned long>& operator+= (Vector<3, unsigned long>& vec1, const Vector<3, unsigned long>& vec2);
template Vector<3, unsigned long> operator- (const Vector<3, unsigned long>& vec1, const Vector<3, unsigned long>& vec2);
template Vector<3, unsigned long>& operator-= (Vector<3, unsigned long>& vec1, const Vector<3, unsigned long>& vec2);
template Vector<3, unsigned long>& operator/= (Vector<3, unsigned long>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, unsigned long> vec);

template Vector<3, short> operator/ (const Vector<3, short>& vec, const double& divider);
template Vector<3, short> operator* (const Vector<3, short>& vec, const double& multiplier);
template Vector<3, short> operator* (const double& multiplier, const Vector<3, short>& vec);
template Vector<3, short>& operator*= (Vector<3, short>& vec, const double& multiplier);
template Vector<3, short> operator+ (const Vector<3, short>& vec1, const Vector<3, short>& vec2);
template Vector<3, short>& operator+= (Vector<3, short>& vec1, const Vector<3, short>& vec2);
template Vector<3, short> operator- (const Vector<3, short>& vec1, const Vector<3, short>& vec2);
template Vector<3, short>& operator-= (Vector<3, short>& vec1, const Vector<3, short>& vec2);
template Vector<3, short>& operator/= (Vector<3, short>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, short> vec);

template Vector<3, unsigned short> operator/ (const Vector<3, unsigned short>& vec, const double& divider);
template Vector<3, unsigned short> operator* (const Vector<3, unsigned short>& vec, const double& multiplier);
template Vector<3, unsigned short> operator* (const double& multiplier, const Vector<3, unsigned short>& vec);
template Vector<3, unsigned short>& operator*= (Vector<3, unsigned short>& vec, const double& multiplier);
template Vector<3, unsigned short> operator+ (const Vector<3, unsigned short>& vec1, const Vector<3, unsigned short>& vec2);
template Vector<3, unsigned short>& operator+= (Vector<3, unsigned short>& vec1, const Vector<3, unsigned short>& vec2);
template Vector<3, unsigned short> operator- (const Vector<3, unsigned short>& vec1, const Vector<3, unsigned short>& vec2);
template Vector<3, unsigned short>& operator-= (Vector<3, unsigned short>& vec1, const Vector<3, unsigned short>& vec2);
template Vector<3, unsigned short>& operator/= (Vector<3, unsigned short>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, unsigned short> vec);

template Vector<3, char> operator/ (const Vector<3, char>& vec, const double& divider);
template Vector<3, char> operator* (const Vector<3, char>& vec, const double& multiplier);
template Vector<3, char> operator* (const double& multiplier, const Vector<3, char>& vec);
template Vector<3, char>& operator*= (Vector<3, char>& vec, const double& multiplier);
template Vector<3, char> operator+ (const Vector<3, char>& vec1, const Vector<3, char>& vec2);
template Vector<3, char>& operator+= (Vector<3, char>& vec1, const Vector<3, char>& vec2);
template Vector<3, char> operator- (const Vector<3, char>& vec1, const Vector<3, char>& vec2);
template Vector<3, char>& operator-= (Vector<3, char>& vec1, const Vector<3, char>& vec2);
template Vector<3, char>& operator/= (Vector<3, char>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, char> vec);

template Vector<3, unsigned char> operator/ (const Vector<3, unsigned char>& vec, const double& divider);
template Vector<3, unsigned char> operator* (const Vector<3, unsigned char>& vec, const double& multiplier);
template Vector<3, unsigned char> operator* (const double& multiplier, const Vector<3, unsigned char>& vec);
template Vector<3, unsigned char>& operator*= (Vector<3, unsigned char>& vec, const double& multiplier);
template Vector<3, unsigned char> operator+ (const Vector<3, unsigned char>& vec1, const Vector<3, unsigned char>& vec2);
template Vector<3, unsigned char>& operator+= (Vector<3, unsigned char>& vec1, const Vector<3, unsigned char>& vec2);
template Vector<3, unsigned char> operator- (const Vector<3, unsigned char>& vec1, const Vector<3, unsigned char>& vec2);
template Vector<3, unsigned char>& operator-= (Vector<3, unsigned char>& vec1, const Vector<3, unsigned char>& vec2);
template Vector<3, unsigned char>& operator/= (Vector<3, unsigned char>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<3, unsigned char> vec);

template class Vector<3, float>;
template class Vector<3, double>;
template class Vector<3, long double>;
template class Vector<3, int>;
template class Vector<3, unsigned int>;
template class Vector<3, long>;
template class Vector<3, unsigned long>;
template class Vector<3, short>;
template class Vector<3, unsigned short>;
template class Vector<3, char>;
template class Vector<3, unsigned char>;

}
