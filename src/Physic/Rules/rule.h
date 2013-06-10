#pragma once

#include "../../system.hpp"

class PhysicPoint;

namespace Rule
{

class Rule
{
public:
	Rule();
	Rule(const Rule& c);
	virtual ~Rule();
	virtual Vector2 getResult(const PhysicPoint& object) const = 0;

private:
};

}
