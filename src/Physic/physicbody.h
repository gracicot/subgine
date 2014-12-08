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

		this->_position = PhysicPoint<n>::getNextPosition(time);
		this->_corrections.clear();
		this->_velocity = PhysicPoint<n>::getNextVelocity(time);
		this->_pulses.clear();
		this->_forces = PhysicPoint<n>::getNextForces();
	}
	
	virtual Vector<n, double> getNextVelocity(const double time) const override
	{
		Vector<n, double> velocity = this->_velocity;
		
		for (auto i : this->getNextForces()) {
			velocity += (i.second / this->_mass) * time;
		}
		
		for (auto i : this->_pulses) {
			Vector<n, double> pulse = i.second;
			Vector<n, double> position = getPulsePosition(i.first);
			double distance = position.getLength();

			if (position.notZero() && pulse.notZero()) {
				Angle torque = position.cross(pulse) / (distance*this->_mass);
				pulse /= (torque.getLength() / getMomentOfInertia()) + 1;
			}
			
			velocity += (pulse / this->_mass);
		}
		
		return velocity;
	}
	
	virtual std::map<std::string, Vector<n, double>> getNextForces() const
	{
		auto forces = this->_forces;
		
		for (auto i : this->_rules) {
			forces[i.first] = i.second->getResult(*this);
		}
		
		for (auto& i : forces) {
			Vector<n, double> force = i.second;
			Vector<n, double> position = getForcePosition(i.first);
			double distance = position.getLength();

			if (position.notZero() && force.notZero()) {
				Angle torque = position.cross(force) / (distance*this->_mass);
				i.second /= (torque.getLength() / getMomentOfInertia()) + 1;
			}
		}
		
		return forces;
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
		Angle velocity = Angle();
		Angle torquePulse = Angle();

		velocity += (getNextTorque(time) / getMomentOfInertia()) * time;

		for (auto forcePos : _pulsesPosition) {
			Vector<n, double> force = this->getPulse(forcePos.first);
			double distance = forcePos.second.getLength();

			if (forcePos.second.notZero() && force.notZero()) {
				Angle torque = forcePos.second.cross(force) / (distance*this->_mass);
				torquePulse += torque;
			}
		}

		velocity = torquePulse / getMomentOfInertia();

		return _angularVelocity + (velocity / 1.0001) * tau;
	}

	Angle getTorque() const
	{
		return _torque;
	}

	Angle getNextTorque(const double time) const
	{
		Angle torque = Angle();

		for (auto forcePos : _forcesPosition) {
			Vector<n, double> force = this->getForce(forcePos.first);
			double distance = forcePos.second.getLength();

			Angle forceTorque = forcePos.second.cross(force) / (distance*this->_mass);
			torque += forceTorque;
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
	
	std::shared_ptr<shape::Shape<n>> getShape() const
	{
		return _shape;
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
	
	Vector<n, double> getPulsePosition(std::string type) const
	{
		auto it = _pulsesPosition.find(type);
		if (it != _pulsesPosition.end()) {
			return it->second;
		}
		return Vector<n, double>();
	}
	
	Vector<n, double> getForcePosition(std::string type) const
	{
		auto it = _forcesPosition.find(type);
		if (it != _forcesPosition.end()) {
			return it->second;
		}
		return Vector<n, double>();
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
