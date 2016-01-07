#pragma once

namespace sbg {

struct Clonable {
	virtual Clonable* clone() const = 0;
};

}
