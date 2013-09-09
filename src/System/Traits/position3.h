#pragma once

#include "../vector3.h"
namespace subgine
{
namespace Traits
{

class Position3
{
public:
	Position3();
	virtual ~Position3();

protected:
	Vector3 _position;
};

}
}

