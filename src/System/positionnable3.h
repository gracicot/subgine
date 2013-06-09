#pragma once

class Vector3;

class Positionnable3
{

public:
	Positionnable3();
	virtual ~Positionnable3();

	virtual Vector3 getPosition() const = 0;
};
