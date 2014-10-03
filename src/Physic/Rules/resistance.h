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
	Resistance(const double value = 0) : _value(value)
	{
		
	}
	
	Vector<n, double> getResult(const PhysicPoint<n>& object) const
	{
		return -1 * object.getVelocity() * getValue();
	}
	
	double getValue() const
	{
		return _value;
	}
	
	void setValue(const double value)
	{
		_value = value;
	}

private:
	double _value;
};

}
}
}
