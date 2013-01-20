#include "physicpoint.h"

PhysicPoint::PhysicPoint()
{
	_position = Vector(0, 0);
	_velocity = Vector(0, 0);
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

Vector PhysicPoint::getVelocity() const
{
	return _velocity;
}

void PhysicPoint::setVelocity(Vector velocity)
{
	_velocity.x = velocity.x;
	_velocity.y = velocity.y;
}

void PhysicPoint::setPosition(Vector posision)
{
	_position = posision;
}

void PhysicPoint::updatePosition(double time)
{
	_position.x += _velocity.x * time;
	_position.y += _velocity.y * time;
}

Rule::Rule& PhysicPoint::getRule(std::string type)
{
	std::map<std::string, Rule::Rule*>::iterator it = _rules.find(type);

	if(it != _rules.end())
	{
		return *it->second;
	}

	throw std::out_of_range("Rule " + type + " doesn't exist...");
}

const Rule::Rule& PhysicPoint::getRule(std::string type) const
{
	std::map<std::string, Rule::Rule*>::const_iterator it = _rules.find(type);

	if(it != _rules.end())
	{
		return *it->second;
	}

	throw std::out_of_range("Rule " + type + " doesn't exist...");
}

void PhysicPoint::setForce(std::string type, const Vector force)
{
	_forces[type] = force;
}

void PhysicPoint::updateVelocity(double time)
{
for(auto i : _forces)
	{
		_velocity.x += (i.second.x / _mass) * time;
		_velocity.y += (i.second.y / _mass) * time;
	}

for(auto i : _pulses)
	{

		_velocity.x += i.second.x / _mass;
		_velocity.y += i.second.y / _mass;
	}

	_pulses.clear();
}

Vector PhysicPoint::getPulse(std::string pulseType)
{
	return _pulses[pulseType];
}

void PhysicPoint::setPulse(const std::string pulseType, const Vector pulse)
{
	_pulses[pulseType] = pulse;
}

const std::map<std::string, Vector>& PhysicPoint::getForce() const
{
	return _forces;
}

std::map<std::string, Vector>& PhysicPoint::getForce()
{
	return _forces;
}

const std::map<std::string, Vector>& PhysicPoint::getPulse() const
{
	return _pulses;
}

std::map<std::string, Vector>& PhysicPoint::getPulse()
{
	return _pulses;
}

void PhysicPoint::applyRules(double time)
{
for(auto i : _rules)
	{
		setForce(i.first, i.second->apply(*this, time));
	}
}

Vector PhysicPoint::getForce(std::string forceType)
{
	return _forces[forceType];
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

void PhysicPoint::setRule(std::string tag, Rule::Rule* rule)
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
