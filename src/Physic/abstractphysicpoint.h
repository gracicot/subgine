#pragma once

namespace subgine
{
namespace physic
{

class AbstractPhysicPoint
{
public:
	AbstractPhysicPoint();
	
	void setMass(const double mass);
	double getMass() const;
	
	virtual void updatePhysic(const double time) = 0;

protected:
	double _mass;
};

}
}
