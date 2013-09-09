#pragma once

#include "../vector2.h"
namespace subgine
{
namespace Traits
{

class Position
{
public:
	Position();
	virtual ~Position();

protected:
	Vector2 _position;
};

}

}
