#pragma once

#include "physicpoint.h"
#include "../System/Shape/shape.h"

#include <iostream>
#include <cmath>
#include <memory>

namespace subgine {
namespace physic {

template<int n>
class PhysicBody : public PhysicPoint<n>
{
public:
	typedef Vector<(n * (n - 1) / 2), double> Angle;
	
	PhysicBody() : _torque(Angle()), _angularVelocity(Angle()), _orientation(Angle()) {}

	void update(const double time) override
	{
		_orientation = std::fmod(getNextOrientation(time), tau);
		_angularVelocity = getNextAngularVelocity(time);
		_pulsesPosition.clear();
		_torque = getNextTorque(time);
		PhysicPoint<n>::update(time);
	}

	Angle getNextOrientation(const double time) const
	{
		return _orientation + (getNextAngularVelocity(time)) * time;
	}

	Angle getOrientation() const
	{
		return _orientation;
	}

	Angle getAngularVelocity() const
	{
		return _angularVelocity;
	}

	void setOrientation(Angle orientation)
	{
		_orientation = orientation;
	}

	Angle getNextAngularVelocity(const double time) const
	{
		Angle velocity = _angularVelocity / tau;
		Angle torquePulse = 0;

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

	Angle getTorque() const
	{
		return _torque;
	}

	Angle getNextTorque(const double time) const
	{
		Angle torque = 0;

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
	double _momentOfInertia;
	std::shared_ptr<shape::Shape<n>> _shape;
	std::map<std::string, Vector<n, double>> _pulsesPosition;
	std::map<std::string, Vector<n, double>> _forcesPosition;

	Angle _orientation;
	Angle _angularVelocity;
	Angle _torque;
};

typedef PhysicBody<2> PhysicBody2;
typedef PhysicBody<3> PhysicBody3;

}
}
