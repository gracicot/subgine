#pragma once

#include <vector>
#include "../vector-all.h"

namespace sbg {
namespace shape {

template<int n>
struct Polytope {
	Polytope();
	Polytope(const Polytope<n>& other);
	Polytope<n>& operator=(const Polytope<n>& other);
	Polytope(Polytope<n>&&);
	Polytope<n>& operator=(Polytope<n>&& other);
	explicit Polytope(std::vector<Vector<n, double>>&& vertices);
	explicit Polytope(const std::vector<Vector<n, double>>& vertices);
	
	void addVertex(Vector<n, double> vertex);
	const std::vector<Vector<n, double>>& getVertices() const;
	void setVertices(std::vector<Vector<n, double>>&& vertices);
	void setVertices(const std::vector<Vector<n, double>>& vertices);
	
	constexpr static auto dimensions = n;
	
private:
	std::vector<Vector<n, double>> _vertices;
};

extern template struct Polytope<2>;
extern template struct Polytope<3>;

using Polygon = Polytope<2>;
using Polyhedron = Polytope<3>;

}
}
