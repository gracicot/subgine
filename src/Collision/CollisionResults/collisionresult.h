#pragma once

#include "../../system.hpp"

#include <memory>

namespace sbg {

class Entity;
class ResultData;

class CollisionResult
{
public:
	CollisionResult();
	CollisionResult(std::weak_ptr<const Entity> other, const bool colliding, std::unique_ptr<const ResultData> data, Time time);
	CollisionResult(const CollisionResult& other);

	bool isColliding() const;
	void colliding(const bool colliding);

	Time getTime() const;
	void setTime(Time time);
	
	std::shared_ptr<const Entity> getOther() const;
	void setOther(std::weak_ptr<const Entity> other);
	
	const ResultData* getData() const;
	void setData(std::unique_ptr<const ResultData> data);

private:
	std::unique_ptr<const ResultData> _data;
	std::weak_ptr<const Entity> _other;
	bool _colliding;
	Time _time;
};

}
