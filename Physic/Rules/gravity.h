#ifndef GRAVITY_H
#define GRAVITY_H

#include "rule.h"
#include "../physicpoint.h"

namespace Rule
{

class Gravity : public Rule
{
public:
	Gravity(const Vector2 value = Vector2());
	Gravity(const Gravity& c);
	virtual ~Gravity();
	
	virtual Vector2 getResult(const PhysicPoint& object) const;
	
	void setValue(const Vector2 value);
	Vector2 getValue() const;
	
private:
	Vector2 _value;
};

}
#endif // GRAVITY_H
