#ifndef GRAVITY_H
#define GRAVITY_H

#include "rule.h"
#include "../physicpoint.h"

namespace Rule
{

class Gravity : public Rule
{
public:
	Gravity(Vector value = Vector(0, 0));
	Gravity(const Gravity& c);
	virtual ~Gravity();
	
	virtual Vector apply(const PhysicPoint& object) const;
	
	void setValue(Vector value);
	Vector getValue() const;
	
private:
	Vector _value;
};

}
#endif // GRAVITY_H
