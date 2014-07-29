#pragma once

namespace subgine
{
namespace collision
{
class CollisionEntity
{
public:
	CollisionEntity() = default;
	virtual CollisionEntity* clone() const =0;
	~CollisionEntity() = default;
};

}
}