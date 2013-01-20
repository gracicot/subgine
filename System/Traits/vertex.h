#ifndef VERTEX_H
#define VERTEX_H

#include "../../system.hpp"

namespace Traits{

class Vertex
{
public:
	Vertex();
	virtual ~Vertex();
	
	const std::list< Vector >& getVertex() const;
	std::list<Vector>& getVertex();
	
protected:
	std::list<Vector> _vertex;
};

}

#endif // VERTEX_H
