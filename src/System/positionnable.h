#pragma once

#include "vector.h"
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"

namespace sbg
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
