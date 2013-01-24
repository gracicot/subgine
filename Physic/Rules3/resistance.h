#ifndef RESISTANCE_H3
#define RESISTANCE_H3

#include "rule.h"
#include "../physicpoint3.h"

namespace Rule3{

class Resistance : public Rule
{
public:
	Resistance(Vector3 value);
	Resistance(const Resistance& c);
	virtual ~Resistance();
	
	virtual Vector3 getResult(const PhysicPoint3& object) const;
	
	void setValue(Vector3 value);
	Vector3 getValue() const;
	
private:
	Vector3 _value;
};

}

#endif // RESISTANCE_H
