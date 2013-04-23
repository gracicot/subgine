#ifndef DEF_PHYSICS_ENGINE
#define DEF_PHYSICS_ENGINE

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

#endif

