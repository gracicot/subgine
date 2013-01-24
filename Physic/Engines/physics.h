#ifndef DEF_PHYSICS_ENGINE
#define DEF_PHYSICS_ENGINE

#include "../../system.hpp"
#include "../physicpoint.h"

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
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
