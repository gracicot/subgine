#pragma once
#include "aabb_able.h"

namespace sbg {

class AABBBox : public AABB_able
{
public:
	AABBBox() = default;
	AABBBox(const AABBBox&) = default;
	AABBBox(AABBBox&&) = default;
	AABBBox(std::pair<Vector2d, Vector2d> box);
	~AABBBox() = default;
	
	void setBox(std::pair<Vector2d, Vector2d> box);
	std::pair<Vector2d, Vector2d> getBox() const;
	std::pair< Vector2d, Vector2d > getBoundingBox() const override;
	
private:
	 std::pair<Vector2d, Vector2d> _box;
};

}
