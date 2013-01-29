/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * jump-2
 *
jump-2 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * jump-2 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _LIST_H_
#define _LIST_H_

template<class> class Container;

class Factory
{
public:
	Factory();
	~Factory();

	template<class T>
	static T* construct()
	{
		T* ptr = new T;
		return ptr;
	}
	template <class T, class... S>
	static T* construct(Container<S>&... Args)
	{
		T* ptr = new T;
		_addData(ptr, Args...);
		return ptr;
	}

private:

	template <class T, class S>
	static void _addData(T* ptr, Container<S>& c)
	{
		c.addData(ptr);
	}

	template <class T, class S, class... D>
	static void _addData(T* ptr, Container<S>& c, Container<D>&... Args)
	{
		c.addData(ptr);
		_addData(ptr, Args...);
	}

};

#endif // _LIST_H_
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
