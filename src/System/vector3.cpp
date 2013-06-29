#include "vector3.h"
#include "const.h"
namespace subgine
{
Vector3::Vector3(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{

}

Vector3::Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z)
{

}

Vector2 Vector3::getAngles() const
{
	Vector2 angle(atan(y / x), acos(z / getLenght()));

	return angle;
}

double Vector3::getLenght() const
{
	return sqrt(pow2(x) + pow2(y) + pow2(z));
}

void Vector3::setAngles(const Vector2 angles)
{
	if (x != 0 || y != 0 || z != 0) {
		double lenght = getLenght();
		x = sin(angles.y) * cos(angles.x) * lenght;
		y = sin(angles.x) * sin(angles.y) * lenght;
		z = cos(angles.y) * lenght;
	}
}

void Vector3::setLenght(double lenght)
{
	if (x != 0 || y != 0 || z != 0) {
		double product = lenght / getLenght();
		x *= product;
		y *= product;
		z *= product;
	} else {
		x = lenght;
	}
}

Vector3 Vector3::unit() const
{
	double lenght = getLenght();
	return Vector3(x / lenght, y / lenght, z / lenght);
}

Vector3 Vector3::getPosition() const
{
	return *this;
}

//Operators

Vector3& Vector3::operator= (const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3 operator/ (const Vector3& vec, const double& divider)
{
	return Vector3(vec.x / divider, vec.y / divider, vec.z / divider);
}

Vector3 operator* (const Vector3& vec, const double& multiplier)
{
	return Vector3(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier);
}

Vector3 operator* (const double& multiplier, const Vector3& vec)
{
	return Vector3(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier);
}

Vector3& operator*= (Vector3& vec, const double& multiplier)
{
	vec.x *= multiplier;
	vec.y *= multiplier;
	vec.z *= multiplier;
	return vec;
}

Vector3 operator+ (const Vector3& vec1, const Vector3& vec2)
{
	return Vector3(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
}

Vector3& operator+= (Vector3& vec1, const Vector3& vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	return vec1;
}

Vector3 operator- (const Vector3& vec1, const Vector3& vec2)
{
	return Vector3(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}

Vector3& operator-= (Vector3& vec1, const Vector3& vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	return vec1;
}

Vector3& operator/= (Vector3& vec, const double& divider)
{
	vec.x /= divider;
	vec.y /= divider;
	vec.z /= divider;
	return vec;
}

Vector3 operator* (const Vector3& vec1, const Vector3& vec2)
{
	return Vector3(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z);
}

Vector3 operator- (const Vector3& vec)
{
	return Vector3(-vec.x, -vec.y, -vec.z);
}


}
