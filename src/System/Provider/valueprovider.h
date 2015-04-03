#pragma once

#include "../clonable.h"

namespace sbg {

template<typename T>
struct ValueProvider : virtual Clonable {
	virtual T getValue() const = 0;
	virtual ValueProvider* clone() const = 0;
};

}
