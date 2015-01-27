#pragma once

namespace sbg {

template<typename T>
class Accumulator
{
public:
	void operator+=(T value) = 0;
	operator T() const = 0;
	void clear() = 0;
	bool empty() const = 0;
	int count() const = 0;
};

}
