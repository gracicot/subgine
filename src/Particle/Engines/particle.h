#pragma once

#include "../../system.hpp"
#include "../../physic.hpp"

namespace subgine
{
namespace particle
{

class ParticleEngine : public Engine, public Container<physic::PhysicPoint>
{
public:
	ParticleEngine() = default;
	~ParticleEngine() = default;

private:
};

}
}
