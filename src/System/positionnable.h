#pragma once

#include "vector.h"

namespace subgine
{
	
	template<int n>
	class Positionnable
	{
		
	public:
		Positionnable();
		virtual ~Positionnable();
		
		virtual Vector<n, double> getPosition() const = 0;
	};
	
}

