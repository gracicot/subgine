#include "position.h"

namespace Traits{
	
Position::Position(): _position()
{
	
}

Position::~Position()
{
	
}

Vector2 Position::getPosition() const
{
	return _position;
}

}