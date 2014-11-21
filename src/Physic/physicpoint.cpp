#include "physicpoint.h"

namespace subgine {
namespace physic {

template<int n>
PhysicPoint<n>::PhysicPoint()
{
}

template<int n>
PhysicPoint<n>::~PhysicPoint()
{
	for (auto i : _rules) {
		delete i.second;
	}
}

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
Rule::Rule<n>& PhysicPoint<n>::getRule(const std::string tag)
{
	auto it = _rules.find(tag);

	if (it != _rules.end()) {
		return *it->second;
	}

	throw std::out_of_range("Rule " + tag + " doesn't exist...");
}

template<int n>
const Rule::Rule<n>& PhysicPoint<n>::getRule(const std::string tag) const
{
	auto it = _rules.find(tag);

	if (it != _rules.end()) {
		return *it->second;
	}

	throw std::out_of_range("Rule " + tag + " doesn't exist...");
}

template<int n>
void PhysicPoint<n>::setForce(const std::string type, const Vector<n, double> force)
{
	_forces[type] = force;
}

template<int n>
void PhysicPoint<n>::update(const double time)
{
	this->_position = getNextPosition(time);
	_corrections.clear();
	_velocity = getNextVelocity(time);
	_pulses.clear();
	_forces = getNextForces();
}

template<int n>
Vector<n, double> PhysicPoint<n>::getNextVelocity(const double time) const
{
	Vector<n, double> velocity = _velocity;

	for (auto i : getNextForces()) {
		velocity += (i.second / _mass) * time;
	}

	for (auto i : _pulses) {
		velocity += (i.second / _mass);
	}

	return velocity;
}

template<int n>
Vector<n, double> PhysicPoint<n>::getNextPosition(const double time) const
{
	Vector<n, double> position = this->_position + (_velocity + getNextVelocity(time)) * time / 2;

	for (auto & correctionList : _corrections) {
		Vector<n, double> average;

		for (auto & correction : correctionList.second) {
			average += correction;
		}

		average / correctionList.second.size();

		position += average;
	}

	return position;
}

template<int n>
std::map<std::string, Vector<n, double>> PhysicPoint<n>::getNextForces() const
{
	auto forces = _forces;

	for (auto i : _rules) {
		forces[i.first] = i.second->getResult(*this);
	}

	return forces;
}

template<int n>
Vector<n, double> PhysicPoint<n>::getPulse(const std::string type) const
{
	auto pulse = _pulses.find(type);

	if (pulse == _pulses.end()) {
		return Vector<n, double>();
	}

	return pulse->second;
}

template<int n>
void PhysicPoint<n>::setPulse(const std::string type, const Vector<n, double> pulse)
{
	_pulses[type] = pulse;
}

template<int n>
const std::map<std::string, Vector<n, double>>& PhysicPoint<n>::getForce() const
{
	return _forces;
}

template<int n>
std::map<std::string, Vector<n, double>>& PhysicPoint<n>::getForce()
{
	return _forces;
}

template<int n>
const std::map<std::string, Vector<n, double>>& PhysicPoint<n>::getPulse() const
{
	return _pulses;
}

template<int n>
std::map<std::string, Vector<n, double>>& PhysicPoint<n>::getPulse()
{
	return _pulses;
}

template<int n>
Vector<n, double> PhysicPoint<n>::getForce(const std::string type) const
{
	auto force = _forces.find(type);

	if (force == _forces.end()) {
		return Vector<n, double>();
	}

	return force->second;
}

template<int n>
PhysicPoint<n>& PhysicPoint<n>::operator= (const PhysicPoint<n>& c)
{
	this->_position = c._position;
	_velocity = c._velocity;

	_mass = c._mass;
	_forces.clear();
	_forces.insert(c._forces.begin(), c._forces.begin());
	_pulses.clear();
	_pulses.insert(c._forces.begin(), c._forces.begin());
	return *this;
}

template<int n>
std::map<std::string, Rule::Rule<n>*>& PhysicPoint<n>::getRule()
{
	return _rules;
}

template<int n>
const std::map<std::string, Rule::Rule<n>*>& PhysicPoint<n>::getRule() const
{
	return _rules;
}

template<int n>
void PhysicPoint<n>::setRule(const std::string tag, Rule::Rule<n>* rule)
{
	auto it = _rules.find(tag);

	if (it == _rules.end()) {
		_rules[tag] = rule;
	} else {
		delete it->second;
		it->second = rule;
	}
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
void PhysicPoint<n>::correctPosition(const std::string profile, const Vector<n, double> amount)
{
	_corrections[profile].push_back(amount);
}

template class PhysicPoint<2>;
template class PhysicPoint<3>;

}
}
