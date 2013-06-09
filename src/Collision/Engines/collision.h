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
	void add(Collisionnable::Collisionnable* object, std::list< std::string > groups);
	void remove(Collisionnable::Collisionnable& object);
	void remove(Collisionnable::Collisionnable& object, std::list< std::string > groups);
	void clearAll();
	
protected:
	void makeObjectList();
	
	std::map<std::string, std::list<Collisionnable::Collisionnable*>> _groups;
	std::map<std::string, CollisionTester*> _testers;
	
	std::vector<std::tuple<CollisionTester*, Collisionnable::Collisionnable*, Collisionnable::Collisionnable*>> _objects;
};
