#pragma once

#include "rule.h"
#include "../physicpoint.h"

namespace subgine
{
namespace physic
{
namespace Rule
{

template<int n>
class Attraction : public Rule<n>
{
public:
	Attraction(const Attraction& c) : _value(c._value), _objects(c._objects)
	{
		
	}
	
	Attraction(const Vector<n, double> value) : _value(value)
	{
		
	}
	
	Vector<n, double> getResult(const PhysicPoint<n>& object) const
	{
		Vector<n, double> result;
		
		for (auto i : _objects) {
			Vector<n, double> absolute = i->getPosition() - object.getPosition();
			double distance = absolute.getLength();
			
			result += gravity * ((absolute.unit() * i->getMass() * object.getMass()) / (distance*distance));
		}
		
		return result * getValue();
	}
	
	void addObject(const PhysicPoint<n>& object)
	{
		_objects.remove(&object);
		_objects.push_back(&object);
	}
	
	void removeObject(const PhysicPoint<n>& object)
	{
		_objects.remove(&object);
	}
	
	Vector<n, double> getValue() const
	{
		return _value;
	}
	
	void setValue(const Vector<n, double> value)
	{
		_value = value;
	}

private:
	static const double gravity;
	
	std::list<const PhysicPoint<n>*> _objects;
	Vector2 _value;
};

template<int n>
const double Attraction<n>::gravity = 6.67e-11;

}
}
}
