#pragma once

#include <set>
#include <memory>

#include "../system.hpp"
#include "aabb_able.h"

namespace subgine {
namespace collision {

class QuadTree : public AABB_able
{
public:
	using container = std::set<std::weak_ptr<const subgine::collision::AABB_able>, std::owner_less<std::weak_ptr<const subgine::collision::AABB_able>>>;
	
	QuadTree(std::pair<subgine::Vector2d, subgine::Vector2d> box = std::pair<subgine::Vector2d, subgine::Vector2d>(subgine::Vector2d(), subgine::Vector2d()));
	QuadTree(const QuadTree& other);
	
	void setSize(subgine::Vector2d size);
	void setPosition(subgine::Vector2d position);
	subgine::Vector2d getSize() const;
	subgine::Vector2d getPosition() const;
	void add(std::weak_ptr< const subgine::collision::AABB_able > object);
	
	container getNearby(const subgine::collision::AABB_able& other) const;
	container& getObjects();
	const container& getObjects() const;
	
	virtual std::pair< subgine::Vector2d, subgine::Vector2d > getBoundingBox() const;
	virtual CollisionEntity* clone() const;
	
private:
	void subdivide(std::weak_ptr< const subgine::collision::AABB_able > object);
	void pushDown();
	
	std::pair< subgine::Vector2d, subgine::Vector2d > getChildBoundingBox(int position) const;
	std::pair<subgine::Vector2d, subgine::Vector2d> _boundingBox;
	std::array<std::unique_ptr<QuadTree>, 4> _nodes;
	container _objects;
};

}
}