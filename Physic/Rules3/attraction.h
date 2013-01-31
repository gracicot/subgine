/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  Guillaume <email>

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


#ifndef RESISTANCE_RULE_H3
#define RESISTANCE_RULE_H3

#include "rule.h"

namespace Rule3
{

class Attraction : public Rule
{
public:
	Attraction(const Vector3 value = Vector3());
	Attraction(const Attraction& c);
	
	virtual Vector3 getResult(const PhysicPoint3& object) const;
	
	void addObject(const PhysicPoint3& object);
	void removeObject(const PhysicPoint3& object);
	
	void setValue(const Vector3 value);
	Vector3 getValue() const;
	
private:
	std::list<const PhysicPoint3*> _objects;
	Vector3 _value;
};

}
#endif // RESISTANCE_RULE_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
