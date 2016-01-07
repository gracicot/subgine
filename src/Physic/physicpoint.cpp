#include "physicpoint.h"

using namespace std;

namespace sbg {

template<int n>
PhysicPoint<n>::PhysicPoint()
{
}

template<int n>
PhysicPoint<n>::~PhysicPoint()
{
}

template<int n>
PhysicPoint<n>& PhysicPoint<n>::operator=(PhysicPoint<n>&& o)
{
	_velocity = move(o._velocity);
	_corrections = move(o._corrections);
	_forces = move(o._forces);
	_position = move(o._position);
	_pulseAccumulators = move(o._pulseAccumulators);
	_pulses = move(o._pulses);
	_rules = move(o._rules);
	return *this;
}

template<int n>
PhysicPoint<n>::PhysicPoint(PhysicPoint<n>&& o) :
	_velocity{move(o._velocity)},
	_position{move(o._position)},
	_pulses{move(o._pulses)},
	_rules{move(o._rules)},
	_forces{move(o._forces)},
	_corrections{move(o._corrections)},
	_pulseAccumulators{move(o._pulseAccumulators)}
{}

template<int n>
Vector<n, double> PhysicPoint<n>::getVelocity() const
{
	return _velocity;
}

template<int n>
void PhysicPoint<n>::setVelocity(const Vector<n, double> velocity)
{
	_velocity = velocity;
}

template<int n>
void PhysicPoint<n>::setPosition(const Vector<n, double> posision)
{
	this->_position = posision;
}

template<int n>
Rule<n>* PhysicPoint<n>::getRule(const string tag)
{
	auto it = _rules.find(tag);

	if (it != _rules.end()) {
		return it->second.get();
	}

	return nullptr;
}

template<int n>
const Rule<n>* PhysicPoint<n>::getRule(const string tag) const
{
	auto it = _rules.find(tag);

	if (it != _rules.end()) {
		return it->second.get();
	}

	return nullptr;
}

template<int n>
void PhysicPoint<n>::removeRule(string tag)
{
	_rules.erase(tag);
	_forces.erase(tag);
}

template<int n>
bool PhysicPoint<n>::hasRule(string tag) const
{
	return _rules.find(tag) != _rules.end();
}

template<int n>
void PhysicPoint<n>::setForce(const string type, const Vector<n, double> force)
{
	_forces[type] = force;
}

template<int n>
void PhysicPoint<n>::update(Time time)
{
	this->_position = getNextPosition(time.getCurrentTime());
	_corrections.clear();
	_velocity = getNextVelocity(time.getCurrentTime());
	_pulses.clear();
	_pulseAccumulators.clear();
	_forces = getNextForces();
}

template<int n>
Vector<n, double> PhysicPoint<n>::getNextVelocity(double time) const
{
	Vector<n, double> velocity = _velocity;

	for (auto i : getNextForces()) {
		velocity += (i.second / _mass) * time;
	}
	
	for (auto i : getNextPulses()) {
		velocity += (i.second / _mass);
	}

	return velocity;
}

template<int n>
Vector<n, double> PhysicPoint<n>::getNextPosition(double time) const
{
	Vector<n, double> position = this->_position + (_velocity + getNextVelocity(time)) * time / 2;
	
	for (auto& correction : _corrections) {
		position += correction.second.value();
	}

	return position;
}

template<int n>
map<string, Vector<n, double>> PhysicPoint<n>::getNextForces() const
{
	auto forces = _forces;

	for (auto& i : _rules) {
		forces[i.first] = i.second->getResult(*this);
	}

	return forces;
}

template<int n>
Vector<n, double> PhysicPoint<n>::getPulse(const string type) const
{
	auto it = _pulses.find(type);

	if (it == _pulses.end()) {
		return Vector<n, double>();
	}
	
	return it->second;
}

template<int n>
Vector<n, double> PhysicPoint<n>::getNextPulse(const string type) const
{
	auto pulses = getNextPulses();
	auto it = pulses.find(type);

	if (it == pulses.end()) {
		return Vector<n, double>();
	}
	
	return it->second;
}

template<int n>
void PhysicPoint<n>::setPulse(const string type, const Vector<n, double> pulse)
{
	_pulses[type] = pulse;
}

template<int n>
const map<string, Vector<n, double>>& PhysicPoint<n>::getForce() const
{
	return _forces;
}

template<int n>
map<string, Vector<n, double>>& PhysicPoint<n>::getForce()
{
	return _forces;
}

template<int n>
const map<string, Vector<n, double>>& PhysicPoint<n>::getPulse() const
{
	return _pulses;
}

template<int n>
map<string, Vector<n, double>>& PhysicPoint<n>::getPulse()
{
	return _pulses;
}

template<int n>
Vector<n, double> PhysicPoint<n>::getForce(const string type) const
{
	auto force = _forces.find(type);

	if (force == _forces.end()) {
		return Vector<n, double>();
	}

	return force->second;
}

template<int n>
map<string, unique_ptr<Rule<n>>>& PhysicPoint<n>::getRule()
{
	return _rules;
}

template<int n>
const map<string, unique_ptr<Rule<n>>>& PhysicPoint<n>::getRule() const
{
	return _rules;
}

template<int n>
void PhysicPoint<n>::setRule(const string tag, unique_ptr<Rule<n>> rule)
{
	_rules[tag] = move(rule);
}

template<int n>
Vector<n, double> PhysicPoint<n>::momentum() const
{
	return _velocity * _mass;
}

template<int n>
Vector<n, double> PhysicPoint<n>::getPosition() const
{
	return this->_position;
}

template<int n>
void PhysicPoint<n>::correctPosition(const string profile, const Vector<n, double> amount)
{
	lock_guard<mutex> lock{_correctionMutex};
	_corrections[profile] += amount;
}

template<int n>
void PhysicPoint<n>::accumulatePulse(const string type, Vector<n, double> pulse)
{
	lock_guard<mutex> lock{_pulseAccumulatorMutex};
	_pulseAccumulators[type] += pulse;
	
}

template<int n>
std::map<std::string, Vector<n, double>> PhysicPoint<n>::getNextPulses() const
{
	auto pulses = _pulses;
	
	for (auto& accumulator : _pulseAccumulators) {
		pulses[accumulator.first] += accumulator.second.value();
	}
	
	return pulses;
}

template class PhysicPoint<2>;
template class PhysicPoint<3>;

}
