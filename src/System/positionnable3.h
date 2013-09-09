#pragma once

#include "vector3.h"

namespace subgine
{

class Positionnable3
{

public:
	Positionnable3();
	virtual ~Positionnable3();

	virtual Vector3 getPosition() const = 0;
};

}

