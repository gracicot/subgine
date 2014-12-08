#pragma once

namespace subgine
{
	extern const double pi;
	extern const double tau;
	
	constexpr int freedom(int n)
	{
		return n * (n - 1) / 2;
	}
	
	template<int n, class T>
	class Vector;
}

