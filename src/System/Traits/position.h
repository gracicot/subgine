#pragma once

#include "../vector.h"

namespace sbg
{
namespace Traits
{

template<int n>
class Position
{
protected:
	Vector<n, double> _position;
};

typedef Position<3> Position3;
typedef Position<2> Position2;

}
}
