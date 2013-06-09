#pragma once

class Vector2;

class Positionnable
{

public:
	Positionnable();
	virtual ~Positionnable();

	virtual Vector2 getPosition() const = 0;
};
