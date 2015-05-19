#pragma once

#include "../../system.hpp"

namespace sbg {

template<int i> class PhysicBody;

template<int n>
DisplayComponentProvider<n> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<n>> physicBody, Vector<n, double> scale = {1});

template<int n>
DisplayComponentProvider<n> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<n>> physicBody, std::function<Vector<n, double>()> scale);

inline DisplayComponentProvider<2> makePhysicBody2DDisplayComponentProvider(std::weak_ptr<const PhysicBody<2>> physicBody, Vector<2, double> scale = {1})
{
	return makePhysicBodyDisplayComponentProvider<2>(physicBody, scale);
}

inline DisplayComponentProvider<2> makePhysicBody2DDisplayComponentProvider(std::weak_ptr<const PhysicBody<2>> physicBody, std::function<Vector<2, double>()> scale)
{
	return makePhysicBodyDisplayComponentProvider<2>(physicBody, scale);
}

inline DisplayComponentProvider<3> makePhysicBody3DDisplayComponentProvider(std::weak_ptr<const PhysicBody<3>> physicBody, Vector<3, double> scale = {1})
{
	return makePhysicBodyDisplayComponentProvider<3>(physicBody, scale);
}

inline DisplayComponentProvider<3> makePhysicBody3DDisplayComponentProvider(std::weak_ptr<const PhysicBody<3>> physicBody, std::function<Vector<3, double>()> scale)
{
	return makePhysicBodyDisplayComponentProvider<3>(physicBody, scale);
}

extern template DisplayComponentProvider<2> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<2>>, Vector<2, double>);
extern template DisplayComponentProvider<2> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<2>>, std::function<Vector<2, double>()>);
extern template DisplayComponentProvider<3> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<3>>, Vector<3, double>);
extern template DisplayComponentProvider<3> makePhysicBodyDisplayComponentProvider(std::weak_ptr<const PhysicBody<3>>, std::function<Vector<3, double>()>);

}
