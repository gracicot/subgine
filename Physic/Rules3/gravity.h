#ifndef GRAVITY_H3
#define GRAVITY_H3

#include "rule.h"
#include "../physicpoint3.h"

namespace Rule3
{

class Gravity : public Rule
{
public:
	Gravity(Vector3 value = Vector3(0, 0));
	Gravity(const Gravity& c);
	virtual ~Gravity();
	
	virtual Vector3 apply(const PhysicPoint3& object) const;
	
	void setValue(Vector3 value);
	Vector3 getValue() const;
	
private:
	Vector3 _value;
};

}
#endif // GRAVITY_H
