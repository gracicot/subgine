#pragma once

#include "displaycomponentprovider.h"
#include "callbackcomponentprovider.h"

namespace subgine {

template <int n>
class CallbackDisplayComponentProvider : public CallbackComponentProvider<n>, public DisplayComponentProvider<n>
{
public:
	CallbackDisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		std::function<Vector<freedom(n), double>()> orientation,
		std::function<double()> scale
	);
	
	CallbackDisplayComponentProvider(
		Vector<n, double> position,
		std::function<Vector<freedom(n), double>()> orientation,
		std::function<double()> scale
	);
	
	CallbackDisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		Vector<freedom(n), double> orientation,
		std::function<double()> scale
	);
	
	CallbackDisplayComponentProvider(
		Vector<n, double> position,
		Vector<freedom(n), double> orientation,
		std::function<double()> scale
	);
	
	CallbackDisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		std::function<Vector<freedom(n), double>()> orientation,
		double scale = 0
	);
	
	CallbackDisplayComponentProvider(
		Vector<n, double> position,
		std::function<Vector<freedom(n), double>()> orientation,
		double scale = 0
	);
	
	CallbackDisplayComponentProvider(
		std::function<Vector<n, double>()> position,
		Vector<freedom(n), double> orientation = Vector<freedom(n), double>(),
		double scale = 0
	);
	
	CallbackDisplayComponentProvider(
		Vector<n, double> position = Vector<n, double>(),
		Vector<freedom(n), double> orientation = Vector<freedom(n), double>(),
		double scale = 0
	);
	
	void setScale(std::function<double()> scale);
	void setScale(double scale);
	virtual double getScale() const override;
	
private:
	std::function<double()> _scale;
	
};

extern template class CallbackDisplayComponentProvider<2>;
extern template class CallbackDisplayComponentProvider<3>;

typedef CallbackDisplayComponentProvider<2> CallbackDisplayComponentProvider2D;
typedef CallbackDisplayComponentProvider<3> CallbackDisplayComponentProvider3D;

}