#pragma once

namespace subgine
{
	template<int n, class T = double>
	class Vector
	{};
	
	typedef Vector<2> Vector2;
	typedef Vector<3> Vector3;
	typedef Vector<2, float> Vector2f;
	typedef Vector<3, float> Vector3f;
	typedef Vector<2, double> Vector2d;
	typedef Vector<3, double> Vector3d;
}

