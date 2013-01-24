#ifndef RESISTANCE_H
#define RESISTANCE_H

#include "rule.h"
#include "../physicpoint.h"

namespace Rule{

class Resistance : public Rule
{
public:
	Resistance(const Vector value = Vector());
	Resistance(const Resistance& c);
	virtual ~Resistance();
	
	virtual Vector getResult(const PhysicPoint& object) const;
	
	void setValue(const Vector value);
	Vector getValue() const;
	
private:
	Vector _value;
};

}

#endif // RESISTANCE_H
