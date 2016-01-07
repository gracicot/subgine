#pragma once

#include "nsphere.h"
#include "polytope.h"
#include "abstractshapeinfo.h"

namespace sbg {

template<int n, typename T>
struct ShapeInfo;

template<int n>
struct ShapeInfo<n, shape::NSphere<n>> : AbstractShapeInfo<n> {
	ShapeInfo(const shape::NSphere<n>& sphere);
	ShapeInfo(shape::NSphere<n>&& sphere);
	
	Vector<freedom(n), double> getMomentOfInertia(double mass) const override;
	Vector<n, double> getCenterOfMass() const override;
	
	shape::NSphere<n> getNSphere() const;
	void setNSphere(const shape::NSphere<n>& sphere);
	void setNSphere(shape::NSphere<n>&& sphere);
	
private:
	shape::NSphere<n> _sphere;
};

template<> Vector<freedom(2), double> ShapeInfo<2, shape::NSphere<2>>::getMomentOfInertia(double mass) const;
template<> Vector<freedom(3), double> ShapeInfo<3, shape::NSphere<3>>::getMomentOfInertia(double mass) const;

template<int n>
struct ShapeInfo<n, shape::Polytope<n>> : AbstractShapeInfo<n> {
	ShapeInfo(const shape::Polytope<n>& polytope);
	ShapeInfo(shape::Polytope<n>&& polytope);
	
	Vector<freedom(n), double> getMomentOfInertia(double mass) const override;
	Vector<n, double> getCenterOfMass() const override;
	
	shape::Polytope<n> getPolytope() const;
	void setPolytope(const shape::Polytope<n>& polytope);
	void setPolytope(shape::Polytope<n>&& polytope);
	
private:
	shape::Polytope<n> _polytope;
};

template<> Vector<freedom(2), double> ShapeInfo<2, shape::Polytope<2>>::getMomentOfInertia(double mass) const;
template<> Vector<freedom(3), double> ShapeInfo<3, shape::Polytope<3>>::getMomentOfInertia(double mass) const;

extern template struct ShapeInfo<2, shape::Polytope<2>>;
extern template struct ShapeInfo<2, shape::NSphere<2>>;
extern template struct ShapeInfo<3, shape::Polytope<3>>;
extern template struct ShapeInfo<3, shape::NSphere<3>>;

template<typename T> using Shape2DInfo = ShapeInfo<2, T>;
template<typename T> using Shape3DInfo = ShapeInfo<3, T>;

}