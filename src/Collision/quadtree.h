#pragma once

#include <set>
#include <memory>

#include "../system.hpp"
#include "aabb_able.h"

namespace sbg {

class QuadTree : public AABB_able
{
public:
	using container = std::set<std::weak_ptr<const AABB_able>, std::owner_less<std::weak_ptr<const AABB_able>>>;
	
	QuadTree(std::pair<Vector2d, Vector2d> box = std::pair<Vector2d, Vector2d>(Vector2d(), Vector2d()));
	QuadTree(const QuadTree& other);
	
	void setSize(Vector2d size);
	void setPosition(Vector2d position);
	Vector2d getSize() const;
	Vector2d getPosition() const;
	void add(std::weak_ptr< const AABB_able > object);
	
	container getNearby(const AABB_able& other) const;
	container& getObjects();
	const container& getObjects() const;
	
	virtual std::pair< Vector2d, Vector2d > getBoundingBox() const;
	virtual CollisionEntity* clone() const;
	
private:
	void subdivide(std::weak_ptr< const AABB_able > object);
	void pushDown();
	
	std::pair< Vector2d, Vector2d > getChildBoundingBox(int position) const;
	std::pair<Vector2d, Vector2d> _boundingBox;
	std::array<std::unique_ptr<QuadTree>, 4> _nodes;
	container _objects;
};

}