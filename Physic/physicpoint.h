
#ifndef DEF_PHYSIC_OBJECT
#define DEF_PHYSIC_OBJECT

#include "../system.hpp"
#include "abstractphysicpoint.h"
#include "Rules/rule.h"

class PhysicPoint : public virtual Traits::Position, public AbstractPhysicPoint
{
public:
	PhysicPoint();
	PhysicPoint(const PhysicPoint& c);
	virtual ~PhysicPoint();
	PhysicPoint& operator=(const PhysicPoint&);

	//set
	void setPosision(Vector pos);
	void setPosition(Vector posision);
	void setVelocity(Vector velocity);
	void setForce(std::string forceType, const Vector force);
	void setPulse(const std::string pulseType, const Vector pulse);
	void setRule(std::string tag, Rule::Rule* rule);

	//update function
	void updateVelocity(double time);
	void updatePosition(double time);
	void applyRules();

	//get
	Vector getVelocity() const;
	Vector getForce(std::string forceType);
	Vector getPulse(std::string pulseType);
	Rule::Rule& getRule(std::string type);
	const Rule::Rule& getRule(std::string type) const;
	std::map<std::string, Rule::Rule*>& getRule();
	const std::map<std::string, Rule::Rule*>& getRule() const;
	std::map<std::string, Vector>& getForce();
	const std::map<std::string, Vector>& getForce() const;
	std::map<std::string, Vector>& getPulse();
	const std::map<std::string, Vector>& getPulse() const;

protected:
	Vector _velocity;
	std::map<std::string, Vector> _pulses;
	std::map<std::string, Rule::Rule*> _rules;
	std::map<std::string, Vector> _forces;

};

#endif
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
