#include "polytope.h"

using namespace std;

namespace sbg {
namespace shape {

template<int n>
Polytope<n>::Polytope(){}

template<int n>
Polytope<n>::Polytope(const std::vector<Vector<n, double>>& vertices): _vertices{vertices} {}

template<int n>
Polytope<n>::Polytope(std::vector<Vector<n, double>>&& vertices): _vertices{move(vertices)} {}

template<int n>
Polytope<n>::Polytope(Polytope<n>&& other): _vertices{move(other._vertices)} {}

template<int n>
Polytope<n>::Polytope(const Polytope<n>& other): _vertices{other._vertices} {}

template<int n>
Polytope<n>& Polytope<n>::operator=(const Polytope<n>& other)
{
	_vertices = other._vertices;
	return *this;
}

template<int n>
Polytope<n>& Polytope<n>::operator=(Polytope<n>&& other)
{
	_vertices = move(other._vertices);
	return *this;
}

template<int n>
void Polytope<n>::addVertex(Vector<n, double> vertex)
{
	_vertices.emplace_back(move(vertex));
}

template<int n>
const std::vector<Vector<n, double>>& Polytope<n>::getVertices() const
{
	return _vertices;
}

template<int n>
void Polytope<n>::setVertices(const std::vector<Vector<n, double>>& vertices)
{
	_vertices = vertices;
}

template<int n>
void Polytope<n>::setVertices(std::vector<Vector<n, double>>&& vertices)
{
	_vertices = move(vertices);
}

template struct Polytope<2>;
template struct Polytope<3>;

}
}
