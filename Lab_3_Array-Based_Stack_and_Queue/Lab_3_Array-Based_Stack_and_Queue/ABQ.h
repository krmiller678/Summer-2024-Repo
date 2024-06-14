#pragma once
// This is our Array Based Queue class -> Remember that for template
// classes all of the definitions need to be contained within the same
// .h file. FIFO property for queues.
#include "leaker.h"

template <typename T>
class ABQ
{
	float _scale_factor = 2.0f;
	int _size;
	int _capacity;
	T* _data;
	void Set(const ABQ& otherQueue);

public:
	// Construction / Destruction
	ABQ();
	ABQ(int capacity);
	~ABQ();

	// Copy Constructor
	ABQ(const ABQ& otherStack);

	// Copy Assignment Operator
	ABQ& operator=(const ABQ& otherQueue);

	// Accessors
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
	T peek();

	// Mutators
	void enqueue(T data);
	T dequeue();
};

template <typename T> 
ABQ<T>::ABQ()
{
	_size = 0;
	_capacity = 1;
	_data = new T[_capacity];
}

template <typename T>
ABQ<T>::ABQ(int capacity)
{
	_size = 0;
	_capacity = capacity;
	_data = new T[_capacity];
}

template <typename T>
ABQ<T>::~ABQ()
{
	delete[] _data;
}

template <typename T>
ABQ<T>::ABQ(const ABQ& otherQueue)
{
	Set(otherQueue);
}

template <typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ& otherQueue)
{
	delete[] _data;
	Set(otherQueue);

	return *this;
}

template <typename T>
void ABQ<T>::Set(const ABQ& otherQueue)
{
	_size = otherQueue._size;
	_capacity = otherQueue._capacity;
	_data = new T[_capacity];

	for (int i = 0; i < _size; i++)
		_data[i] = otherQueue._data[i];
}

template <typename T>
unsigned int ABQ<T>::getSize()
{
	return _size;
}

template <typename T>
unsigned int ABQ<T>::getMaxCapacity()
{
	return _capacity;
}

template <typename T>
T* ABQ<T>::getData()
{
	return _data;
}

template <typename T>
T ABQ<T>::peek()
{
	if (_size > 0)
		return _data[0];
	else
		throw std::runtime_error("what you think this is");
}

template <typename T>
void ABQ<T>::enqueue(T data)
{
	// 1. Determine if we need to add capacity
	if (_size == _capacity)
	{
		_capacity *= _scale_factor;
		// 1.5 - Copy array into new bigger array
		T* tempArray = new T[_capacity];
		for (int i = 0; i < _size; i++)
			tempArray[i] = _data[i];

		delete[] _data;
		_data = tempArray;
	}

	// 2. Add in the fresh data
	_data[_size] = data;

	// 3. increment size
	_size++;
}

template <typename T>
T ABQ<T>::dequeue()
{
	if (_size > 0)
	{
		// IMPORTANT - If you are going to decrement size, adjust the array order in the same place
		// ie do not separate by having a bunch of structure reorganization in the middle.
		T thingy = _data[0];
		_size--;
		for (int i = 0; i < _size; i++)
			_data[i] = _data[i + 1];
		// 1. Determine if downsizing is necessary
		if ((float)_size / _capacity < 1 / _scale_factor)
		{
			_capacity /= _scale_factor;
			T* tempArray = new T[_capacity];
			for (int i = 0; i < _size; i++)
				tempArray[i] = _data[i];
			delete[] _data;
			_data = tempArray;
		}
		return thingy;
	}
	else
		throw std::runtime_error("what you think this is");

}