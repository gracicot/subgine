#ifndef VERTEX_H
#define VERTEX_H

#include "../../system.hpp"

namespace Traits{

class Vertex
{
public:
	Vertex();
	virtual ~Vertex();
	
	const std::list< Vector2 >& getVertex() const;
	std::list<Vector2>& getVertex();
	
protected:
	std::list<Vector2> _vertex;
};

}

#endif // VERTEX_H
