#include "gravity.h"

namespace Rule3
{

Gravity::Gravity(const Gravity& c) : _value(c._value)
{

}

Gravity::Gravity(Vector3 value) : _value(value)
{

}

Gravity::~Gravity()
{

}

Vector3 Gravity::apply(const PhysicPoint3& object) const
{
	return _value*object.getMass();
}

Vector3 Gravity::getValue() const
{
	return _value;
}

void Gravity::setValue(Vector3 value)
{
	_value = value;
}

}