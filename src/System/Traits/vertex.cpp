#include "vertex.h"

namespace Traits{

Vertex::Vertex()
{

}

Vertex::~Vertex()
{
	
}

const std::list<Vector2>& Vertex::getVertex() const
{
	return _vertex;
}

std::list< Vector2 >& Vertex::getVertex()
{
	return _vertex;
}

}