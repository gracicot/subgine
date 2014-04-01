#pragma once

#include <vector>

#include "../../system.hpp"
#include "../abstractphysicpoint.h"

namespace subgine
{
namespace physic
{
class Physics : public Engine
{
public:
	//constructors and destructor
	Physics();
	~Physics();
	
	void addPhysicEntity(AbstractPhysicPoint* entity);
	void removePhysicEntity(AbstractPhysicPoint* entity);

	void execute(const double time);

private:
	std::vector<AbstractPhysicPoint*> _entites;
};

}
}
