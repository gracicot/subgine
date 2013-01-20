
#ifndef DEF_PHYSIC_OBJECT3
#define DEF_PHYSIC_OBJECT3

#include "../system.hpp"
#include "abstractphysicpoint.h"
#include "Rules3/rule.h"

class PhysicPoint3 : public virtual Traits::Position3, public AbstractPhysicPoint
{
public:
	PhysicPoint3();
	PhysicPoint3(const PhysicPoint3& c);
	virtual ~PhysicPoint3();
	PhysicPoint3& operator=(const PhysicPoint3&);

	//set
	void setPosition(Vector3 posision);
	void setVelocity(Vector3 velocity);
	void setForce(std::string type, const Vector3 force);
	void setPulse(const std::string pulseType, const Vector3 pulse);
	void setRule(std::string tag, Rule3::Rule* rule);

	//update function
	void updateVelocity(double time);
	void updatePosition(double time);
	void applyRules(double time);

	//get
	Vector3 getVelocity() const;
	Vector3 getPulse(std::string pulseType);
	Vector3 getForce(std::string pulseType);
	Rule3::Rule& getRule(std::string type);
	const Rule3::Rule& getRule(std::string type) const;
	std::map<std::string, Rule3::Rule*>& getRule();
	const std::map<std::string, Rule3::Rule*>& getRule() const;
	std::map<std::string, Vector3>& getForce();
	const std::map<std::string, Vector3>& getForce() const;
	 std::map< std::string, Vector3 >& getPulse();
	const std::map<std::string, Vector3>& getPulse() const;

protected:
	Vector3 _velocity;
	std::map<std::string, Vector3> _pulses;
	std::map<std::string, Rule3::Rule*> _rules;
	std::map<std::string, Vector3> _forces;

};

#endif
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4;
