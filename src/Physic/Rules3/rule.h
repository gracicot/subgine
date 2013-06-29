#pragma once

#include "../../system.hpp"

namespace subgine
{
namespace physic
{
class PhysicPoint3;

namespace Rule3
{

class Rule
{
public:
	Rule();
	Rule(const Rule& c);
	virtual ~Rule();
	virtual Vector3 getResult(const PhysicPoint3& object) const = 0;

private:
};

}
}
}
