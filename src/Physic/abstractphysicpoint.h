#pragma once

namespace subgine
{
namespace physic
{

class AbstractPhysicPoint
{
public:
	AbstractPhysicPoint();
	~AbstractPhysicPoint() = default;
	
	void setMass(const double mass);
	double getMass() const;
	
	virtual void update(const double time) = 0;

protected:
	double _mass;
};

}
}
