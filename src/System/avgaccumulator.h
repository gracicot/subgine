#pragma once

#include "accumulator.h"

namespace sbg {

template<typename T>
class AvgAccumulator : public Accumulator<T>
{
public:
	AvgAccumulator() : _total(), _count(0)
	{
		
	}
	void take(T value)
	{
		_total += value;
	}
	
	T flush()
	{
		T result = _total / _count;
		_total = T();
		_count = 0;
		return result;
	}
	
private:
	T _total;
	int _count;
};

}
