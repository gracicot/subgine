#pragma once

#include "../vector2.h"

namespace Traits
{

class Position : public Positionnable
{
public:
	Position();
	virtual ~Position();

	virtual Vector2 getPosition() const;

protected:
	Vector2 _position;
};

}
