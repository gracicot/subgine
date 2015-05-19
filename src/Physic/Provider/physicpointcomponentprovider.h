#pragma once

#include "../../system.hpp"

#include <memory>
#include <functional>

namespace sbg {

template<int n> class PhysicPoint;

template<int n>
ComponentProvider<n> makePhysicPointComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, Vector<freedom(n), double> orientation = {});

template<int n>
ComponentProvider<n> makePhysicPointComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, std::function<Vector<freedom(n), double>()> orientation);

extern template ComponentProvider<2> makePhysicPointComponentProvider<2>(std::weak_ptr<const PhysicPoint<2>>, Vector<freedom(2), double>);
extern template ComponentProvider<3> makePhysicPointComponentProvider<3>(std::weak_ptr<const PhysicPoint<3>>, Vector<freedom(3), double>);
extern template ComponentProvider<2> makePhysicPointComponentProvider<2>(std::weak_ptr<const PhysicPoint<2>>, std::function<Vector<freedom(2), double>()>);
extern template ComponentProvider<3> makePhysicPointComponentProvider<3>(std::weak_ptr<const PhysicPoint<3>>, std::function<Vector<freedom(3), double>()>);

inline ComponentProvider<2> makePhysicPointComponentProvider2D(std::weak_ptr<const PhysicPoint<2>> physicPoint, std::function<Vector<freedom(2), double>()> orientation)
{
	return makePhysicPointComponentProvider<2>(physicPoint, orientation);
}

inline ComponentProvider<3> makePhysicPointComponentProvider3D(std::weak_ptr<const PhysicPoint<3>> physicPoint, std::function<Vector<freedom(3), double>()> orientation)
{
	return makePhysicPointComponentProvider<3>(physicPoint, orientation);
}

inline ComponentProvider<2> makePhysicPointComponentProvider2D(std::weak_ptr<const PhysicPoint<2>> physicPoint, Vector<freedom(2), double> orientation)
{
	return makePhysicPointComponentProvider<2>(physicPoint, orientation);
}

inline ComponentProvider<3> makePhysicPointComponentProvider3D(std::weak_ptr<const PhysicPoint<3>> physicPoint, Vector<freedom(3), double> orientation)
{
	return makePhysicPointComponentProvider<3>(physicPoint, orientation);
}

}