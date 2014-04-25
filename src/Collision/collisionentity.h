#pragma once

namespace subgine
{
namespace collision
{
class CollisionEntity
{
public:
	CollisionEntity();
	virtual CollisionEntity* clone() const =0;
	virtual ~CollisionEntity();
};

}
}