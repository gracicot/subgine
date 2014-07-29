#include "aabb_able.h"

subgine::Vector2d subgine::collision::AABB_able::boxOverlap(const subgine::collision::AABB_able& other) const
{
	auto boundingBoxThis = getBoundingBox();
	auto boundingBoxOther = other.getBoundingBox();

	if (
	    boundingBoxThis.second.x < boundingBoxOther.first.x ||
	    boundingBoxThis.second.y < boundingBoxOther.first.y ||
	    boundingBoxThis.first.x > boundingBoxOther.second.x ||
	    boundingBoxThis.first.y > boundingBoxOther.second.y
	) {
		const Vector2& amin = boundingBoxThis.first;
		const Vector2& amax = boundingBoxThis.second;
		const Vector2& bmin = boundingBoxOther.first;
		const Vector2& bmax = boundingBoxOther.second;

		Vector2 mtd;

		double left = (bmin.x - amax.x);
		double right = (bmax.x - amin.x);
		double top = (bmin.y - amax.y);
		double bottom = (bmax.y - amin.y);

		if (std::abs(left) < right) {
			mtd.x = left;
		} else {
			mtd.x = right;
		}

		if (std::abs(top) < bottom) {
			mtd.y = top;
		} else {
			mtd.y = bottom;
		}

		if (std::abs(mtd.x) < std::abs(mtd.y)) {
			mtd.x = 0;
		} else {
			mtd.x = 0;
		}

		return mtd;
	} else {
		return Vector2d();
	}
}

bool subgine::collision::AABB_able::isboxOverlapping(const subgine::collision::AABB_able& other) const
{
	auto boundingBoxThis = getBoundingBox();
	auto boundingBoxOther = other.getBoundingBox();

	return !(
		boundingBoxThis.second.x < boundingBoxOther.first.x ||
		boundingBoxThis.second.y < boundingBoxOther.first.y ||
		boundingBoxThis.first.x > boundingBoxOther.second.x ||
		boundingBoxThis.first.y > boundingBoxOther.second.y
	);
}

bool subgine::collision::AABB_able::isContaining(const subgine::collision::AABB_able& other) const
{
	auto boundingBoxThis = getBoundingBox();
	auto boundingBoxOther = other.getBoundingBox();
	
	return (
		boundingBoxThis.first.x <= boundingBoxOther.first.x &&
		boundingBoxThis.first.y <= boundingBoxOther.first.y &&
		boundingBoxThis.second.x >= boundingBoxOther.second.x &&
		boundingBoxThis.second.y >= boundingBoxOther.second.y 
	);
}
