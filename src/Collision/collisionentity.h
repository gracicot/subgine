#pragma once

class CollisionEntity
{
public:
	CollisionEntity();
	virtual CollisionEntity* clone() const =0;
	virtual ~CollisionEntity();
};
