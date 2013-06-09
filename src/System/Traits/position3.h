#pragma once

#include "../vector3.h"

namespace Traits{

class Position3 : Positionnable3
{
public:
	Position3();
	virtual ~Position3();
	
	virtual Vector3 getPosition() const;
	
protected:
	Vector3 _position;
};

}
