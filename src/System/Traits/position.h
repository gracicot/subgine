#pragma once

#include "../vector2.h"
namespace subgine
{
namespace Traits
{

template<int n = 2>
class Position
{
protected:
	Vector<n, double> _position;
};

typedef Position<3> Position3;

}
}
