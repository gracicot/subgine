#pragma once

#include <set>

#include "../../system.hpp"
#include "../abstractphysicpoint.h"

namespace sbg {

class Physics : public Engine
{
public:
	//constructors and destructor
	Physics();
	~Physics();
	
	void add(std::weak_ptr<AbstractPhysicPoint> entity);
	void remove(std::weak_ptr<AbstractPhysicPoint> entity);

	void execute(const double time);

private:
	std::set<std::weak_ptr<AbstractPhysicPoint>, std::owner_less<std::weak_ptr<AbstractPhysicPoint>>> _objects;
};

}
