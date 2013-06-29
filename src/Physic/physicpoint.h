#pragma once

#include "abstractphysicpoint.h"
#include "../System/Traits/position.h"
namespace subgine
{
namespace physic
{

namespace Rule
{
class Rule;
}

class PhysicPoint : public virtual Traits::Position, public AbstractPhysicPoint
{
public:
	PhysicPoint();
	PhysicPoint(const PhysicPoint& c);
	virtual ~PhysicPoint();
	PhysicPoint& operator= (const PhysicPoint&);

	Vector2 momentum() const;

	//set
	void setPosition(const Vector2 posision);
	void setVelocity(const Vector2 velocity);
	void setForce(const std::string type, const Vector2 force);
	void setPulse(const std::string type, const Vector2 pulse);
	void setRule(const std::string tag, Rule::Rule* rule);

	//update function
	void updateVelocity(const double time);
	void updatePosition(const double time);
	void applyRules();

	//get
	Vector2 getVelocity() const;

	Vector2 getForce(const std::string type) const;
	std::map<std::string, Vector2>& getForce();
	const std::map<std::string, Vector2>& getForce() const;

	Vector2 getPulse(const std::string type) const;
	std::map<std::string, Vector2>& getPulse();
	const std::map<std::string, Vector2>& getPulse() const;

	Rule::Rule& getRule(const std::string type);
	const Rule::Rule& getRule(const std::string tag) const;
	std::map<std::string, Rule::Rule*>& getRule();
	const std::map<std::string, Rule::Rule*>& getRule() const;

protected:
	Vector2 _velocity;
	std::map<std::string, Vector2> _pulses;
	std::map<std::string, Rule::Rule*> _rules;
	std::map<std::string, Vector2> _forces;

};
}
}

