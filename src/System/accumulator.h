#pragma once

namespace sbg {

template<typename T>
class Accumulator
{
public:
	virtual void operator+=(T value) = 0;
	virtual operator T() const = 0;
	virtual void clear() = 0;
	virtual bool empty() const = 0;
	virtual int count() const = 0;
};

}
