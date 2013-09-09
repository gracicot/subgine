#pragma once

#include "vector2.h"

namespace subgine
{

class Positionnable
{

public:
	Positionnable();
	virtual ~Positionnable();

	virtual Vector2 getPosition() const = 0;
};

}

