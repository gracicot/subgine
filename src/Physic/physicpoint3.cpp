#include "physicpoint3.h"

#include "../system.hpp"
#include "Rules3/rule.h"

PhysicPoint3::PhysicPoint3()
{
	_mass = 1;
	_lock = false;
}

PhysicPoint3::PhysicPoint3(const PhysicPoint3& c)
{
	_position = c._position;
	_velocity = c._velocity;

	_mass = c._mass;
	_forces.clear();
	_forces.insert(c._forces.begin(), c._forces.begin());
	_pulses.clear();
	_pulses.insert(c._forces.begin(), c._forces.begin());
	_lock = c._lock;
}

PhysicPoint3::~PhysicPoint3()
{
for(auto i : _rules)
	{
		delete i.second;
	}
}

Vector3 PhysicPoint3::getVelocity() const
{
	return _velocity;
}

void PhysicPoint3::setVelocity(const Vector3 velocity)
{
	_velocity = velocity;
}

void PhysicPoint3::setPosition(const Vector3 position)
{
	_position = position;
}

void PhysicPoint3::updatePosition(const double time)
{
	_position += _velocity * time;
}

Rule3::Rule& PhysicPoint3::getRule(const std::string type)
{
	auto it = _rules.find(type);

	if(it != _rules.end())
	{
		return *it->second;
	}

	throw std::out_of_range("Rule " + type + " doesn't exist...");
}

const Rule3::Rule& PhysicPoint3::getRule(const std::string type) const
{
	auto it = _rules.find(type);

	if(it != _rules.end())
	{
		return *it->second;
	}

	throw std::out_of_range("Rule " + type + " doesn't exist...");
}

void PhysicPoint3::setForce(const std::string type, const Vector3 force)
{
	_forces[type] = force;
}

void PhysicPoint3::updateVelocity(const double time)
{
for(auto i : _forces)
	{
		_velocity += (i.second / _mass) * time;
	}

for(auto i : _pulses)
	{

		_velocity += i.second / _mass;
	}

	_pulses.clear();
}

Vector3 PhysicPoint3::getPulse(const std::string type) const
{
	auto pulse = _pulses.find(type);
	
	if(pulse == _pulses.end())
	{
		return Vector3();
	}
	
	return pulse->second;
}

void PhysicPoint3::setPulse(const std::string type, const Vector3 pulse)
{
	_pulses[type] = pulse;
}

const std::map<std::string, Vector3>& PhysicPoint3::getForce() const
{
	return _forces;
}

std::map<std::string, Vector3>& PhysicPoint3::getForce()
{
	return _forces;
}

const std::map<std::string, Vector3>& PhysicPoint3::getPulse() const
{
	return _pulses;
}

std::map<std::string, Vector3>& PhysicPoint3::getPulse()
{
	return _pulses;
}

void PhysicPoint3::applyRules()
{
for(auto i : _rules)
	{
		setForce(i.first, i.second->getResult(*this));
	}
}

Vector3 PhysicPoint3::getForce(const std::string type) const
{
	auto force = _pulses.find(type);
	
	if(force == _pulses.end())
	{
		return Vector3();
	}
	
	return force->second;
}

PhysicPoint3& PhysicPoint3::operator=(const PhysicPoint3& c)
{
	_position = c._position;
	_velocity = c._velocity;

	_mass = c._mass;
	_forces.clear();
	_forces.insert(c._forces.begin(), c._forces.begin());
	_pulses.clear();
	_pulses.insert(c._forces.begin(), c._forces.begin());
	_lock = c._lock;
	return *this;
}

std::map<std::string, Rule3::Rule*>& PhysicPoint3::getRule()
{
	return _rules;
}

const std::map<std::string, Rule3::Rule*>& PhysicPoint3::getRule() const
{
	return _rules;
}

void PhysicPoint3::setRule(const std::string tag, Rule3::Rule* rule)
{
	auto it = _rules.find(tag);

	if(it == _rules.end())
	{
		_rules[tag] = rule;
	}
	else
	{
		delete it->second;
		it->second = rule;
	}
}

Vector3 PhysicPoint3::momentum() const
{
	return _velocity * _mass;
}
