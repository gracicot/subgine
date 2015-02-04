#pragma once

#include "physicpoint.h"

#include <memory>

namespace sbg {

template<int n>
class PhysicBody : public PhysicPoint<n>
{
public:
	typedef Vector<freedom(n), double> Angle;
	
	PhysicBody();

	void update(const double time) override;
	
	virtual Vector<n, double> getNextVelocity(const double time) const override;
	virtual std::map<std::string, Vector<n, double>> getNextForces() const;

	Angle getTorque() const;
	Angle getOrientation() const;
	Angle getAngularVelocity() const;
	
	Angle getNextOrientation(const double time) const;
	Angle getNextAngularVelocity(const double time) const;
	Angle getNextTorque(const double time) const;

	void setOrientation(Angle orientation);
	
	double getMomentOfInertia() const;

	void setShape(std::shared_ptr<shape::Shape<n>> shape);
	std::shared_ptr<shape::Shape<n>> getShape() const;

	void accumulatePulse(const std::string type, Vector<n, double> pulse) override;
	void accumulatePulse(const std::string type, Vector<n, double> pulse, Vector<n, double> position = Vector<n, double>());
	void setPulse(const std::string type, const Vector<n, double> pulse, const Vector<n, double> position = Vector<n, double>());
	void setForce(const std::string type, const Vector<n, double> force, const Vector<n, double> position = Vector<n, double>());
	Vector<n, double> getPulsePosition(std::string type) const;
	Vector<n, double> getForcePosition(std::string type) const;

protected:
	double _momentOfInertia;
	std::shared_ptr<shape::Shape<n>> _shape;
	std::map<std::string, Vector<n, double>> _pulsesPosition;
	std::map<std::string, Vector<n, double>> _forcesPosition;
	std::map<std::string, std::pair<SumAccumulator<Vector<n, double>>, double>> _pulsesPositionAccumulator;
	std::mutex _pulseAccumulationMutex;

	Angle _orientation;
	Angle _angularVelocity;
	Angle _torque;
};

template <> void PhysicBody<2>::update(const double time);
template <> void PhysicBody<3>::update(const double time);

extern template class PhysicBody<2>;
extern template class PhysicBody<3>;

typedef PhysicBody<2> PhysicBody2D;
typedef PhysicBody<3> PhysicBody3D;

}
