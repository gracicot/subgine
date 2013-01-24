#ifndef GRAVITY_H
#define GRAVITY_H

#include "rule.h"
#include "../physicpoint.h"

namespace Rule
{

class Gravity : public Rule
{
public:
	Gravity(const Vector value = Vector());
	Gravity(const Gravity& c);
	virtual ~Gravity();
	
	virtual Vector getResult(const PhysicPoint& object) const;
	
	void setValue(const Vector value);
	Vector getValue() const;
	
private:
	Vector _value;
};

}
#endif // GRAVITY_H
