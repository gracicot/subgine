#pragma once

#include "../system.hpp"

#include <vector>
#include <map>
#include "abstractphysicpoint.h"
#include "Rules/rule.h"
#include "pulseaccumulator.h"

namespace sbg {

template<int n>
struct PhysicPoint : AbstractPhysicPoint {
	PhysicPoint();
	~PhysicPoint();
	PhysicPoint(const PhysicPoint&) = delete;
	PhysicPoint& operator=(const PhysicPoint&) = delete;
	PhysicPoint(PhysicPoint&&);
	PhysicPoint& operator=(PhysicPoint&&);
	
	void setVelocity(const Vector<n, double> velocity);
	Vector<n, double> getVelocity() const;
	
	Vector<n, double> getPosition() const;
	void setPosition(const Vector<n, double> posision);
	void correctPosition(const std::string profile, const Vector<n, double> amount);
	
	Vector<n, double> momentum() const;
	
	void update(Time time) override;
	
	virtual void accumulatePulse(const std::string type, Vector<n, double> pulse);
	std::map<std::string, Vector<n, double>>& getPulse();
	const std::map<std::string, Vector<n, double>>& getPulse() const;
	void setPulse(const std::string type, const Vector<n, double> pulse);
	Vector<n, double> getPulse(const std::string type) const;
	Vector<n, double> getNextPulse(const std::string type) const;
	
	void setRule(const std::string tag, std::unique_ptr<Rule<n>> rule);
	std::map<std::string, std::unique_ptr<Rule<n>>>& getRule();
	Rule<n>* getRule(const std::string tag);
	const std::map<std::string, std::unique_ptr<Rule<n>>>& getRule() const;
	const Rule<n>* getRule(const std::string tag) const;
	bool hasRule(std::string tag) const;
	
	void removeRule(std::string tag);
	
	void setForce(const std::string type, const Vector<n, double> force);
	Vector<n, double> getForce(const std::string type) const;
	std::map<std::string, Vector<n, double>>& getForce();
	const std::map<std::string, Vector<n, double>>& getForce() const;
	
	std::map<std::string, Vector<n, double>> getNextPulses() const;
	Vector<n, double> getNextPosition(double time) const;
	virtual Vector<n, double> getNextVelocity(double time) const;
	virtual std::map<std::string, Vector<n, double>> getNextForces() const;

protected:
	Vector<n, double> _velocity;
	Vector<n, double> _position;
	std::map<std::string, Vector<n, double>> _pulses;
	std::map<std::string, std::unique_ptr<Rule<n>>> _rules;
	std::map<std::string, Vector<n, double>> _forces;
	std::map<std::string, AvgAccumulator<Vector<n, double>>> _corrections;
	std::map<std::string, PulseAccumulator<n>> _pulseAccumulators;
	std::mutex _correctionMutex;
	std::mutex _pulseAccumulatorMutex;
};

extern template struct PhysicPoint<2>;
extern template struct PhysicPoint<3>;

using PhysicPoint2D = PhysicPoint<2>;
using PhysicPoint3D = PhysicPoint<3>;

}

