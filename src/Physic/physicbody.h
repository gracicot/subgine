#pragma once

#include "physicpoint.h"
#include "../System/Shape/shape.h"

#include <iostream>
#include <memory>

namespace subgine
{
namespace physic
{

template<int n>
class PhysicBody : public PhysicPoint<n>
{
public:
	PhysicBody() : _torque(0), _angularVecolicy(0), _orientation(0) {}
	
	void update(const double time) override
	{
		_orientation = std::fmod(getNextOrientation(time), tau);
		_angularVecolicy = getNextAngularVelocity(time);
		_pulsesPosition.clear();
		_torque = getNextTorque(time);
		PhysicPoint<n>::update(time);
	}
	
	double getNextOrientation(const double time) const
	{
		return _orientation + (getNextAngularVelocity(time)) * time;
	}
	
	double getOrientation() const
	{
		return _orientation;
	}
	
	double getAngularVelocity() const
	{
		return _angularVecolicy;
	}
	
	double setOrientation(double orientation)
	{
		_orientation = orientation;
	}
	
	double getNextAngularVelocity(const double time) const
	{
		double velocity = _angularVecolicy / tau;
		double torquePulse = 0;
		
		velocity += (getNextTorque(time) / getMomentOfInertia()) * time;
		
		for (auto forcePos : _pulsesPosition) {
			Vector<n, double> force = this->getPulse(forcePos.first);
			double distance = forcePos.second.getLength();
			
			if (forcePos.second.notZero() && force.notZero()) {
				torquePulse += forcePos.second.cross(force) * distance;
			}
		}
		velocity += torquePulse / getMomentOfInertia();
		
		return (velocity / 1.0001) * tau;
	}
	
	double getTorque() const
	{
		return _torque;
	}
	
	double getNextTorque(const double time) const
	{
		double torque = 0;
		
		for (auto forcePos : _forcesPosition) {
			Vector<n, double> force = this->getForce(forcePos.first);
			double distance = forcePos.second.getLength();
			
			torque += forcePos.second.angle(forcePos.second.getAngle() + getOrientation()).cross(force) * distance;
		}
		
		return torque;
	}
	
	double getMomentOfInertia() const
	{
		if (_shape) {
			return _momentOfInertia;
		} else {
			return this->_mass;
		}
	}
	
	void setShape(std::shared_ptr<shape::Shape<n>> shape)
	{
		_shape = shape;
		_momentOfInertia = _shape->getMomentOfInertia(this->_mass);
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
	std::shared_ptr<shape::Shape<n>> _shape;
	std::map<std::string, Vector<n, double>> _pulsesPosition;
	std::map<std::string, Vector<n, double>> _forcesPosition;
	
	double _orientation;
	double _momentOfInertia;
	double _angularVecolicy;
	double _torque;
};

typedef PhysicBody<2> PhysicBody2;
typedef PhysicBody<3> PhysicBody3;

}
}