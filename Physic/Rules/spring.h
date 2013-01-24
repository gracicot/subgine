/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef RULE_SPRING_H
#define RULE_SPRING_H

#include "rule.h"
#include "../physicpoint.h"

namespace Rule
{

class Spring : public Rule
{
public:
	Spring(const Vector value, const double size, const Positionnable& position);
	Spring(const Vector value = Vector(), const double size = 0, const Vector position = Vector());
	Spring(const Spring& other);
	virtual ~Spring();
	Vector getValue() const;
	double getSize() const;
	Vector getPosition() const;
	
	virtual Vector getResult(const PhysicPoint& object) const;
	
	void setValue(const Vector value);
	void setSize(const double size);
	void setPosition(const Positionnable& position);
	void setPosition(const Vector position);

private:
	Vector  _value;
	double _size;

	bool _deletePosition;
	Positionnable* _position;
};

}
#endif // RULE_SPRING_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
