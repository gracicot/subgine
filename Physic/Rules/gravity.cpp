#include "gravity.h"

namespace Rule
{

Gravity::Gravity(const Gravity& c) : _value(c._value)
{

}

Gravity::Gravity(Vector value) : _value(value)
{

}

Gravity::~Gravity()
{

}

Vector Gravity::apply(const PhysicPoint& object, double time) const
{
	return _value*object.getMass();
}

Vector Gravity::getValue() const
{
	return _value;
}

void Gravity::setValue(Vector value)
{
	_value = value;
}

}