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


#ifndef PARTICLE_H
#define PARTICLE_H

#include "../physic.hpp"

class Particle : public PhysicPoint
{
public:
	Particle(const double lifetime = 1);
	~Particle() = default;
	
	double getTime() const;
	void setLifeTime(const double lifetime);
	double getLifetime() const;
	
private:
	double _lifetime;
};

#endif // PARTICLE_H
