#pragma once

#include "rule.h"

namespace subgine
{

class Positionnable3;
namespace physic
{

namespace Rule3
{

class Spring : public Rule
{
public:
	Spring(const Vector3 value, const double size, Positionnable3& position);
	Spring(const Vector3 value = Vector3(), const double size = 0, const Vector3 position = Vector3());
	Spring(const Spring& other);
	virtual ~Spring();
	Vector3 getValue() const;
	double getSize() const;
	Vector3 getPosition() const;

	Vector3 getResult(const PhysicPoint3& object) const;

	void setValue(const Vector3 value);
	void setSize(double size);
	void setPosition(Positionnable3& position);
	void setPosition(Vector3 position);

private:
	Vector3  _value;
	double _size;

	bool _deletePosition;
	Positionnable3* _position;
};

}
}
}
