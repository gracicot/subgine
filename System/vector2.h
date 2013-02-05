/*
    Copyright 2012 <copyright holder> <email>

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/


#ifndef VECTOR_H
#define VECTOR_H

#include "const.h"
#include "positionnable.h"

struct Vector2 : public Positionnable
{
	Vector2(double _x = 0, double _y = 0);
	Vector2(const Vector2& other);
	Vector2(const sf::Vector2<float>& other);
	Vector2(const sf::Vector2<double>& other);
	
	Vector2& operator=(const Vector2& other);
	double getAngle() const;
	double getLenght() const;
	void setAngle(const double angle);
	void setLenght(const double lenght);
	Vector2 project(Vector2& other) const;
	Vector2 unit() const;
	double dot(const Vector2& vec) const;

	virtual Vector2 getPosition() const;

	operator sf::Vector2<double>() const;
	operator sf::Vector2<float>() const;

	double x;
	double y;
};

Vector2 operator*(const Vector2& vec1, const Vector2& vec2);
Vector2 operator*(const double& multiplier, const Vector2& vec);
Vector2 operator*(const Vector2& vec, const double& multiplier);
Vector2 operator+(const Vector2& vec1, const Vector2& vec2);
Vector2 operator-(const Vector2& vec1, const Vector2& vec2);
Vector2 operator/(const Vector2& vec, const double& divider);
Vector2& operator*=(Vector2& vec, const double& multiplier);
Vector2& operator+=(Vector2& vec1, const Vector2& vec2);
Vector2& operator-=(Vector2& vec1, const Vector2& vec2);
Vector2& operator/=(Vector2& vec, const double& divider);
inline std::ostream& operator<<(std::ostream& out, Vector2 vec)
{
	out << vec.x << ", " << vec.y;
	return out;
}


#endif // VECTOR_H


