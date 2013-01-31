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


#ifndef RESISTANCE_RULE_H
#define RESISTANCE_RULE_H

#include "rule.h"

namespace Rule
{

class Attraction : public Rule
{
public:
	Attraction(const Vector2 value = Vector2());
	Attraction(const Attraction& c);
	
	virtual Vector2 getResult(const PhysicPoint& object) const;
	
	void addObject(const PhysicPoint& object);
	void removeObject(const PhysicPoint& object);
	
	void setValue(const Vector2 value);
	Vector2 getValue() const;
	
private:
	std::list<const PhysicPoint*> _objects;
	Vector2 _value;
};

}
#endif // RESISTANCE_RULE_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
