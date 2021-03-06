#include "physicbody.h"

#include "../System/Shape/shapeinfo.h"

#include <cmath>
#include <iostream>

using namespace std;

namespace sbg {

const double correction = 12;

template<int n>
PhysicBody<n>::PhysicBody(){}

template<>
void PhysicBody<2>::update(Time time)
{
	_orientation = fmod(getNextOrientation(time.getCurrentTime()), tau);
	_angularVelocity = getNextAngularVelocity(time.getCurrentTime());
	_pulsesPosition.clear();
	_torque = getNextTorque();

	this->_position = getNextPosition(time.getCurrentTime());
	this->_corrections.clear();
	this->_velocity = getNextVelocity(time.getCurrentTime());
	this->_pulses.clear();
	_pulsesPositionAccumulator.clear();
	this->_pulseAccumulators.clear();
	this->_forces = getNextForces();
}

template<>
void PhysicBody<3>::update(Time time)
{
	Angle nextOrientation = getNextOrientation(time.getCurrentTime());
	_orientation.x = fmod(nextOrientation.x, tau);
	_orientation.y = fmod(nextOrientation.y, tau);
	_orientation.z = fmod(nextOrientation.z, tau);
	_angularVelocity = getNextAngularVelocity(time.getCurrentTime());
	_pulsesPosition.clear();
	_torque = getNextTorque();

	this->_position = getNextPosition(time.getCurrentTime());
	this->_corrections.clear();
	this->_velocity = getNextVelocity(time.getCurrentTime());
	this->_pulses.clear();
	_pulsesPositionAccumulator.clear();
	this->_pulseAccumulators.clear();
	this->_forces = getNextForces();
}

template<int n>
Vector<n, double> PhysicBody<n>::getNextVelocity(double time) const
{	Vector<n, double> velocity = this->_velocity;

	for (auto i : this->getNextForces()) {
		Vector<n, double> position = getForcePosition(i.first);

		if (!position.null() && !i.second.null()) {
			Angle torque = position.cross(i.second) / correction;
			i.second *= 1 / ((torque.length() * (1.0/getMomentOfInertia())) + Vector<freedom(n), double>{1});
		}
		
		velocity += (i.second / this->_mass) * time;
	}
	
	for (auto i : this->getNextPulses()) {
		Vector<n, double> pulse = i.second;
		Vector<n, double> position = getPulsePosition(i.first);

		if (!position.null() && !pulse.null()) {
			Angle torque = position.cross(pulse) / correction;
			pulse *= 1 / ((torque.length() / getMomentOfInertia()) + Vector<freedom(n), double>{1});
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

	return forces;
}

template<int n>
Vector<freedom(n), double> PhysicBody<n>::getNextOrientation(double time) const
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
Vector<freedom(n), double> PhysicBody<n>::getNextAngularVelocity(double time) const
{
	Angle velocity = Angle();
	Angle torquePulse = Angle();

	velocity = (getNextTorque() * (1/getMomentOfInertia())) * time;
	
	auto pulses = this->getNextPulses();

	for (auto forcePos : getNextPulsesPositions()) {
		Vector<n, double> pulse = pulses[forcePos.first];
		Vector<n, double> position = forcePos.second;

		if (!position.null() && !pulse.null()) {
			Angle torque = position.cross(pulse) / correction;
			torquePulse += torque;
		}
	}

	velocity += torquePulse * (1/ getMomentOfInertia());

	return _angularVelocity + (velocity / 1.001) * tau;
}

template<int n>
Vector<freedom(n), double> PhysicBody<n>::getTorque() const
{
	return _torque;
}

template<int n>
Vector<freedom(n), double> PhysicBody<n>::getNextTorque() const
{
	Angle torque = Angle();

	for (auto forcePos : _forcesPosition) {
		Vector<n, double> force = this->getForce(forcePos.first);

		if (!forcePos.second.null() && !force.null()) {
			Angle forceTorque = forcePos.second.cross(force) / correction;
			torque += forceTorque;
		}
	}

	return torque;
}

template<int n>
Vector<freedom(n), double> PhysicBody<n>::getMomentOfInertia() const
{
	if (_shapeInfo) {
		return _shapeInfo->getMomentOfInertia(this->_mass);
	} else {
		return Vector<freedom(n), double>{this->_mass};
	}
}

template<int n>
void PhysicBody<n>::setShapeInfo(unique_ptr<AbstractShapeInfo<n>> shapeInfo)
{
	_shapeInfo = move(shapeInfo);
}

template<int n>
const AbstractShapeInfo<n>* PhysicBody<n>::getShapeInfo() const
{
	return _shapeInfo.get();
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
	auto pulsePosition = getNextPulsesPositions();
	
	auto it = pulsePosition.find(type);

	if (it != pulsePosition.end()) {
		return it->second;
	}

	return {};
}

template<int n>
Vector<n, double> PhysicBody<n>::getForcePosition(string type) const
{
	auto it = _forcesPosition.find(type);

	if (it != _forcesPosition.end()) {
		return it->second;
	}

	return {};
}

template<int n>
void PhysicBody<n>::accumulatePulse(const string type, Vector<n, double> pulse)
{
	accumulatePulse(type, pulse, {});
}

template<int n>
void PhysicBody<n>::accumulatePulse(const string type, Vector<n, double> pulse, Vector<n, double> position)
{
	lock_guard<mutex> lock{_pulseAccumulationMutex};
	PhysicPoint<n>::accumulatePulse(type, pulse);
	_pulsesPositionAccumulator[type].first += position * pulse.length();
	_pulsesPositionAccumulator[type].second += pulse.length();
	
}

template<int n>
std::map<std::string, Vector<n, double>> PhysicBody<n>::getNextPulsesPositions() const
{
	auto pulsePositions = _pulsesPosition;
	
	for (auto accumulator : _pulsesPositionAccumulator) {
		if (accumulator.second.second > 0) {
			pulsePositions[accumulator.first] += accumulator.second.first.value() / accumulator.second.second;
		}
	}
	
	return pulsePositions;
}

template struct PhysicBody<2>;
template struct PhysicBody<3>;

}
