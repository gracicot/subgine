#include "vector2.h"

#include "vector1.h"

using namespace std;

namespace sbg {

template<class T>
Vector<2, T>::Vector() : x(0), y(0)
{}

template<class T>
Vector<2, T>::Vector(T value) : x(value), y(value)
{}

template<class T>
Vector<2, T>::Vector(T _x, T _y) : x(_x), y(_y)
{}

template<class T>
double Vector<2, T>::getAngle() const
{
	double angle = atan2(y, x);

	if (angle < 0) {
		angle += tau;
	}

	return angle;
}

template<class T>
double Vector<2, T>::getLength() const
{
	return sqrt((x * x) + (y * y));
}

template<class T>
void Vector<2, T>::setAngle(double angle)
{
	if (notZero()) {
		double lenght = getLength();
		x = cos(angle) * lenght;
		y = sin(angle) * lenght;
	}
}

template<class T>
void Vector<2, T>::setLenght(double lenght)
{
	if (notZero()) {
		double product = lenght / getLength();
		x *= product;
		y *= product;
	} else {
		x = lenght;
	}
}

template<class T>
Vector<2, T> Vector<2, T>::project(const Vector<2, T> &other) const
{
	return (this->dot(other.unit())) * other;
}

template<class T>
bool Vector<2, T>::notZero() const
{
	return x != 0 || y != 0;
}

template<class T>
Vector<2, T> Vector<2, T>::unit() const
{
	if (notZero()) {
		double lenght = getLength();

		return Vector<2, T>(x / lenght, y / lenght);
	} else {
		return Vector< 2 , T >(0, 0);
	}
}

template<class T>
Vector<2, T> Vector<2, T>::angle(double angle) const
{
	Vector< 2 , T > temp;

	if (notZero()) {
		double lenght = getLength();
		temp.x = cos(angle) * lenght;
		temp.y = sin(angle) * lenght;
	}

	return temp;
}

template<class T>
double Vector<2, T>::dot(const Vector<2, T> &vec) const
{
	return (x * vec.x) + (y * vec.y);
}

template<class T>
Vector< 1 , T > Vector<2, T>::cross(const Vector<2, T> &other) const
{
	return (x * other.y) - (y * other.x);
}

template<class T>
Vector< 2 , T > Vector<2, T>::cross(const double multiplier) const
{
	return Vector< 2 , T >(multiplier * y, -multiplier * x);
}

template<class T>
Vector<2, T>& Vector<2, T>::operator= (const Vector<2, T> &other)
{
	x = other.x;
	y = other.y;
	return *this;
}

template<class T>
bool Vector<2, T>::operator== (const Vector<2, T>& other) const
{
	return x == other.x && y == other.y;
}

template<class T>
bool Vector<2, T>::operator!= (const Vector<2, T>& other) const
{
	return !(*this == other);
}

template<class T>
bool Vector<2, T>::operator< (const Vector<2, T> &other) const
{
	return ((x * x) + (y * y)) < ((other.x * other.x) + (other.y * other.y));
}

template<class T>
bool Vector<2, T>::operator> (const Vector<2, T> &other) const
{
	return ((x * x) + (y * y)) > ((other.x * other.x) + (other.y * other.y));
}

template<class T>
bool Vector<2, T>::operator> (double length) const
{
	return ((x * x) + (y * y)) > (length * length);
}

template<class T>
bool Vector<2, T>::operator< (double length) const
{
	return ((x * x) + (y * y)) < (length * length);
}

template<class T>
Vector<2, T> operator/ (const Vector<2, T> &vec, const double &divider)
{
	return Vector<2, T>(vec.x / divider, vec.y / divider);
}

template<class T>
Vector<2, T> operator* (const Vector<2, T> &vec, const double &multiplier)
{
	return Vector<2, T>(vec.x * multiplier, vec.y * multiplier);
}

template<class T>
Vector<2, T> operator* (const double &multiplier, const Vector<2, T> &vec)
{
	return Vector<2, T>(vec.x * multiplier, vec.y * multiplier);
}

template<class T>
Vector<2, T> &operator*= (Vector<2, T> &vec, const double &multiplier)
{
	vec.x *= multiplier;
	vec.y *= multiplier;
	return vec;
}

template<class T>
Vector<2, T> operator+ (const Vector<2, T> &vec1, const Vector<2, T> &vec2)
{
	return Vector<2, T>(vec1.x + vec2.x, vec1.y + vec2.y);
}

template<class T>
Vector<2, T> &operator+= (Vector<2, T> &vec1, const Vector<2, T> &vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	return vec1;
}

template<class T>
Vector<2, T> operator- (const Vector<2, T> &vec1, const Vector<2, T> &vec2)
{
	return Vector<2, T>(vec1.x - vec2.x, vec1.y - vec2.y);
}

template<class T>
Vector<2, T> &operator-= (Vector<2, T> &vec1, const Vector<2, T> &vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	return vec1;
}

template<class T>
Vector<2, T> &operator/= (Vector<2, T> &vec, const double &divider)
{
	vec.x /= divider;
	vec.y /= divider;
	return vec;
}

template<class T>
inline ostream &operator<< (ostream &out, Vector<2, T> vec)
{
	out << vec.x << ", " << vec.y;
	return out;
}

template Vector<2, float> operator/ (const Vector<2, float>& vec, const double& divider);
template Vector<2, float> operator* (const Vector<2, float>& vec, const double& multiplier);
template Vector<2, float> operator* (const double& multiplier, const Vector<2, float>& vec);
template Vector<2, float>& operator*= (Vector<2, float>& vec, const double& multiplier);
template Vector<2, float> operator+ (const Vector<2, float>& vec1, const Vector<2, float>& vec2);
template Vector<2, float>& operator+= (Vector<2, float>& vec1, const Vector<2, float>& vec2);
template Vector<2, float> operator- (const Vector<2, float>& vec1, const Vector<2, float>& vec2);
template Vector<2, float>& operator-= (Vector<2, float>& vec1, const Vector<2, float>& vec2);
template Vector<2, float>& operator/= (Vector<2, float>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, float> vec);

template Vector<2, double> operator/ (const Vector<2, double>& vec, const double& divider);
template Vector<2, double> operator* (const Vector<2, double>& vec, const double& multiplier);
template Vector<2, double> operator* (const double& multiplier, const Vector<2, double>& vec);
template Vector<2, double>& operator*= (Vector<2, double>& vec, const double& multiplier);
template Vector<2, double> operator+ (const Vector<2, double>& vec1, const Vector<2, double>& vec2);
template Vector<2, double>& operator+= (Vector<2, double>& vec1, const Vector<2, double>& vec2);
template Vector<2, double> operator- (const Vector<2, double>& vec1, const Vector<2, double>& vec2);
template Vector<2, double>& operator-= (Vector<2, double>& vec1, const Vector<2, double>& vec2);
template Vector<2, double>& operator/= (Vector<2, double>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, double> vec);

template Vector<2, long double> operator/ (const Vector<2, long double>& vec, const double& divider);
template Vector<2, long double> operator* (const Vector<2, long double>& vec, const double& multiplier);
template Vector<2, long double> operator* (const double& multiplier, const Vector<2, long double>& vec);
template Vector<2, long double>& operator*= (Vector<2, long double>& vec, const double& multiplier);
template Vector<2, long double> operator+ (const Vector<2, long double>& vec1, const Vector<2, long double>& vec2);
template Vector<2, long double>& operator+= (Vector<2, long double>& vec1, const Vector<2, long double>& vec2);
template Vector<2, long double> operator- (const Vector<2, long double>& vec1, const Vector<2, long double>& vec2);
template Vector<2, long double>& operator-= (Vector<2, long double>& vec1, const Vector<2, long double>& vec2);
template Vector<2, long double>& operator/= (Vector<2, long double>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, long double> vec);

template Vector<2, int> operator/ (const Vector<2, int>& vec, const double& divider);
template Vector<2, int> operator* (const Vector<2, int>& vec, const double& multiplier);
template Vector<2, int> operator* (const double& multiplier, const Vector<2, int>& vec);
template Vector<2, int>& operator*= (Vector<2, int>& vec, const double& multiplier);
template Vector<2, int> operator+ (const Vector<2, int>& vec1, const Vector<2, int>& vec2);
template Vector<2, int>& operator+= (Vector<2, int>& vec1, const Vector<2, int>& vec2);
template Vector<2, int> operator- (const Vector<2, int>& vec1, const Vector<2, int>& vec2);
template Vector<2, int>& operator-= (Vector<2, int>& vec1, const Vector<2, int>& vec2);
template Vector<2, int>& operator/= (Vector<2, int>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, int> vec);

template Vector<2, unsigned int> operator/ (const Vector<2, unsigned int>& vec, const double& divider);
template Vector<2, unsigned int> operator* (const Vector<2, unsigned int>& vec, const double& multiplier);
template Vector<2, unsigned int> operator* (const double& multiplier, const Vector<2, unsigned int>& vec);
template Vector<2, unsigned int>& operator*= (Vector<2, unsigned int>& vec, const double& multiplier);
template Vector<2, unsigned int> operator+ (const Vector<2, unsigned int>& vec1, const Vector<2, unsigned int>& vec2);
template Vector<2, unsigned int>& operator+= (Vector<2, unsigned int>& vec1, const Vector<2, unsigned int>& vec2);
template Vector<2, unsigned int> operator- (const Vector<2, unsigned int>& vec1, const Vector<2, unsigned int>& vec2);
template Vector<2, unsigned int>& operator-= (Vector<2, unsigned int>& vec1, const Vector<2, unsigned int>& vec2);
template Vector<2, unsigned int>& operator/= (Vector<2, unsigned int>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, unsigned int> vec);

template Vector<2, long> operator/ (const Vector<2, long>& vec, const double& divider);
template Vector<2, long> operator* (const Vector<2, long>& vec, const double& multiplier);
template Vector<2, long> operator* (const double& multiplier, const Vector<2, long>& vec);
template Vector<2, long>& operator*= (Vector<2, long>& vec, const double& multiplier);
template Vector<2, long> operator+ (const Vector<2, long>& vec1, const Vector<2, long>& vec2);
template Vector<2, long>& operator+= (Vector<2, long>& vec1, const Vector<2, long>& vec2);
template Vector<2, long> operator- (const Vector<2, long>& vec1, const Vector<2, long>& vec2);
template Vector<2, long>& operator-= (Vector<2, long>& vec1, const Vector<2, long>& vec2);
template Vector<2, long>& operator/= (Vector<2, long>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, long> vec);

template Vector<2, unsigned long> operator/ (const Vector<2, unsigned long>& vec, const double& divider);
template Vector<2, unsigned long> operator* (const Vector<2, unsigned long>& vec, const double& multiplier);
template Vector<2, unsigned long> operator* (const double& multiplier, const Vector<2, unsigned long>& vec);
template Vector<2, unsigned long>& operator*= (Vector<2, unsigned long>& vec, const double& multiplier);
template Vector<2, unsigned long> operator+ (const Vector<2, unsigned long>& vec1, const Vector<2, unsigned long>& vec2);
template Vector<2, unsigned long>& operator+= (Vector<2, unsigned long>& vec1, const Vector<2, unsigned long>& vec2);
template Vector<2, unsigned long> operator- (const Vector<2, unsigned long>& vec1, const Vector<2, unsigned long>& vec2);
template Vector<2, unsigned long>& operator-= (Vector<2, unsigned long>& vec1, const Vector<2, unsigned long>& vec2);
template Vector<2, unsigned long>& operator/= (Vector<2, unsigned long>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, unsigned long> vec);

template Vector<2, short> operator/ (const Vector<2, short>& vec, const double& divider);
template Vector<2, short> operator* (const Vector<2, short>& vec, const double& multiplier);
template Vector<2, short> operator* (const double& multiplier, const Vector<2, short>& vec);
template Vector<2, short>& operator*= (Vector<2, short>& vec, const double& multiplier);
template Vector<2, short> operator+ (const Vector<2, short>& vec1, const Vector<2, short>& vec2);
template Vector<2, short>& operator+= (Vector<2, short>& vec1, const Vector<2, short>& vec2);
template Vector<2, short> operator- (const Vector<2, short>& vec1, const Vector<2, short>& vec2);
template Vector<2, short>& operator-= (Vector<2, short>& vec1, const Vector<2, short>& vec2);
template Vector<2, short>& operator/= (Vector<2, short>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, short> vec);

template Vector<2, unsigned short> operator/ (const Vector<2, unsigned short>& vec, const double& divider);
template Vector<2, unsigned short> operator* (const Vector<2, unsigned short>& vec, const double& multiplier);
template Vector<2, unsigned short> operator* (const double& multiplier, const Vector<2, unsigned short>& vec);
template Vector<2, unsigned short>& operator*= (Vector<2, unsigned short>& vec, const double& multiplier);
template Vector<2, unsigned short> operator+ (const Vector<2, unsigned short>& vec1, const Vector<2, unsigned short>& vec2);
template Vector<2, unsigned short>& operator+= (Vector<2, unsigned short>& vec1, const Vector<2, unsigned short>& vec2);
template Vector<2, unsigned short> operator- (const Vector<2, unsigned short>& vec1, const Vector<2, unsigned short>& vec2);
template Vector<2, unsigned short>& operator-= (Vector<2, unsigned short>& vec1, const Vector<2, unsigned short>& vec2);
template Vector<2, unsigned short>& operator/= (Vector<2, unsigned short>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, unsigned short> vec);

template Vector<2, char> operator/ (const Vector<2, char>& vec, const double& divider);
template Vector<2, char> operator* (const Vector<2, char>& vec, const double& multiplier);
template Vector<2, char> operator* (const double& multiplier, const Vector<2, char>& vec);
template Vector<2, char>& operator*= (Vector<2, char>& vec, const double& multiplier);
template Vector<2, char> operator+ (const Vector<2, char>& vec1, const Vector<2, char>& vec2);
template Vector<2, char>& operator+= (Vector<2, char>& vec1, const Vector<2, char>& vec2);
template Vector<2, char> operator- (const Vector<2, char>& vec1, const Vector<2, char>& vec2);
template Vector<2, char>& operator-= (Vector<2, char>& vec1, const Vector<2, char>& vec2);
template Vector<2, char>& operator/= (Vector<2, char>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, char> vec);

template Vector<2, unsigned char> operator/ (const Vector<2, unsigned char>& vec, const double& divider);
template Vector<2, unsigned char> operator* (const Vector<2, unsigned char>& vec, const double& multiplier);
template Vector<2, unsigned char> operator* (const double& multiplier, const Vector<2, unsigned char>& vec);
template Vector<2, unsigned char>& operator*= (Vector<2, unsigned char>& vec, const double& multiplier);
template Vector<2, unsigned char> operator+ (const Vector<2, unsigned char>& vec1, const Vector<2, unsigned char>& vec2);
template Vector<2, unsigned char>& operator+= (Vector<2, unsigned char>& vec1, const Vector<2, unsigned char>& vec2);
template Vector<2, unsigned char> operator- (const Vector<2, unsigned char>& vec1, const Vector<2, unsigned char>& vec2);
template Vector<2, unsigned char>& operator-= (Vector<2, unsigned char>& vec1, const Vector<2, unsigned char>& vec2);
template Vector<2, unsigned char>& operator/= (Vector<2, unsigned char>& vec, const double& divider);
template ostream& operator<< (ostream& out, Vector<2, unsigned char> vec);

template class Vector<2, float>;
template class Vector<2, double>;
template class Vector<2, long double>;
template class Vector<2, int>;
template class Vector<2, unsigned int>;
template class Vector<2, long>;
template class Vector<2, unsigned long>;
template class Vector<2, short>;
template class Vector<2, unsigned short>;
template class Vector<2, char>;
template class Vector<2, unsigned char>;

}
