#pragma once

#include "../system.hpp"

#include "CollisionHandlers/collisionhandler.h"
#include "CollisionResults/collisionresult.h"

namespace Collisionnable
{

class Collisionnable
{
public:
	Collisionnable();
	virtual ~Collisionnable();
	
	void removeCollisionHandler(std::string tag);
	void addCollisionHandler(CollisionHandler* handler, std::string tag);
	void trigger(Collisionnable& other, CollisionResult* result, std::string tag);

protected:
	std::map<std::string, CollisionHandler*> _collisionhandlers;
};

}
