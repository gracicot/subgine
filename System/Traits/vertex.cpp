#include "vertex.h"

namespace Traits{

Vertex::Vertex()
{

}

Vertex::~Vertex()
{
	
}

const std::list<Vector>& Vertex::getVertex() const
{
	return _vertex;
}

std::list< Vector >& Vertex::getVertex()
{
	return _vertex;
}

}