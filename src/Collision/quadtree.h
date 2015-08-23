#pragma once

#include <set>
#include <memory>

#include "../system.hpp"
#include "aabb_able.h"

namespace sbg {

template<typename T>
class QuadTree : public AABB_able
{
public:
	using container = std::set<std::weak_ptr<const T>, std::owner_less<std::weak_ptr<const T>>>;
	
	QuadTree(std::pair<Vector2d, Vector2d> box = {}): _boundingBox{box}
	{
		
	}
	
	QuadTree(const QuadTree&) = delete;
	QuadTree& operator=(const QuadTree&) = delete;
	
    QuadTree(QuadTree&& other) : _boundingBox{std::move(other._boundingBox)}, _nodes{std::move(other._nodes)}, _objects{std::move(other._objects)} {}

    QuadTree& operator=(QuadTree&& other) {
		std::swap(_boundingBox, other._boundingBox);
		std::swap(_nodes, other.nodes);
		std::swap(_objects, other._objects);
    }
    
	void add(std::weak_ptr<const T> object)
	{
		if (!object.expired()) {
			auto obj = object.lock();
			if (isContaining(*obj) && (obj->getBoundingBox().first - obj->getBoundingBox().second).notZero()) {
				subdivide(object);
			}
			pushDown();
		}
	}

	container getNearby(const T& other) const
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

	QuadTree<T>* clone() const
	{
		return new QuadTree<T>(*this);
	}

	std::pair<Vector2d, Vector2d> getBoundingBox() const
	{
		return _boundingBox;
	}

	Vector2d getPosition() const
	{
		return _boundingBox.first;
	}

	Vector2d getSize() const
	{
		return _boundingBox.second - _boundingBox.first;
	}

	void setPosition(Vector2d position)
	{
		Vector2d size = getSize();
		_boundingBox.first = position;
		setSize(size);
	}

	void setSize(Vector2d size)
	{
		_boundingBox.second = size + _boundingBox.first;
	}

	const container& getObjects() const
	{
		return _objects;
	}

	container& getObjects()
	{
		return _objects;
	}
	
private:
	void subdivide(std::weak_ptr<const T> object)
	{
		if (!object.expired()) {
			auto obj = object.lock();
			if (isboxOverlapping(*obj) && (obj->getBoundingBox().first - obj->getBoundingBox().second).notZero()) {
				for (int i = 0 ; i<_nodes.size() ; i++) {
					auto box = getChildBoundingBox(i);
					auto& node = _nodes[i];
					
					if (!node) {
						node = std::make_unique<QuadTree>(box);
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
	}

	void pushDown()
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

	std::pair<Vector2d, Vector2d> getChildBoundingBox(int position) const
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
			default:
			{
				return {};
			}
		}
	}
	
	std::pair<Vector2d, Vector2d> _boundingBox;
	std::array<std::unique_ptr<QuadTree<T>>, 4> _nodes;
	container _objects;
};

}