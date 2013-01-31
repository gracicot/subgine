#include "gravity.h"

#include "../physicpoint3.h"

namespace Rule3
{

Gravity::Gravity(const Gravity& c) : _value(c._value)
{

}

Gravity::Gravity(const Vector3 value) : _value(value)
{

}

Gravity::~Gravity()
{

}

Vector3 Gravity::getResult(const PhysicPoint3& object) const
{
	return _value*object.getMass();
}

Vector3 Gravity::getValue() const
{
	return _value;
}

void Gravity::setValue(const Vector3 value)
{
	_value = value;
}

}