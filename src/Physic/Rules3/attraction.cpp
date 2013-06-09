#include "attraction.h"

#include "../physicpoint3.h"

namespace Rule3
{

Attraction::Attraction(const Attraction& c) : _value(c._value), _objects(c._objects)
{

}

Attraction::Attraction(const Vector3 value) : _value(value)
{

}

Vector3 Attraction::getResult(const PhysicPoint3& object) const
{
	Vector3 result;
	Vector3 absolute;
	
for(auto i : _objects)
	{
		absolute = i->getPosition() - object.getPosition();
		result +=  (absolute.unit() * i->getMass() * object.getMass()) / (pow2(absolute.x) + pow2(absolute.y) + pow2(absolute.z));	  
	}

	return result * getValue();
}

void Attraction::addObject(const PhysicPoint3& object)
{
	_objects.remove(&object);
	_objects.push_back(&object);
}

void Attraction::removeObject(const PhysicPoint3& object)
{
	_objects.remove(&object);
}

Vector3 Attraction::getValue() const
{
	return _value;
}

void Attraction::setValue(const Vector3 value)
{
	_value = value;
}

}

