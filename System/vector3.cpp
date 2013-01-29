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


#include "vector3.h"


Vector3::Vector3(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{

}

Vector3::Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z)
{

}

Vector2 Vector3::getAngles() const
{
	Vector2 angle(atan(y/x), acos(z / getLenght()));
	
	return angle;
}

double Vector3::getLenght() const
{
	return sqrt(pow2(x) + pow2(y) + pow2(z));
}

void Vector3::setAngles(const Vector2 angles)
{
	if(x != 0 || y != 0 || z != 0)
	{
		double lenght = getLenght();
		x = sin(angles.y) * cos(angles.x) * lenght;
		y = sin(angles.x) * sin(angles.y) * lenght;
		z = cos(angles.y) * lenght;
	}
}

void Vector3::setLenght(double lenght)
{
	if(x != 0 || y != 0 || z != 0)
	{
		double product = lenght / getLenght();
		x *= product;
		y *= product;
		z *= product;
	}
	else
	{
		x = lenght;
	}
}

Vector3 Vector3::normalize() const
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

Vector3 operator*(const Vector3& vec1, const Vector3& vec2)
{
	return Vector3(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z);
}


// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
