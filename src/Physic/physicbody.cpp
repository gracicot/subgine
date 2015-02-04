#include "physicbody.h"

#include "../System/Shape/shape.h"

#include <cmath>
#include <iostream>

using namespace std;

namespace sbg {

const double correction = 12;

template<int n>
PhysicBody<n>::PhysicBody() : _torque(Angle()), _angularVelocity(Angle()), _orientation(Angle()) {}

template<>
void PhysicBody<2>::update(const double time)
{
	_orientation = fmod(getNextOrientation(time), tau);
	_angularVelocity = getNextAngularVelocity(time);
	_pulsesPosition.clear();
	_torque = getNextTorque(time);

	this->_position = getNextPosition(time);
	this->_corrections.clear();
	this->_velocity = getNextVelocity(time);
	this->_pulses.clear();
	_pulsesPositionAccumulator.clear();
	this->_pulseAccumulators.clear();
	this->_forces = getNextForces();
}

template<>
void PhysicBody<3>::update(const double time)
{
	Angle nextOrientation = getNextOrientation(time);
	_orientation.x = fmod(nextOrientation.x, tau);
	_orientation.y = fmod(nextOrientation.y, tau);
	_orientation.z = fmod(nextOrientation.z, tau);
	_angularVelocity = getNextAngularVelocity(time);
	_pulsesPosition.clear();
	_torque = getNextTorque(time);

	this->_position = getNextPosition(time);
	this->_corrections.clear();
	this->_velocity = getNextVelocity(time);
	this->_pulses.clear();
	_pulsesPositionAccumulator.clear();
	this->_pulseAccumulators.clear();
	this->_forces = getNextForces();
}

template<int n>
Vector<n, double> PhysicBody<n>::getNextVelocity(const double time) const
{	Vector<n, double> velocity = this->_velocity;

	for (auto i : this->getNextForces()) {
		velocity += (i.second / this->_mass) * time;
	}
	
	auto pulses = this->_pulses;
	
	for (auto& accumulator : this->_pulseAccumulators) {
		pulses[accumulator.first] += static_cast<Vector<n, double>>(accumulator.second);
	}

	for (auto i : pulses) {
		Vector<n, double> pulse = i.second;
		Vector<n, double> position = getPulsePosition(i.first);

		if (position.notZero() && pulse.notZero()) {
			Angle torque = position.cross(pulse) / correction;
			pulse /= (torque.getLength() / getMomentOfInertia()) + 1;
		}

		velocity += (pulse / this->_mass);
	}

	return velocity;
}

template<int n>
map<string, Vector<n, double>> PhysicBody<n>::getNextForces() const
{
	auto forces = this->_forces;

	for (auto& i : this->_rules) {
		forces[i.first] = i.second->getResult(*this);
	}

	for (auto& i : forces) {
		Vector<n, double> force = i.second;
		Vector<n, double> position = getForcePosition(i.first);

		if (position.notZero() && force.notZero()) {
			Angle torque = position.cross(force) / correction;
			i.second /= (torque.getLength() / getMomentOfInertia()) + 1;
		}
	}

	return forces;
}

template<int n>
Vector<freedom(n), double> PhysicBody<n>::getNextOrientation(const double time) const
{
	return _orientation + (getNextAngularVelocity(time)) * time;
}

template<int n>
Vector<freedom(n), double> PhysicBody<n>::getOrientation() const
{
	return _orientation;
}

template<int n>
Vector<freedom(n), double> PhysicBody<n>::getAngularVelocity() const
{
	return _angularVelocity;
}

template<int n>
void PhysicBody<n>::setOrientation(Angle orientation)
{
	_orientation = orientation;
}

template<int n>
Vector<freedom(n), double> PhysicBody<n>::getNextAngularVelocity(const double time) const
{
	Angle velocity = Angle();
	Angle torquePulse = Angle();

	velocity = (getNextTorque(time) / getMomentOfInertia()) * time;
	
	auto pulsePosition = _pulsesPosition;
	
	for (auto accumulator : _pulsesPositionAccumulator) {
		if (accumulator.second.second > 0) {
			pulsePosition[accumulator.first] += static_cast<Vector<n, double>>(accumulator.second.first) / accumulator.second.second;
		}
	}
	
	auto pulses = this->_pulses;
	
	for (auto& accumulator : this->_pulseAccumulators) {
		pulses[accumulator.first] += static_cast<Vector<n, double>>(accumulator.second);
	}

	for (auto forcePos : pulsePosition) {
		Vector<n, double> pulse = pulses[forcePos.first];
		Vector<n, double> position = forcePos.second;

		if (position.notZero() && pulse.notZero()) {
			Angle torque = position.cross(pulse) / correction;
			torquePulse += torque;
		}
	}

	velocity += torquePulse / getMomentOfInertia();

	return _angularVelocity + (velocity / 1.001) * tau;
}

template<int n>
Vector<freedom(n), double> PhysicBody<n>::getTorque() const
{
	return _torque;
}

template<int n>
Vector<freedom(n), double> PhysicBody<n>::getNextTorque(const double time) const
{
	Angle torque = Angle();

	for (auto forcePos : _forcesPosition) {
		Vector<n, double> force = this->getForce(forcePos.first);

		if (forcePos.second.notZero() && force.notZero()) {
			Angle forceTorque = forcePos.second.cross(force) / correction;
			torque += forceTorque;
		}
	}

	return torque;
}

template<int n>
double PhysicBody<n>::getMomentOfInertia() const
{
	if (_shape) {
		return _momentOfInertia;
	} else {
		return this->_mass;
	}
}

template<int n>
void PhysicBody<n>::setShape(shared_ptr<shape::Shape<n>> shape)
{
	_shape = shape;
	_momentOfInertia = _shape->getMomentOfInertia(this->_mass);
}

template<int n>
shared_ptr<shape::Shape<n>> PhysicBody<n>::getShape() const
{
	return _shape;
}

template<int n>
void PhysicBody<n>::setPulse(const string type, const Vector<n, double> pulse, const Vector<n, double> position)
{
	this->_pulses[type] = pulse;
	_pulsesPosition[type] = position;
}

template<int n>
void PhysicBody<n>::setForce(const string type, const Vector<n, double> force, const Vector<n, double> position)
{
	this->_forces[type] = force;
	_forcesPosition[type] = position;
}

template<int n>
Vector<n, double> PhysicBody<n>::getPulsePosition(string type) const
{
	auto pulsePosition = _pulsesPosition;
	
	for (auto accumulator : _pulsesPositionAccumulator) {
		if (accumulator.second.second > 0) {
			pulsePosition[accumulator.first] += static_cast<Vector<n, double>>(accumulator.second.first) / accumulator.second.second;
		}
	}
	auto it = pulsePosition.find(type);

	if (it != pulsePosition.end()) {
		return it->second;
	}

	return Vector<n, double>();
}

template<int n>
Vector<n, double> PhysicBody<n>::getForcePosition(string type) const
{
	auto it = _forcesPosition.find(type);

	if (it != _forcesPosition.end()) {
		return it->second;
	}

	return Vector<n, double>();
}

template<int n>
void PhysicBody<n>::accumulatePulse(const string type, Vector<n, double> pulse)
{
	PhysicPoint<n>::accumulatePulse(type, pulse);
}

template<int n>
void PhysicBody<n>::accumulatePulse(const string type, Vector<n, double> pulse, Vector<n, double> position)
{
	lock_guard<mutex> lock{_pulseAccumulationMutex};
	PhysicPoint<n>::accumulatePulse(type, pulse);
	_pulsesPositionAccumulator[type].first += position * pulse.getLength();
	_pulsesPositionAccumulator[type].second += pulse.getLength();
	
}

template class PhysicBody<2>;
template class PhysicBody<3>;

}
