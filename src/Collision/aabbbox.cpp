#include "aabbbox.h"

using namespace std;

namespace sbg {

AABBBox::AABBBox(pair<Vector2d, Vector2d> box) : _box(box)
{

}

pair< Vector2d, Vector2d > AABBBox::getBoundingBox() const
{
	return _box;
}

pair<Vector2d, Vector2d> AABBBox::getBox() const
{
	return _box;
}

void AABBBox::setBox(pair< Vector2d, Vector2d > box)
{
	_box = box;
}

}
