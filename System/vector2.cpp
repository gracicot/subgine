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


#include "vector2.h"


Vector::Vector(double _x, double _y) : x(_x), y(_y)
{

}

Vector::Vector(const Vector& other) : x(other.x), y(other.y)
{

}

Vector::Vector(const sf::Vector2< float >& other) : x(other.x), y(other.y)
{

}

Vector::Vector(const sf::Vector2< double >& other) : x(other.x), y(other.y)
{

}

double Vector::getAngle() const
{
	double angle = atan2(y, x);
	if (angle < 0)
	{
		angle += 2 * M_PI;
	}
	return angle;
}

double Vector::getLenght() const
{
	return sqrt(pow2(x) + pow2(y));
}

void Vector::setAngle(double angle)
{
	if(x != 0 || y != 0)
	{
		double lenght = getLenght();
		x = cos(angle) * lenght;
		y = sin(angle) * lenght;
	}
}

void Vector::setLenght(double lenght)
{
	if(x != 0 || y != 0)
	{
		double product = lenght / getLenght();
		x *= product;
		y *= product;
	}
	else
	{
		x = lenght;
	}
}

Vector Vector::project(Vector& other) const
{
	Vector normalizedOther = other.normalize();
	return (*this * normalizedOther) * normalizedOther;
}

Vector Vector::normalize() const
{
	double lenght = getLenght();
	return Vector(x/lenght, y/lenght);
}

Vector Vector::getPosition() const
{
	return *this;
}

Vector::operator sf::Vector2< double >() const
{
	return sf::Vector2<double> (x, y);
}

Vector::operator sf::Vector2< float >() const
{
	return sf::Vector2<float> (x, y);
}


//Operators

Vector& Vector::operator= (const Vector& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Vector operator/ (const Vector& vec, const double& divider)
{
	return Vector(vec.x / divider, vec.y / divider);
}

Vector operator* (const Vector& vec, const double& multiplier)
{
	return Vector(vec.x * multiplier, vec.y * multiplier);
}

Vector operator* (const double& multiplier, const Vector& vec)
{
	return Vector(vec.x * multiplier, vec.y * multiplier);
}

Vector& operator*= (Vector& vec, const double& multiplier)
{
	vec.x *= multiplier;
	vec.y *= multiplier;
	return vec;
}

Vector operator+ (const Vector& vec1, const Vector& vec2)
{
	return Vector(vec1.x + vec2.x, vec1.y + vec2.y);
}

Vector& operator+= (Vector& vec1, const Vector& vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	return vec1;
}

Vector operator- (const Vector& vec1, const Vector& vec2)
{
	return Vector(vec1.x - vec2.x, vec1.y - vec2.y);
}

Vector& operator-= (Vector& vec1, const Vector& vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	return vec1;
}

double operator*(const Vector& vec1, const Vector& vec2)
{
	return (vec1.x*vec2.x)+(vec2.y*vec1.y);
}

Vector& operator/= (Vector& vec, const double& divider)
{
	vec.x /= divider;
	vec.y /= divider;
	return vec;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
