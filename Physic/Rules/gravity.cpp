#include "gravity.h"

namespace Rule
{

Gravity::Gravity(const Gravity& c) : _value(c._value)
{

}

Gravity::Gravity(const Vector value) : _value(value)
{

}

Gravity::~Gravity()
{

}

Vector Gravity::getResult(const PhysicPoint& object) const
{
	return _value*object.getMass();
}

Vector Gravity::getValue() const
{
	return _value;
}

void Gravity::setValue(const Vector value)
{
	_value = value;
}

}