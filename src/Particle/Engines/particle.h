#pragma once

#include "../../system.hpp"
#include "../../physic.hpp"

class ParticleEngine : public Engine, public Container<PhysicPoint>
{
public:
	ParticleEngine() = default;
	~ParticleEngine() = default;
	
private:
};
