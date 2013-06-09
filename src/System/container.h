#pragma once

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


