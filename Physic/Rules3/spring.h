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


#ifndef RULE_SPRING_H3
#define RULE_SPRING_H3

#include "rule.h"
#include "../physicpoint3.h"

namespace Rule3
{

class Spring : public Rule
{
public:
	Spring(Vector3 value, double size, Positionnable3& position);
	Spring(Vector3 value, double size, Vector3 position);
	Spring(const Spring& other);
	virtual ~Spring();
	Vector3 getValue() const;
	double getSize() const;
	Vector3 getPosition() const;
	
	Vector3 getResult(const PhysicPoint3& object) const;
	
	void setValue(Vector3 value);
	void setSize(double size);
	void setPosition(Positionnable3& pos);
	void setPosition(Vector3 pos);

private:
	Vector3  _value;
	double _size;

	bool _deletePosition;
	Positionnable3* _position;
};

}
#endif // RULE_SPRING_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
