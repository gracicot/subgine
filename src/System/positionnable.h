#pragma once

#include "vector.h"

namespace subgine
{
	template<int n>
	class Positionnable
	{
	public:
		virtual Vector<n, double> getPosition() const = 0;
	};
	
	typedef Positionnable<3> Positionnable3;
	typedef Positionnable<2> Positionnable2;
}
