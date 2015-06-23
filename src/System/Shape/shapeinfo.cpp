#include "shapeinfo.h"

#include <utility>

using namespace std;

namespace sbg {

template<int n>
ShapeInfo<n, shape::NSphere<n>>::ShapeInfo(const shape::NSphere<n>& sphere) : _sphere{sphere} {}

template<int n>
ShapeInfo<n, shape::NSphere<n>>::ShapeInfo(shape::NSphere<n>&& sphere) : _sphere{move(sphere)} {}

template<int n>
Vector<n, double> ShapeInfo<n, shape::NSphere<n>>::getCenterOfMass() const
{
 	return {0};
}

template <>
Vector<freedom(2), double> ShapeInfo<2, shape::NSphere<2>>::getMomentOfInertia(double mass) const
{
	return {mass * power<2>(_sphere.getRadius()) * 0.5};
}

template <>
Vector<freedom(3), double> ShapeInfo<3, shape::NSphere<3>>::getMomentOfInertia(double mass) const
{
	return {mass * power<2>(_sphere.getRadius()) * 0.4};
}

template<int n>
shape::NSphere<n> ShapeInfo<n, shape::NSphere<n>>::getNSphere() const
{
	return _sphere;
}

template<int n>
void ShapeInfo<n, shape::NSphere<n>>::setNSphere(const shape::NSphere<n>& sphere)
{
	_sphere = sphere;
}

template<int n>
void ShapeInfo<n, shape::NSphere<n>>::setNSphere(shape::NSphere<n>&& sphere)
{
	_sphere = move(sphere);
}

template<int n>
ShapeInfo<n, shape::Polytope<n>>::ShapeInfo(const shape::Polytope<n>& polytope): _polytope{polytope} {}

template<int n>
ShapeInfo<n, shape::Polytope<n>>::ShapeInfo(shape::Polytope<n>&& polytope): _polytope{move(polytope)} {}

template<>
Vector<freedom(2), double> ShapeInfo<2, shape::Polytope<2>>::getMomentOfInertia(double mass) const
{
	// TODO: todo
	return mass;
}

template<>
Vector<freedom(3), double> ShapeInfo<3, shape::Polytope<3>>::getMomentOfInertia(double mass) const
{
	// one day, this function shall be complete.
	return mass;
}

template<int n>
Vector<n, double> ShapeInfo<n, shape::Polytope<n>>::getCenterOfMass() const
{
	// TODO: be more precise, this may work only with triangles, rectangles and regular polygon.
	Vector<n, double> average;
	const auto& vertices = _polytope.getVertices();
	for (auto vertex : vertices) {
		average += vertex;
	}
	return average / vertices.size();
}

template<int n>
shape::Polytope<n> ShapeInfo<n, shape::Polytope<n>>::getPolytope() const
{
	return _polytope;
}

template<int n>
void ShapeInfo<n, shape::Polytope<n>>::setPolytope(const shape::Polytope<n>& polytope)
{
	_polytope = polytope;
}

template<int n>
void ShapeInfo<n, shape::Polytope<n>>::setPolytope(shape::Polytope<n>&& polytope)
{
	_polytope = move(polytope);
}

template class ShapeInfo<2, shape::Polytope<2>>;
template class ShapeInfo<2, shape::NSphere<2>>;
template class ShapeInfo<3, shape::Polytope<3>>;
template class ShapeInfo<3, shape::NSphere<3>>;


}