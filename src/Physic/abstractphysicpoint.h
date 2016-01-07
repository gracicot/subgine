#pragma once

#include "../system.hpp"

namespace sbg {

class AbstractPhysicPoint
{
public:
	void setMass(const double mass);
	double getMass() const;
	
	virtual void update(Time time) = 0;

protected:
	double _mass = 1;
};

}
