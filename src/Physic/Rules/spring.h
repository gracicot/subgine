#pragma once

#include "rule.h"

namespace subgine
{
namespace physic
{
namespace Rule
{

class Spring : public Rule
{
public:
	Spring(const Vector2 value, const double size, Positionnable& position);
	Spring(const Vector2 value = Vector2(), const double size = 0, const Vector2 position = Vector2());
	Spring(const Spring& other);
	virtual ~Spring();
	Vector2 getValue() const;
	double getSize() const;
	Vector2 getPosition() const;

	virtual Vector2 getResult(const PhysicPoint& object) const;

	void setValue(const Vector2 value);
	void setSize(const double size);
	void setPosition(Positionnable& position);
	void setPosition(Vector2 position);

private:
	Vector2  _value;
	double _size;

	bool _deletePosition;
	Positionnable* _position;
};

}
}
}
