#include "aabbbox.h"

subgine::collision::AABBBox::AABBBox(std::pair< subgine::Vector2d, subgine::Vector2d > box) : _box(box)
{

}

subgine::collision::CollisionEntity* subgine::collision::AABBBox::clone() const
{
	return new AABBBox(*this);
}

std::pair< subgine::Vector2d, subgine::Vector2d > subgine::collision::AABBBox::getBoundingBox() const
{
	return _box;
}

std::pair< subgine::Vector2d, subgine::Vector2d > subgine::collision::AABBBox::getBox() const
{
	return _box;
}

void subgine::collision::AABBBox::setBox(std::pair< subgine::Vector2d, subgine::Vector2d > box)
{
	_box = box;
}
