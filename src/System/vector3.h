#pragma once

#include "vector2.h"
#include "positionnable3.h"

struct Vector3 : public Positionnable3
{
	Vector3(double _x = 0, double _y = 0, double _z = 0);
	Vector3(const Vector3& other);
	
	Vector3& operator=(const Vector3& other);
	Vector2 getAngles() const;
	double getLenght() const;
	void setAngles(const Vector2 angles);
	void setLenght(const double lenght);
	Vector3 unit() const;

	virtual Vector3 getPosition() const;
	
	double x;
	double y;
	double z;
};

Vector3 operator*(const double& multiplier, const Vector3& vec);
Vector3 operator*(const Vector3& vec1, const Vector3& vec2);
Vector3 operator*(const Vector3& vec, const double& multiplier);
Vector3 operator+(const Vector3& vec1, const Vector3& vec2);
Vector3 operator-(const Vector3& vec1, const Vector3& vec2);
Vector3 operator/(const Vector3& vec, const double& divider);
Vector3 operator-(const Vector3& vec);
Vector3& operator*=(Vector3& vec, const double& multiplier);
Vector3& operator+=(Vector3& vec1, const Vector3& vec2);
Vector3& operator-=(Vector3& vec1, const Vector3& vec2);
Vector3& operator/=(Vector3& vec, const double& divider);

inline std::ostream& operator<<(std::ostream& out, Vector3 vec)
{
	out << vec.x << ", " << vec.y << ", " << vec.z;
	return out;
}
