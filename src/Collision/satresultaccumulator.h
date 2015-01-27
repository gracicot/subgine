#pragma once

#include "../system.hpp"

namespace sbg {

class SatResult;

template<>
class Accumulator<SatResult>
{
public:
	Accumulator();
	void operator+=(SatResult value);
	operator SatResult() const;
	void clear();
	bool empty() const;
	int count() const;
	
private:
	Vector2d _total;
	std::vector<Vector2d> _contacts;
	int _count;
};

}
