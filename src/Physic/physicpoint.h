
#pragma once

#include "../system.hpp"

#include <vector>
#include <map>
#include "abstractphysicpoint.h"
#include "Rules/rule.h"

namespace sbg {

template<int n>
class PhysicPoint : public AbstractPhysicPoint, public Positionnable<n>, public virtual Traits::Position<n>
{
public:
	PhysicPoint();
	~PhysicPoint();
	PhysicPoint<n>& operator= (const PhysicPoint<n>& c);
	
	void setVelocity(const Vector<n, double> velocity);
	Vector<n, double> getVelocity() const;
	
	Vector<n, double> getPosition() const;
	void setPosition(const Vector<n, double> posision);
	void correctPosition(const std::string profile, const Vector<n, double> amount);
	
	Vector<n, double> momentum() const;
	
	void update(const double time) override;
	
	std::map<std::string, Vector<n, double>>& getPulse();
	const std::map<std::string, Vector<n, double>>& getPulse() const;
	void setPulse(const std::string type, const Vector<n, double> pulse);
	Vector<n, double> getPulse(const std::string type) const;
	
	void setRule(const std::string tag, Rule::Rule<n>* rule);
	std::map<std::string, Rule::Rule<n>*>& getRule();
	Rule::Rule<n>& getRule(const std::string tag);
	const std::map<std::string, Rule::Rule<n>*>& getRule() const;
	const Rule::Rule<n>& getRule(const std::string tag) const;
	
	void setForce(const std::string type, const Vector<n, double> force);
	Vector<n, double> getForce(const std::string type) const;
	std::map<std::string, Vector<n, double>>& getForce();
	const std::map<std::string, Vector<n, double>>& getForce() const;
	
	Vector<n, double> getNextPosition(const double time) const;
	virtual Vector<n, double> getNextVelocity(const double time) const;
	virtual std::map<std::string, Vector<n, double>> getNextForces() const;

protected:
	Vector<n, double> _velocity;
	std::map<std::string, Vector<n, double>> _pulses;
	std::map<std::string, Rule::Rule<n>*> _rules;
	std::map<std::string, Vector<n, double>> _forces;
	std::map<std::string, std::vector<Vector<n, double>>> _corrections;

};

extern template class PhysicPoint<2>;
extern template class PhysicPoint<3>;

typedef PhysicPoint<2> PhysicPoint2;
typedef PhysicPoint<3> PhysicPoint3;

}

