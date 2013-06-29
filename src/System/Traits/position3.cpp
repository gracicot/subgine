#include "position3.h"
namespace subgine
{
namespace Traits
{

Position3::Position3() : _position()
{

}

Position3::~Position3()
{

}

Vector3 Position3::getPosition() const
{
	return _position;
}

}
}
