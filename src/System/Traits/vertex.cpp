#include "vertex.h"

namespace sbg {
namespace Traits {

Vertex::Vertex()
{

}

Vertex::~Vertex()
{

}

const std::list<Vector2d>& Vertex::getVertex() const
{
	return _vertex;
}

std::list< Vector2d >& Vertex::getVertex()
{
	return _vertex;
}

}
}
