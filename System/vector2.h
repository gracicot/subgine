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

struct Vector : public Positionnable
{
	Vector(double _x = 0, double _y = 0);
	Vector(const Vector& other);
	Vector(const sf::Vector2<float>& other);
	Vector(const sf::Vector2<double>& other);
	
	Vector& operator=(const Vector& other);
	double getAngle() const;
	double getLenght() const;
	void setAngle(const double angle);
	void setLenght(const double lenght);
	Vector project(Vector& other) const;
	Vector normalize() const;
	double dot(const Vector& vec) const;

	virtual Vector getPosition() const;

	operator sf::Vector2<double>() const;
	operator sf::Vector2<float>() const;

	double x;
	double y;
};

Vector operator*(const Vector& vec1, const Vector& vec2);
Vector operator*(const double& multiplier, const Vector& vec);
Vector operator*(const Vector& vec, const double& multiplier);
Vector operator+(const Vector& vec1, const Vector& vec2);
Vector operator-(const Vector& vec1, const Vector& vec2);
Vector operator/(const Vector& vec, const double& divider);
Vector& operator*=(Vector& vec, const double& multiplier);
Vector& operator+=(Vector& vec1, const Vector& vec2);
Vector& operator-=(Vector& vec1, const Vector& vec2);
Vector& operator/=(Vector& vec, const double& divider);
inline std::ostream& operator<<(std::ostream& out, Vector vec)
{
	out << vec.x << ", " << vec.y;
	return out;
}


#endif // VECTOR_H

// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
