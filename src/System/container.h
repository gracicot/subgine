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


#ifndef STORAGE_H
#define STORAGE_H

template<class T> class Storage;

template<class T> class Container
{

public:
	void addData(T* data)
	{
		_data.push_back(data);
		insertedAction();
	}

	const std::list<T*>& getContent() const
	{
		return _data;
	}

	std::list<T*>& getContent()
	{
		return _data;
	}

	Storage<T> getStorage() const
	{
		Storage<T> storage;
		storage._data = _data;
		return storage;
	}

	void selectStorage(Storage<T>& storage)
	{
		_data = storage._data;
	}

	void removeData(T& object)
	{
		_data.remove(&object);
	}

protected:
	std::list<T*>& getList()
	{
		return _data;
	}

	virtual void insertedAction()
	{

	}

private:

	std::list<T*> _data;

};

template<class T> class Storage : private Container<T>
{

};


#endif // STORAGE_H

