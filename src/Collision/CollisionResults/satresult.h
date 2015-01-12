#pragma once

#include "../../system.hpp"

#include "collisionresult.h"
#include "resultdata.h"

#include <vector>

namespace sbg {

class SatResult : public ResultData
{
public:
	SatResult(const Vector2d gap = Vector2d{});

	void setGap(const Vector2d gap);
	Vector2d getGap() const;
	
	void setContacts(std::vector<Vector2d> contacts);
	std::vector<Vector2d> getContacts() const;
	
	SatResult* clone() const override;

private:
	Vector2d _gap;
	std::vector<Vector2d> _contacts;
};

}
