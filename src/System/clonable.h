#pragma once

class Clonable
{
public:
	virtual Clonable* clone() const = 0;
};
