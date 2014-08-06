#include "quadtree.h"

#include <iostream>
#include <algorithm>

using namespace subgine;

namespace subgine {
namespace collision {

QuadTree::QuadTree(std::pair< subgine::Vector2d, subgine::Vector2d > box): _boundingBox(box)
{
	
}

QuadTree::QuadTree(const QuadTree& other)
{
	_boundingBox = other._boundingBox;
	_objects = other._objects;
	for (int i = 0 ; i<_nodes.size() ; i++) {
		_nodes[i] = std::unique_ptr<QuadTree>(dynamic_cast<QuadTree*>(other._nodes[i]->clone()));
	}
}

std::pair< subgine::Vector2d, subgine::Vector2d > QuadTree::getChildBoundingBox(int position) const
{
	switch (position) {
		case 0:
		{
			return {getPosition(), {getPosition().x + (getSize().x / 2), getPosition().y + (getSize().y / 2)}};
			break;
		}
		case 1:
		{
			return {{getPosition().x + (getSize().x / 2), getPosition().y},{getPosition().x + (getSize().x), getPosition().y + (getSize().y / 2)}};
			break;
		}
		case 2:
		{
			return {{getPosition().x, getPosition().y + (getSize().y / 2)}, {getPosition().x + (getSize().x / 2), getPosition().y + getSize().y}};
			break;
		}
		case 3:
		{
			return {{getPosition().x + (getSize().x / 2), getPosition().y + (getSize().y / 2)}, getPosition() + getSize()};
			break;
		}
	}
}

void QuadTree::add(std::weak_ptr< const subgine::collision::AABB_able > object)
{
	auto obj = object.lock();
	if (isContaining(*obj) && (obj->getBoundingBox().first - obj->getBoundingBox().second).notZero()) {
		subdivide(object);
	}
	pushDown();
}

void QuadTree::subdivide(std::weak_ptr< const collision::AABB_able > object)
{
	auto obj = object.lock();
	if (isboxOverlapping(*obj) && (obj->getBoundingBox().first - obj->getBoundingBox().second).notZero()) {
		for (int i = 0 ; i<_nodes.size() ; i++) {
			auto box = getChildBoundingBox(i);
			auto& node = _nodes[i];
			
			if (!node) {
				node = std::unique_ptr<QuadTree>(new QuadTree(box));
			}
			
			if (node->isContaining(*obj)) {
				node->subdivide(object);
			} else if (node->isboxOverlapping(*obj)) {
				node->_objects.insert(object);
			} else {
				_objects.insert(object);
			}
		}
	}
}

void QuadTree::pushDown()
{
	auto it = _objects.begin();
	while(it!=_objects.end()) {
		auto current = it++;
		bool inserted = false;
		for (auto& node : _nodes) {
			if (node) {
				if (!current->expired()) {
					auto closePtr = current->lock();
					if (node->isboxOverlapping(*closePtr)) {
						node->_objects.insert(*current);
						inserted = true;
					}
				}
			}
		}
		if (inserted) {
			_objects.erase(current);
		}
	}
	for (auto& node : _nodes) {
		if (node) { 
			if (node->_objects.size() != 0) {
				node->pushDown();
			}
		}
	}
}

QuadTree::container QuadTree::getNearby(const collision::AABB_able& other) const
{
	container object = _objects;
	
	for (auto& node : _nodes) {
		if (node && node->isboxOverlapping(other)) {
			auto nodeObjects = node->getNearby(other);
			object.insert(nodeObjects.begin(), nodeObjects.end());
		}
	}
	
	return object;
}

subgine::collision::CollisionEntity* QuadTree::clone() const
{
	return new QuadTree(*this);
}

std::pair< subgine::Vector2d, subgine::Vector2d > QuadTree::getBoundingBox() const
{
	return _boundingBox;
}

subgine::Vector2d QuadTree::getPosition() const
{
	return _boundingBox.first;
}

subgine::Vector2d QuadTree::getSize() const
{
	return _boundingBox.second - _boundingBox.first;
}

void QuadTree::setPosition(subgine::Vector2d position)
{
	subgine::Vector2d size = getSize();
	_boundingBox.first = position;
	setSize(size);
}

void QuadTree::setSize(subgine::Vector2d size)
{
	_boundingBox.second = size + _boundingBox.first;
}

const QuadTree::container& QuadTree::getObjects() const
{
	return _objects;
}

QuadTree::container& QuadTree::getObjects()
{
	return _objects;
}

}
}