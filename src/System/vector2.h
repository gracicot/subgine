#pragma once

#include "positionnable.h"
#include "const.h"

namespace subgine
{

struct Vector2 : public Positionnable {
	Vector2(double _x = 0, double _y = 0);
	Vector2(const Vector2& other);

	Vector2& operator= (const Vector2& other);
	double getAngle() const;
	double getLenght() const;
	void setAngle(const double angle);
	void setLenght(const double lenght);
	Vector2 project(Vector2 other) const;
	Vector2 unit() const;
	double dot(const Vector2& vec) const;

	virtual Vector2 getPosition() const;

	double x;
	double y;
};

Vector2 operator* (const Vector2& vec1, const Vector2& vec2);
Vector2 operator* (const double& multiplier, const Vector2& vec);
Vector2 operator* (const Vector2& vec, const double& multiplier);
Vector2 operator+ (const Vector2& vec1, const Vector2& vec2);
Vector2 operator- (const Vector2& vec1, const Vector2& vec2);
Vector2 operator/ (const Vector2& vec, const double& divider);
Vector2 operator- (const Vector2& vec);
Vector2& operator*= (Vector2& vec, const double& multiplier);
Vector2& operator+= (Vector2& vec1, const Vector2& vec2);
Vector2& operator-= (Vector2& vec1, const Vector2& vec2);
Vector2& operator/= (Vector2& vec, const double& divider);
inline std::ostream& operator<< (std::ostream& out, Vector2 vec)
{
	out << vec.x << ", " << vec.y;
	return out;
}


}
