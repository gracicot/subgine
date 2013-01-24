
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
	void setPosition(const Vector posision);
	void setVelocity(const Vector velocity);
	void setForce(const std::string type, const Vector force);
	void setPulse(const std::string type, const Vector pulse);
	void setRule(const std::string tag, Rule::Rule* rule);

	//update function
	void updateVelocity(const double time);
	void updatePosition(const double time);
	void applyRules();

	//get
	Vector getVelocity() const;
	
	Vector getForce(const std::string type) const;
	std::map<std::string, Vector>& getForce();
	const std::map<std::string, Vector>& getForce() const;
	
	Vector getPulse(const std::string type) const;
	std::map<std::string, Vector>& getPulse();
	const std::map<std::string, Vector>& getPulse() const;
	
	Rule::Rule& getRule(const std::string type);
	const Rule::Rule& getRule(const std::string type) const;
	std::map<std::string, Rule::Rule*>& getRule();
	const std::map<std::string, Rule::Rule*>& getRule() const;

protected:
	Vector _velocity;
	std::map<std::string, Vector> _pulses;
	std::map<std::string, Rule::Rule*> _rules;
	std::map<std::string, Vector> _forces;

};

#endif
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
