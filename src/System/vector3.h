#pragma once

#include <ostream>
#include <cmath>
#include "vector.h"
#include "vector2.h"

namespace sbg {

template<class T>
class Vector<3, T>
{
public:
	Vector();
	Vector(T value);
	Vector(T _x, T _y, T _z);
	Vector(const Vector<3, T>& other);
	
	template<class O>
	operator Vector< 3 , O >() const
	{
		return Vector< 3 , O >(
			static_cast<O>(x),
			static_cast<O>(y),
			static_cast<O>(z)
		);
	}
	
	Vector<2, double> getAngle() const;
	double getLength() const;
	void setAngle(const Vector<3, double> angles);
	void setLenght(double lenght);
	Vector<3, T> project(Vector<3, T> other) const;
	bool notZero() const;
	Vector<3, T> unit() const;
	Vector<3, T> cross(Vector<3, T>& other) const;
	double dot(const Vector<3, T>& vec) const;
	
	Vector<3, T>& operator= (const Vector<3, T>& other);
	
	bool operator< (const Vector<3, T>& other) const;
	bool operator> (const Vector<3, T>& other) const;
	bool operator> (double length) const;
	bool operator< (double length) const;
	bool operator== (const Vector<3, T>& other) const;
	bool operator!= (const Vector<3, T>& other) const;
	
	T x, y, z;
	
	constexpr static int size = 3;
	using type = T;
};
	
template<class T> Vector<3, T> operator/ (const Vector<3, T>& vec, const double& divider);
template<class T> Vector<3, T> operator* (const Vector<3, T>& vec, const double& multiplier);
template<class T> Vector<3, T> operator* (const double& multiplier, const Vector<3, T>& vec);
template<class T> Vector<3, T>& operator*= (Vector<3, T>& vec, const double& multiplier);
template<class T> Vector<3, T> operator+ (const Vector<3, T>& vec1, const Vector<3, T>& vec2);
template<class T> Vector<3, T>& operator+= (Vector<3, T>& vec1, const Vector<3, T>& vec2);
template<class T> Vector<3, T> operator- (const Vector<3, T>& vec1, const Vector<3, T>& vec2);
template<class T> Vector<3, T>& operator-= (Vector<3, T>& vec1, const Vector<3, T>& vec2);
template<class T> Vector<3, T>& operator/= (Vector<3, T>& vec, const double& divider);
template<class T> Vector<3, T> operator- (const Vector<3, T>& vec);
template<class T> std::ostream& operator<< (std::ostream& out, Vector<3, T> vec);

extern template Vector<3, float> operator/ (const Vector<3, float>& vec, const double& divider);
extern template Vector<3, float> operator* (const Vector<3, float>& vec, const double& multiplier);
extern template Vector<3, float> operator* (const double& multiplier, const Vector<3, float>& vec);
extern template Vector<3, float>& operator*= (Vector<3, float>& vec, const double& multiplier);
extern template Vector<3, float> operator+ (const Vector<3, float>& vec1, const Vector<3, float>& vec2);
extern template Vector<3, float>& operator+= (Vector<3, float>& vec1, const Vector<3, float>& vec2);
extern template Vector<3, float> operator- (const Vector<3, float>& vec1, const Vector<3, float>& vec2);
extern template Vector<3, float>& operator-= (Vector<3, float>& vec1, const Vector<3, float>& vec2);
extern template Vector<3, float>& operator/= (Vector<3, float>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, float> vec);

extern template Vector<3, double> operator/ (const Vector<3, double>& vec, const double& divider);
extern template Vector<3, double> operator* (const Vector<3, double>& vec, const double& multiplier);
extern template Vector<3, double> operator* (const double& multiplier, const Vector<3, double>& vec);
extern template Vector<3, double>& operator*= (Vector<3, double>& vec, const double& multiplier);
extern template Vector<3, double> operator+ (const Vector<3, double>& vec1, const Vector<3, double>& vec2);
extern template Vector<3, double>& operator+= (Vector<3, double>& vec1, const Vector<3, double>& vec2);
extern template Vector<3, double> operator- (const Vector<3, double>& vec1, const Vector<3, double>& vec2);
extern template Vector<3, double>& operator-= (Vector<3, double>& vec1, const Vector<3, double>& vec2);
extern template Vector<3, double>& operator/= (Vector<3, double>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, double> vec);

extern template Vector<3, long double> operator/ (const Vector<3, long double>& vec, const double& divider);
extern template Vector<3, long double> operator* (const Vector<3, long double>& vec, const double& multiplier);
extern template Vector<3, long double> operator* (const double& multiplier, const Vector<3, long double>& vec);
extern template Vector<3, long double>& operator*= (Vector<3, long double>& vec, const double& multiplier);
extern template Vector<3, long double> operator+ (const Vector<3, long double>& vec1, const Vector<3, long double>& vec2);
extern template Vector<3, long double>& operator+= (Vector<3, long double>& vec1, const Vector<3, long double>& vec2);
extern template Vector<3, long double> operator- (const Vector<3, long double>& vec1, const Vector<3, long double>& vec2);
extern template Vector<3, long double>& operator-= (Vector<3, long double>& vec1, const Vector<3, long double>& vec2);
extern template Vector<3, long double>& operator/= (Vector<3, long double>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, long double> vec);

extern template Vector<3, int> operator/ (const Vector<3, int>& vec, const double& divider);
extern template Vector<3, int> operator* (const Vector<3, int>& vec, const double& multiplier);
extern template Vector<3, int> operator* (const double& multiplier, const Vector<3, int>& vec);
extern template Vector<3, int>& operator*= (Vector<3, int>& vec, const double& multiplier);
extern template Vector<3, int> operator+ (const Vector<3, int>& vec1, const Vector<3, int>& vec2);
extern template Vector<3, int>& operator+= (Vector<3, int>& vec1, const Vector<3, int>& vec2);
extern template Vector<3, int> operator- (const Vector<3, int>& vec1, const Vector<3, int>& vec2);
extern template Vector<3, int>& operator-= (Vector<3, int>& vec1, const Vector<3, int>& vec2);
extern template Vector<3, int>& operator/= (Vector<3, int>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, int> vec);

extern template Vector<3, unsigned int> operator/ (const Vector<3, unsigned int>& vec, const double& divider);
extern template Vector<3, unsigned int> operator* (const Vector<3, unsigned int>& vec, const double& multiplier);
extern template Vector<3, unsigned int> operator* (const double& multiplier, const Vector<3, unsigned int>& vec);
extern template Vector<3, unsigned int>& operator*= (Vector<3, unsigned int>& vec, const double& multiplier);
extern template Vector<3, unsigned int> operator+ (const Vector<3, unsigned int>& vec1, const Vector<3, unsigned int>& vec2);
extern template Vector<3, unsigned int>& operator+= (Vector<3, unsigned int>& vec1, const Vector<3, unsigned int>& vec2);
extern template Vector<3, unsigned int> operator- (const Vector<3, unsigned int>& vec1, const Vector<3, unsigned int>& vec2);
extern template Vector<3, unsigned int>& operator-= (Vector<3, unsigned int>& vec1, const Vector<3, unsigned int>& vec2);
extern template Vector<3, unsigned int>& operator/= (Vector<3, unsigned int>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, unsigned int> vec);

extern template Vector<3, long> operator/ (const Vector<3, long>& vec, const double& divider);
extern template Vector<3, long> operator* (const Vector<3, long>& vec, const double& multiplier);
extern template Vector<3, long> operator* (const double& multiplier, const Vector<3, long>& vec);
extern template Vector<3, long>& operator*= (Vector<3, long>& vec, const double& multiplier);
extern template Vector<3, long> operator+ (const Vector<3, long>& vec1, const Vector<3, long>& vec2);
extern template Vector<3, long>& operator+= (Vector<3, long>& vec1, const Vector<3, long>& vec2);
extern template Vector<3, long> operator- (const Vector<3, long>& vec1, const Vector<3, long>& vec2);
extern template Vector<3, long>& operator-= (Vector<3, long>& vec1, const Vector<3, long>& vec2);
extern template Vector<3, long>& operator/= (Vector<3, long>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, long> vec);

extern template Vector<3, unsigned long> operator/ (const Vector<3, unsigned long>& vec, const double& divider);
extern template Vector<3, unsigned long> operator* (const Vector<3, unsigned long>& vec, const double& multiplier);
extern template Vector<3, unsigned long> operator* (const double& multiplier, const Vector<3, unsigned long>& vec);
extern template Vector<3, unsigned long>& operator*= (Vector<3, unsigned long>& vec, const double& multiplier);
extern template Vector<3, unsigned long> operator+ (const Vector<3, unsigned long>& vec1, const Vector<3, unsigned long>& vec2);
extern template Vector<3, unsigned long>& operator+= (Vector<3, unsigned long>& vec1, const Vector<3, unsigned long>& vec2);
extern template Vector<3, unsigned long> operator- (const Vector<3, unsigned long>& vec1, const Vector<3, unsigned long>& vec2);
extern template Vector<3, unsigned long>& operator-= (Vector<3, unsigned long>& vec1, const Vector<3, unsigned long>& vec2);
extern template Vector<3, unsigned long>& operator/= (Vector<3, unsigned long>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, unsigned long> vec);

extern template Vector<3, short> operator/ (const Vector<3, short>& vec, const double& divider);
extern template Vector<3, short> operator* (const Vector<3, short>& vec, const double& multiplier);
extern template Vector<3, short> operator* (const double& multiplier, const Vector<3, short>& vec);
extern template Vector<3, short>& operator*= (Vector<3, short>& vec, const double& multiplier);
extern template Vector<3, short> operator+ (const Vector<3, short>& vec1, const Vector<3, short>& vec2);
extern template Vector<3, short>& operator+= (Vector<3, short>& vec1, const Vector<3, short>& vec2);
extern template Vector<3, short> operator- (const Vector<3, short>& vec1, const Vector<3, short>& vec2);
extern template Vector<3, short>& operator-= (Vector<3, short>& vec1, const Vector<3, short>& vec2);
extern template Vector<3, short>& operator/= (Vector<3, short>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, short> vec);

extern template Vector<3, unsigned short> operator/ (const Vector<3, unsigned short>& vec, const double& divider);
extern template Vector<3, unsigned short> operator* (const Vector<3, unsigned short>& vec, const double& multiplier);
extern template Vector<3, unsigned short> operator* (const double& multiplier, const Vector<3, unsigned short>& vec);
extern template Vector<3, unsigned short>& operator*= (Vector<3, unsigned short>& vec, const double& multiplier);
extern template Vector<3, unsigned short> operator+ (const Vector<3, unsigned short>& vec1, const Vector<3, unsigned short>& vec2);
extern template Vector<3, unsigned short>& operator+= (Vector<3, unsigned short>& vec1, const Vector<3, unsigned short>& vec2);
extern template Vector<3, unsigned short> operator- (const Vector<3, unsigned short>& vec1, const Vector<3, unsigned short>& vec2);
extern template Vector<3, unsigned short>& operator-= (Vector<3, unsigned short>& vec1, const Vector<3, unsigned short>& vec2);
extern template Vector<3, unsigned short>& operator/= (Vector<3, unsigned short>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, unsigned short> vec);

extern template Vector<3, char> operator/ (const Vector<3, char>& vec, const double& divider);
extern template Vector<3, char> operator* (const Vector<3, char>& vec, const double& multiplier);
extern template Vector<3, char> operator* (const double& multiplier, const Vector<3, char>& vec);
extern template Vector<3, char>& operator*= (Vector<3, char>& vec, const double& multiplier);
extern template Vector<3, char> operator+ (const Vector<3, char>& vec1, const Vector<3, char>& vec2);
extern template Vector<3, char>& operator+= (Vector<3, char>& vec1, const Vector<3, char>& vec2);
extern template Vector<3, char> operator- (const Vector<3, char>& vec1, const Vector<3, char>& vec2);
extern template Vector<3, char>& operator-= (Vector<3, char>& vec1, const Vector<3, char>& vec2);
extern template Vector<3, char>& operator/= (Vector<3, char>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, char> vec);

extern template Vector<3, unsigned char> operator/ (const Vector<3, unsigned char>& vec, const double& divider);
extern template Vector<3, unsigned char> operator* (const Vector<3, unsigned char>& vec, const double& multiplier);
extern template Vector<3, unsigned char> operator* (const double& multiplier, const Vector<3, unsigned char>& vec);
extern template Vector<3, unsigned char>& operator*= (Vector<3, unsigned char>& vec, const double& multiplier);
extern template Vector<3, unsigned char> operator+ (const Vector<3, unsigned char>& vec1, const Vector<3, unsigned char>& vec2);
extern template Vector<3, unsigned char>& operator+= (Vector<3, unsigned char>& vec1, const Vector<3, unsigned char>& vec2);
extern template Vector<3, unsigned char> operator- (const Vector<3, unsigned char>& vec1, const Vector<3, unsigned char>& vec2);
extern template Vector<3, unsigned char>& operator-= (Vector<3, unsigned char>& vec1, const Vector<3, unsigned char>& vec2);
extern template Vector<3, unsigned char>& operator/= (Vector<3, unsigned char>& vec, const double& divider);
extern template std::ostream& operator<< (std::ostream& out, Vector<3, unsigned char> vec);

extern template class Vector<3, float>;
extern template class Vector<3, double>;
extern template class Vector<3, long double>;
extern template class Vector<3, int>;
extern template class Vector<3, unsigned int>;
extern template class Vector<3, long>;
extern template class Vector<3, unsigned long>;
extern template class Vector<3, short>;
extern template class Vector<3, unsigned short>;
extern template class Vector<3, char>;
extern template class Vector<3, unsigned char>;

typedef Vector<3, float> Vector3f;
typedef Vector<3, double> Vector3d;
typedef Vector<3, long double> Vector3ld;
typedef Vector<3, int> Vector3i;
typedef Vector<3, unsigned int> Vector3ui;
typedef Vector<3, long> Vector3l;
typedef Vector<3, unsigned long> Vector3ul;
typedef Vector<3, short> Vector3s;
typedef Vector<3, unsigned short> Vector3us;
typedef Vector<3, char> Vector3c;
typedef Vector<3, unsigned char> Vector3uc;

}
