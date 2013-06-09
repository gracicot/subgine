#pragma once

#include "../../system.hpp"

#include "../collisionnable.h"
#include "../CollisionTesters/collisiontester.h"

class Collision : public Engine
{

public:
	Collision();
	virtual ~Collision();

	virtual void execute(const float time);
	
	CollisionTester& getTester(const std::string tag);
	const CollisionTester& getTester(const std::string tag) const;
	
	void addTester(CollisionTester* tester, const std::string tag);
	void addData(Collisionnable::Collisionnable* object, std::list< std::string > testers);
	void removeData(Collisionnable::Collisionnable& object);
	
protected:
	std::map<Collisionnable::Collisionnable*, std::list<std::string>> _objects;
	std::map<std::string, CollisionTester*> _testers;
};
