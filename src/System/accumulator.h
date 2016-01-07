#pragma once

namespace sbg {

template<typename T>
struct Accumulator {
	virtual void operator+=(T value) = 0;
	virtual T value() const = 0;
	virtual void clear() = 0;
	virtual bool empty() const = 0;
	virtual int count() const = 0;
};

}
