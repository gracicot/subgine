#pragma once

#include "../../system.hpp"
#include "../abstractphysicpoint.h"

class Physics : public Container<AbstractPhysicPoint>, public Engine
{
public:
	//constructors and destructor
	Physics();
	~Physics();

	void execute(const float time);

private:

};
