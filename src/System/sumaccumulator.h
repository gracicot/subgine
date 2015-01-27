#pragma once

#include "accumulator.h"

namespace sbg {

template<typename T>
class SumAccumulator : public Accumulator<T>
{
public:
	SumAccumulator() : _total(), _count(0)
	{
		
	}
	
	void operator+=(T value)
	{
		_total += value;
		_count++;
	}
	
	operator T() const
	{
		return _total;
	}
	
	void clear()
	{
		_total = T();
		_count = 0;
	}
	
	bool empty() const
	{
		return _count == 0;
	}
	
	int count() const
	{
		return _count;
	}
	
private:
	T _total;
	int _count;
	
};

}
