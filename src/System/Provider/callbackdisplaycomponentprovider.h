#pragma once

#include "displaycomponentprovider.h"
#include "callbackcomponentprovider.h"

namespace sbg {

template <int n>
class CallbackDisplayComponentProvider : public virtual CallbackComponentProvider<n>, public virtual DisplayComponentProvider<n>
{
public:
	CallbackDisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		std::function<Vector<freedom(n), double>()> orientation,
		std::function<Vector<n, double>()> scale
	);
	
	CallbackDisplayComponentProvider(
		Vector<n, double> position,
		std::function<Vector<freedom(n), double>()> orientation,
		std::function<Vector<n, double>()> scale
	);
	
	CallbackDisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		Vector<freedom(n), double> orientation,
		std::function<Vector<n, double>()> scale
	);
	
	CallbackDisplayComponentProvider(
		Vector<n, double> position,
		Vector<freedom(n), double> orientation,
		std::function<Vector<n, double>()> scale
	);
	
	CallbackDisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		std::function<Vector<freedom(n), double>()> orientation,
		Vector<n, double> scale = 0
	);
	
	CallbackDisplayComponentProvider(
		Vector<n, double> position,
		std::function<Vector<freedom(n), double>()> orientation,
		Vector<n, double> scale = 0
	);
	
	CallbackDisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		Vector<freedom(n), double> orientation = Vector<freedom(n), double>(),
		Vector<n, double> scale = 0
	);
	
	CallbackDisplayComponentProvider(
		Vector<n, double> position = Vector<n, double>(),
		Vector<freedom(n), double> orientation = Vector<freedom(n), double>(),
		Vector<n, double> scale = 0
	);
	
	void setScale(std::function<Vector<n, double>()> scale);
	void setScale(Vector<n, double> scale);
	Vector<n, double> getScale() const override;
	
private:
	std::function<Vector<n, double>()> _scale;
	
};

extern template class CallbackDisplayComponentProvider<2>;
extern template class CallbackDisplayComponentProvider<3>;

typedef CallbackDisplayComponentProvider<2> CallbackDisplayComponentProvider2D;
typedef CallbackDisplayComponentProvider<3> CallbackDisplayComponentProvider3D;

}