#include "physicpoint.h"

#include "../system.hpp"
#include "Rules/rule.h"

PhysicPoint::PhysicPoint()
{
	_position = Vector2(0, 0);
	_velocity = Vector2(0, 0);
	_mass = 1;
	_lock = false;
}

PhysicPoint::PhysicPoint(const PhysicPoint& c)
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

PhysicPoint::~PhysicPoint()
{
for(auto i : _rules)
	{
		delete i.second;
	}
}

Vector2 PhysicPoint::getVelocity() const
{
	return _velocity;
}

void PhysicPoint::setVelocity(const Vector2 velocity)
{
	_velocity = velocity;
}

void PhysicPoint::setPosition(const Vector2 posision)
{
	_position = posision;
}

void PhysicPoint::updatePosition(const double time)
{
	_position += _velocity * time;
}

Rule::Rule& PhysicPoint::getRule(const std::string tag)
{
	std::map<std::string, Rule::Rule*>::iterator it = _rules.find(tag);

	if(it != _rules.end())
	{
		return *it->second;
	}

	throw std::out_of_range("Rule " + tag + " doesn't exist...");
}

const Rule::Rule& PhysicPoint::getRule(const std::string tag) const
{
	std::map<std::string, Rule::Rule*>::const_iterator it = _rules.find(tag);

	if(it != _rules.end())
	{
		return *it->second;
	}

	throw std::out_of_range("Rule " + tag + " doesn't exist...");
}

void PhysicPoint::setForce(const std::string type, const Vector2 force)
{
	_forces[type] = force;
}

void PhysicPoint::updateVelocity(const double time)
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

Vector2 PhysicPoint::getPulse(const std::string type) const
{
	auto pulse = _pulses.find(type);

	if(pulse == _pulses.end())
	{
		return Vector2();
	}

	return pulse->second;
}

void PhysicPoint::setPulse(const std::string type, const Vector2 pulse)
{
	_pulses[type] = pulse;
}

const std::map<std::string, Vector2>& PhysicPoint::getForce() const
{
	return _forces;
}

std::map<std::string, Vector2>& PhysicPoint::getForce()
{
	return _forces;
}

const std::map<std::string, Vector2>& PhysicPoint::getPulse() const
{
	return _pulses;
}

std::map<std::string, Vector2>& PhysicPoint::getPulse()
{
	return _pulses;
}

void PhysicPoint::applyRules()
{
for(auto i : _rules)
	{
		setForce(i.first, i.second->getResult(*this));
	}
}

Vector2 PhysicPoint::getForce(const std::string type) const
{
	auto force = _pulses.find(type);

	if(force == _pulses.end())
	{
		return Vector2();
	}

	return force->second;
}

PhysicPoint& PhysicPoint::operator=(const PhysicPoint& c)
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

std::map<std::string, Rule::Rule*>& PhysicPoint::getRule()
{
	return _rules;
}

const std::map<std::string, Rule::Rule*>& PhysicPoint::getRule() const
{
	return _rules;
}

void PhysicPoint::setRule(const std::string tag, Rule::Rule* rule)
{
	std::map<std::string, Rule::Rule*>::iterator it = _rules.find(tag);

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

// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
