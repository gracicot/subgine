#pragma once

#include "../../system.hpp"

#include "collisionresult.h"
#include "resultdata.h"
#include "../satresultaccumulator.h"

#include <vector>
#include <memory>

namespace sbg {

struct SatResult : ResultData {
	using AccumulatorType = Accumulator<SatResult>;
	SatResult(const Vector2d gap = {}, std::vector<Vector2d> contacts = {});

	void setGap(const Vector2d gap);
	Vector2d getGap() const;
	
	void setContacts(std::vector<Vector2d> contacts);
	std::vector<Vector2d> getContacts() const;
	
	SatResult* clone() const override;
	std::unique_ptr<ResultData> reverse() const override;

private:
	Vector2d _gap;
	std::vector<Vector2d> _contacts;
};

}
