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
#include "const.h"

Vector2::Vector2(double _x, double _y) : x(_x), y(_y)
{

}

Vector2::Vector2(const Vector2& other) : x(other.x), y(other.y)
{

}

double Vector2::getAngle() const
{
	double angle = atan2(y, x);
	if (angle < 0)
	{
		angle += 2 * pi;
	}
	return angle;
}

double Vector2::getLenght() const
{
	return sqrt(pow2(x) + pow2(y));
}

void Vector2::setAngle(double angle)
{
	if(x != 0 || y != 0)
	{
		double lenght = getLenght();
		x = cos(angle) * lenght;
		y = sin(angle) * lenght;
	}
}

void Vector2::setLenght(double lenght)
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

Vector2 Vector2::project(Vector2 other) const
{
	return (this->dot(other.unit())) * other;
}

Vector2 Vector2::unit() const
{
	double lenght = getLenght();
	return Vector2(x/lenght, y/lenght);
}

Vector2 Vector2::getPosition() const
{
	return *this;
}

double Vector2::dot(const Vector2& vec) const
{
	return (x*vec.x)+(y*vec.y);
}


//Operators

Vector2& Vector2::operator= (const Vector2& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Vector2 operator/ (const Vector2& vec, const double& divider)
{
	return Vector2(vec.x / divider, vec.y / divider);
}

Vector2 operator* (const Vector2& vec, const double& multiplier)
{
	return Vector2(vec.x * multiplier, vec.y * multiplier);
}

Vector2 operator* (const double& multiplier, const Vector2& vec)
{
	return Vector2(vec.x * multiplier, vec.y * multiplier);
}

Vector2& operator*= (Vector2& vec, const double& multiplier)
{
	vec.x *= multiplier;
	vec.y *= multiplier;
	return vec;
}

Vector2 operator+ (const Vector2& vec1, const Vector2& vec2)
{
	return Vector2(vec1.x + vec2.x, vec1.y + vec2.y);
}

Vector2& operator+= (Vector2& vec1, const Vector2& vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	return vec1;
}

Vector2 operator- (const Vector2& vec1, const Vector2& vec2)
{
	return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
}

Vector2& operator-= (Vector2& vec1, const Vector2& vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	return vec1;
}

Vector2 operator*(const Vector2& vec1, const Vector2& vec2)
{
	return Vector2(vec1.x * vec2.x, vec1.y * vec2.y);
}

Vector2& operator/= (Vector2& vec, const double& divider)
{
	vec.x /= divider;
	vec.y /= divider;
	return vec;
}

Vector2 operator-(const Vector2& vec)
{

}
