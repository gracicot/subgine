#ifndef ABSTRACTPHYSICPOINT_H
#define ABSTRACTPHYSICPOINT_H

class AbstractPhysicPoint
{
public:
	void setMass(double mass);
	void lock(bool lock);
	
	bool isLock() const;
	double getMass() const;

	virtual void updateVelocity(double time) = 0;
	virtual void updatePosition(double time) = 0;
	virtual void applyRules(double time) = 0;
	
protected:
	double _mass;
	bool _lock;
};

#endif // ABSTRACTPHYSICPOINT_H
