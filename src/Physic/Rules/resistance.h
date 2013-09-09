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
class Resistance : public Rule<n>
{
public:
	Resistance(const Vector<n, double> value = Vector<n, double>()) : _value(value)
	{
		
	}
	
	Vector<n, double> getResult(const PhysicPoint<n>& object) const
	{
		return -1 * object.getVelocity() * getValue();
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
	Vector<n, double> _value;
};

}
}
}
