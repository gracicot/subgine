#include "aabb_able.h"

using namespace std;

namespace sbg {

Vector2d AABB_able::boxOverlap(const AABB_able& other) const
{
	auto boundingBoxThis = getBoundingBox();
	auto boundingBoxOther = other.getBoundingBox();

	if (
	    boundingBoxThis.second.x < boundingBoxOther.first.x ||
	    boundingBoxThis.second.y < boundingBoxOther.first.y ||
	    boundingBoxThis.first.x > boundingBoxOther.second.x ||
	    boundingBoxThis.first.y > boundingBoxOther.second.y
	) {
		const Vector2d& amin = boundingBoxThis.first;
		const Vector2d& amax = boundingBoxThis.second;
		const Vector2d& bmin = boundingBoxOther.first;
		const Vector2d& bmax = boundingBoxOther.second;

		Vector2d mtd;

		double left = (bmin.x - amax.x);
		double right = (bmax.x - amin.x);
		double top = (bmin.y - amax.y);
		double bottom = (bmax.y - amin.y);

		if (abs(left) < right) {
			mtd.x = left;
		} else {
			mtd.x = right;
		}

		if (abs(top) < bottom) {
			mtd.y = top;
		} else {
			mtd.y = bottom;
		}

		if (abs(mtd.x) < abs(mtd.y)) {
			mtd.x = 0;
		} else {
			mtd.x = 0;
		}

		return mtd;
	} else {
		return Vector2d();
	}
}

bool AABB_able::isboxOverlapping(const AABB_able& other) const
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

bool AABB_able::isContaining(const AABB_able& other) const
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

}
