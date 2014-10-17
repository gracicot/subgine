
#pragma once

#include "../system.hpp"

#include <vector>
#include <map>
#include "abstractphysicpoint.h"
#include "Rules/rule.h"

namespace subgine
{
namespace physic
{

template<int n>
class PhysicPoint : public AbstractPhysicPoint, public Positionnable<n>, public virtual Traits::Position<n>
{
public:
	PhysicPoint()
	{
	}
	
	~PhysicPoint()
	{
		for (auto i : _rules) {
			delete i.second;
		}
	}
	
	Vector<n, double> getVelocity() const
	{
		return _velocity;
	}
	
	void setVelocity(const Vector<n, double> velocity)
	{
		_velocity = velocity;
	}
	
	void setPosition(const Vector<n, double> posision)
	{
		this->_position = posision;
	}
	
	Rule::Rule<n>& getRule(const std::string tag)
	{
		auto it = _rules.find(tag);
		
		if (it != _rules.end()) {
			return *it->second;
		}
		
		throw std::out_of_range("Rule " + tag + " doesn't exist...");
	}
	
	const Rule::Rule<n>& getRule(const std::string tag) const
	{
		auto it = _rules.find(tag);
		
		if (it != _rules.end()) {
			return *it->second;
		}
		
		throw std::out_of_range("Rule " + tag + " doesn't exist...");
	}
	
	void setForce(const std::string type, const Vector<n, double> force)
	{
		_forces[type] = force;
	}
	
	void update(const double time) override
	{
		this->_position = getNextPosition(time);
		_corrections.clear();
		_velocity = getNextVelocity(time);
		_pulses.clear();
		_forces = getNextForces();
	}
	
	virtual Vector<n, double> getNextVelocity(const double time) const
	{
		Vector<n, double> velocity = _velocity;
		
		for (auto i : this->getNextForces()) {
			velocity += (i.second / _mass) * time;
		}
		
		for (auto i : _pulses) {
			velocity += (i.second / _mass);
		}
		
		return velocity;
	}
	
	Vector<n, double> getNextPosition(const double time) const
	{
		Vector<n, double> position = this->_position + (_velocity + getNextVelocity(time)) * time/2;
		
		for (auto& correctionList : _corrections) {
			Vector<n, double> average;
			for (auto& correction : correctionList.second) {
				average += correction;
			}
			average / correctionList.second.size();
			
			position += average;
		}
		
		return position;
	}
	
	virtual std::map<std::string, Vector<n, double>> getNextForces() const
	{
		auto forces = _forces;
		
		for (auto i : _rules) {
			forces[i.first] = i.second->getResult(*this);
		}
		
		return forces;
	}
	
	Vector<n, double> getPulse(const std::string type) const
	{
		auto pulse = _pulses.find(type);
		
		if (pulse == _pulses.end()) {
			return Vector<n, double>();
		}
		
		return pulse->second;
	}
	
	void setPulse(const std::string type, const Vector<n, double> pulse)
	{
		_pulses[type] = pulse;
	}
	
	const std::map<std::string, Vector<n, double>>& getForce() const
	{
		return _forces;
	}
	
	std::map<std::string, Vector<n, double>>& getForce()
	{
		return _forces;
	}
	
	const std::map<std::string, Vector<n, double>>& getPulse() const
	{
		return _pulses;
	}
	
	std::map<std::string, Vector<n, double>>& getPulse()
	{
		return _pulses;
	}
	
	Vector<n, double> getForce(const std::string type) const
	{
		auto force = _forces.find(type);
		
		if (force == _forces.end()) {
			return Vector<n, double>();
		}
		
		return force->second;
	}
	
	PhysicPoint<n>& operator= (const PhysicPoint<n>& c)
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
	
	std::map<std::string, Rule::Rule<n>*>& getRule()
	{
		return _rules;
	}
	
	const std::map<std::string, Rule::Rule<n>*>& getRule() const
	{
		return _rules;
	}
	
	void setRule(const std::string tag, Rule::Rule<n>* rule)
	{
		auto it = _rules.find(tag);
		
		if (it == _rules.end()) {
			_rules[tag] = rule;
		} else {
			delete it->second;
			it->second = rule;
		}
	}
	
	Vector<n, double> momentum() const
	{
		return _velocity * _mass;
	}
	
	Vector<n, double> getPosition() const 
	{
		return this->_position;
	}
	
	void correctPosition(const std::string profile, const Vector<n, double> amount)
	{
		_corrections[profile].push_back(amount);
	}

protected:
	Vector<n, double> _velocity;
	std::map<std::string, Vector<n, double>> _pulses;
	std::map<std::string, Rule::Rule<n>*> _rules;
	std::map<std::string, Vector<n, double>> _forces;
	std::map<std::string, std::vector<Vector<n, double>>> _corrections;

};

typedef PhysicPoint<2> PhysicPoint2;
typedef PhysicPoint<3> PhysicPoint3;

}
}

