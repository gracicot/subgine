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
		
		return *this;
    }
    
    template<typename I>
	void add(I first, I end)
	{
		for (auto it = std::move(first) ; it != end ; it++) {
			if (isContaining(**it) && ((*it)->getBoundingBox().first - (*it)->getBoundingBox().second).notZero()) {
				subdivide(*it);
			}
		}
		pushDown();
	}
	
	template<typename  C>
	void add(C&& container) {
		add(container.begin(), container.end());
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
	void subdivide(std::shared_ptr<const T> object)
	{
		for (int i = 0 ; i<_nodes.size() ; i++) {
			auto& node = _nodes[i];
			
			if (!node) {
				node = std::make_unique<QuadTree>(getChildBoundingBox(i));
			}
			
			if (node->isContaining(*object)) {
				node->subdivide(object);
			} else if (node->isboxOverlapping(*object)) {
				node->_objects.emplace(object);
			} else {
				_objects.emplace(object);
			}
		}
		
	}

	void pushDown()
	{
		auto it = _objects.begin();
		bool inserted = false;
		while(it!=_objects.end()) {
			auto current = it++;
			for (auto& node : _nodes) {
				if (node) {
					if (!current->expired()) {
						auto closePtr = current->lock();
						if (node->isboxOverlapping(*closePtr)) {
							node->push(closePtr);
							inserted = true;
						}
					}
				}
			}
		}
		if (inserted) {
			_objects.clear();
		}
		for (auto& node : _nodes) {
			if (node) { 
				if (node->_objects.size() != 0) {
					node->pushDown();
				}
			}
		}
	}
	
	void push(std::shared_ptr<const T>& object) {
		bool inserted = false;
		for (auto& node : _nodes) {
			if (node) {
				if (node->isboxOverlapping(*object)) {
					node->push(object);
					inserted= true;
				}
			}
		}
		
		if (!inserted) {
			_objects.emplace(object);
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