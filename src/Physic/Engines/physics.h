#pragma once

#include "../../system.hpp"
#include "../abstractphysicpoint.h"
namespace subgine
{
namespace physic
{
class Physics : public Container<AbstractPhysicPoint>, public Engine
{
public:
	//constructors and destructor
	Physics();
	~Physics();

	void execute(const double time);

private:

};

}
}
