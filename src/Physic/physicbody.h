#pragma once

#include "physicpoint.h"

namespace subgine
{
namespace physic
{

template<int n>
class PhysicBody : public PhysicPoint<n>, Traits::Angle
{
public:
	PhysicBody() : _torque(0), _angularVecolicy(0) {}
	
	void updatePhysic(const double time) override
	{
		_angle = getNextOrientation(time);
		_angularVecolicy = getNextAngularVelocity(time);
		PhysicPoint<n>::updatePhysic(time);
	}
	
	double getNextOrientation(const double time) const
	{
		return _angle + (getNextAngularVelocity(time)) * time;
	}
	
	double getOrientation() const
	{
		return _angle;
	}
	
	double getAngularVelocity() const
	{
		return _angularVecolicy;
	}
	
	double getNextAngularVelocity(const double time) const
	{
		return _angularVecolicy + (getNextTorque(time) / getMomentOfInertia()) * time;
	}
	
	double getTorque() const
	{
		return _torque;
	}
	
	double getNextTorque(const double time) const
	{
		return _torque;
	}
	
	double getMomentOfInertia() const
	{
		return this->_mass;
	}
	
	void setPulse(const std::string type, const Vector<n, double> pulse, const Vector<n, double> position = Vector<n, double>())
	{
		this->_pulses[type] = pulse;
		_pulsesPosition[type] = position;
	}
	
	void setForce(const std::string type, const Vector<n, double> force, const Vector<n, double> position = Vector<n, double>())
	{
		this->_forces[type] = force;
		_forcesPosition[type] = position;
	}
	
protected:
	std::map<std::string, Vector<n, double>> _pulsesPosition;
	std::map<std::string, Vector<n, double>> _forcesPosition;
	
	double _angularVecolicy;
	double _torque;
};

typedef PhysicBody<2> PhysicBody2;
typedef PhysicBody<3> PhysicBody3;

}
}