#pragma once

#include "../../system.hpp"

template<int n> class PhysicPoint;

namespace subgine
{
namespace physic
{
namespace Rule
{
	
template<int n>
class Rule
{
public:
	virtual Vector<n, double> getResult(const PhysicPoint<n>& object) const = 0;
};

}
}
}
