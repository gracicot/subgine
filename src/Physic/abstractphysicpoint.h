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
	void lock(const bool lock);

	bool isLock() const;
	double getMass() const;

	virtual void updateVelocity(const double time) = 0;
	virtual void updatePosition(const double time) = 0;
	virtual void applyRules() = 0;

protected:
	double _mass;
	bool _lock;
};

}
}
