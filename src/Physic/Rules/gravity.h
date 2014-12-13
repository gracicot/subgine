#pragma once

#include "rule.h"
#include "../physicpoint.h"

namespace sbg {
namespace Rule {
	
template<int n>
class Gravity : public Rule<n>
{
public:
	Gravity(const Vector<n, double> value = Vector<n, double>()) : _value(value)
	{
		
	}
	
	Vector<n, double> getResult(const PhysicPoint<n>& object) const
	{
		return _value * object.getMass();
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
