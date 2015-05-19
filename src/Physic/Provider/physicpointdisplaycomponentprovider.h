#pragma once

#include "../../system.hpp"

namespace sbg {

template<int n> class PhysicPoint;

template<int n>
DisplayComponentProvider<n> makePhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, Vector<freedom(n), double> orientation = {}, Vector<n, double> scale = {1});

template<int n>
DisplayComponentProvider<n> makePhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, std::function<Vector<freedom(n), double>()> orientation, Vector<n, double> scale = {1});

template<int n>
DisplayComponentProvider<n> makePhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, Vector<freedom(n), double> orientation, std::function<Vector<n, double>()> scale);

template<int n>
DisplayComponentProvider<n> makePhysicPointDisplayComponentProvider(std::weak_ptr<const PhysicPoint<n>> physicPoint, std::function<Vector<freedom(n), double>()> orientation, std::function<Vector<n, double>()> scale);

inline DisplayComponentProvider<2> makePhysicPoint2DDisplayComponentProvider(std::weak_ptr<const PhysicPoint<2>> physicPoint, Vector<freedom(2), double> orientation = {}, Vector<2, double> scale = {1})
{
	return makePhysicPointDisplayComponentProvider<2>(physicPoint, orientation, scale);
}

inline DisplayComponentProvider<2> makePhysicPoint2DDisplayComponentProvider(std::weak_ptr<const PhysicPoint<2>> physicPoint, std::function<Vector<freedom(2), double>()> orientation, Vector<2, double> scale = {1})
{
	return makePhysicPointDisplayComponentProvider<2>(physicPoint, orientation, scale);
}

inline DisplayComponentProvider<2> makePhysicPoint2DDisplayComponentProvider(std::weak_ptr<const PhysicPoint<2>> physicPoint, Vector<freedom(2), double> orientation, std::function<Vector<2, double>()> scale)
{
	return makePhysicPointDisplayComponentProvider<2>(physicPoint, orientation, scale);
}

inline DisplayComponentProvider<2> makePhysicPoint2DDisplayComponentProvider(std::weak_ptr<const PhysicPoint<2>> physicPoint, std::function<Vector<freedom(2), double>()> orientation, std::function<Vector<2, double>()> scale)
{
	return makePhysicPointDisplayComponentProvider<2>(physicPoint, orientation, scale);
}

inline DisplayComponentProvider<3> makePhysicPoint3DDisplayComponentProvider(std::weak_ptr<const PhysicPoint<3>> physicPoint, Vector<freedom(3), double> orientation = {}, Vector<3, double> scale = {1})
{
	return makePhysicPointDisplayComponentProvider<3>(physicPoint, orientation, scale);
}

inline DisplayComponentProvider<3> makePhysicPoint3DDisplayComponentProvider(std::weak_ptr<const PhysicPoint<3>> physicPoint, std::function<Vector<freedom(3), double>()> orientation, Vector<3, double> scale = {1})
{
	return makePhysicPointDisplayComponentProvider<3>(physicPoint, orientation, scale);
}

inline DisplayComponentProvider<3> makePhysicPoint3DDisplayComponentProvider(std::weak_ptr<const PhysicPoint<3>> physicPoint, Vector<freedom(3), double> orientation, std::function<Vector<3, double>()> scale)
{
	return makePhysicPointDisplayComponentProvider<3>(physicPoint, orientation, scale);
}

inline DisplayComponentProvider<3> makePhysicPoint3DDisplayComponentProvider(std::weak_ptr<const PhysicPoint<3>> physicPoint, std::function<Vector<freedom(3), double>()> orientation, std::function<Vector<3, double>()> scale)
{
	return makePhysicPointDisplayComponentProvider<3>(physicPoint, orientation, scale);
}

extern template DisplayComponentProvider<2> makePhysicPointDisplayComponentProvider<2>(std::weak_ptr<const PhysicPoint<2>> physicPoint, Vector<freedom(2), double>, Vector<2, double>);
extern template DisplayComponentProvider<2> makePhysicPointDisplayComponentProvider<2>(std::weak_ptr<const PhysicPoint<2>> physicPoint, std::function<Vector<freedom(2), double>()>, Vector<2, double>);
extern template DisplayComponentProvider<2> makePhysicPointDisplayComponentProvider<2>(std::weak_ptr<const PhysicPoint<2>> physicPoint, Vector<freedom(2), double>, std::function<Vector<2, double>()>);
extern template DisplayComponentProvider<2> makePhysicPointDisplayComponentProvider<2>(std::weak_ptr<const PhysicPoint<2>> physicPoint, std::function<Vector<freedom(2), double>()>, std::function<Vector<2, double>()>);
extern template DisplayComponentProvider<3> makePhysicPointDisplayComponentProvider<3>(std::weak_ptr<const PhysicPoint<3>> physicPoint, Vector<freedom(3), double>, Vector<3, double>);
extern template DisplayComponentProvider<3> makePhysicPointDisplayComponentProvider<3>(std::weak_ptr<const PhysicPoint<3>> physicPoint, std::function<Vector<freedom(3), double>()>, Vector<3, double>);
extern template DisplayComponentProvider<3> makePhysicPointDisplayComponentProvider<3>(std::weak_ptr<const PhysicPoint<3>> physicPoint, Vector<freedom(3), double>, std::function<Vector<3, double>()>);
extern template DisplayComponentProvider<3> makePhysicPointDisplayComponentProvider<3>(std::weak_ptr<const PhysicPoint<3>> physicPoint, std::function<Vector<freedom(3), double>()>, std::function<Vector<3, double>()>);

}
