#pragma once

class CollisionResult;

namespace Collisionnable{class Collisionnable;}

class CollisionHandler
{
public:
	CollisionHandler() = default;
	virtual ~CollisionHandler();

	
	virtual void apply(Collisionnable::Collisionnable& object, const Collisionnable::Collisionnable& other, CollisionResult& result) = 0;
};
