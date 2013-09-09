#pragma once

#include "abstractphysicpoint.h"
#include "../System/Traits/position3.h"
#include "../System/positionnable3.h"

namespace subgine
{
namespace physic
{
namespace Rule3
{
class Rule;
}

class PhysicPoint3 : public virtual Traits::Position3, public AbstractPhysicPoint, public Positionnable3
{
public:
	PhysicPoint3();
	PhysicPoint3(const PhysicPoint3& c);
	virtual ~PhysicPoint3();
	PhysicPoint3& operator= (const PhysicPoint3&);

	Vector3 momentum() const;

	//set
	void setPosition(const Vector3 position);
	void setVelocity(const Vector3 velocity);
	void setForce(const std::string type, const Vector3 force);
	void setPulse(const std::string type, const Vector3 pulse);
	void setRule(const std::string tag, Rule3::Rule* rule);

	//update function
	void updateVelocity(const double time);
	void updatePosition(const double time);
	void applyRules();

	//get
	Vector3 getVelocity() const;
	virtual Vector3 getPosition() const;

	Vector3 getPulse(const std::string type) const;
	std::map< std::string, Vector3 >& getPulse();
	const std::map<std::string, Vector3>& getPulse() const;

	Vector3 getForce(const std::string type) const;
	std::map<std::string, Vector3>& getForce();
	const std::map<std::string, Vector3>& getForce() const;

	Rule3::Rule& getRule(const std::string type);
	const Rule3::Rule& getRule(const std::string type) const;
	std::map<std::string, Rule3::Rule*>& getRule();
	const std::map<std::string, Rule3::Rule*>& getRule() const;

protected:
	Vector3 _velocity;
	std::map<std::string, Vector3> _pulses;
	std::map<std::string, Rule3::Rule*> _rules;
	std::map<std::string, Vector3> _forces;

};

}
}
