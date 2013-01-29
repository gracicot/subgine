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


#ifndef TRAIT_POSITION_H
#define TRAIT_POSITION_H

#include "../positionnable.h"
#include "../vector2.h"

namespace Traits{

class Position : public Positionnable
{
public:
	Position();
	virtual ~Position();
	
	virtual Vector2 getPosition() const;
	
protected:
	Vector2 _position;
};

}

#endif // TRAIT_POSITION_H
