#pragma once

namespace sbg {

class AbstractPhysicPoint
{
public:
	AbstractPhysicPoint();
	
	void setMass(const double mass);
	double getMass() const;
	
	virtual void update(const double time) = 0;

protected:
	double _mass;
};

}
