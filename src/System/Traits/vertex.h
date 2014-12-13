#pragma once

#include <list>

#include "../vector2.h"

namespace sbg
{
namespace Traits
{

class Vertex
{
public:
	Vertex();
	virtual ~Vertex();

	const std::list< Vector2d >& getVertex() const;
	std::list<Vector2d>& getVertex();

protected:
	std::list<Vector2d> _vertex;
};

}


}
