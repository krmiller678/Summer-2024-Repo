#pragma once
// This is our Array Based Stack class -> Remember that for template
// classes all of the definitions need to be contained within the same
// .h file. LIFO property for stacks.
#include "leaker.h"

template <typename T>
class ABS
{
	float _scale_factor = 2.0f;
	int _size;
	int _capacity;
	T* _data;

public:
	// Construction / Destruction
	ABS();
	ABS(int capacity);
	~ABS();

	// Copy Constructor
	ABS(const ABS& otherStack);

	// Copy Assignment Operator
	ABS& operator=(const ABS& otherStack);

	// Accessors
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
	T peek();

	// Mutators
	void push(T data);
	T pop();
};

template <typename T>
ABS<T>::ABS()
{
	_size = 0;
	_capacity = 1;
	_data = new T[_capacity];
}
template <typename T>
ABS<T>::ABS(int capacity)
{
	_size = 0;
	_capacity = capacity;
	_data = new T[_capacity];
}
template <typename T>
ABS<T>::~ABS()
{
	delete[] _data;
}
template <typename T>
ABS<T>::ABS(const ABS& otherStack)
{
	_size = otherStack._size;
	_capacity = otherStack._capacity;
	_data = new T[_capacity];

	for (unsigned int i = 0; i < _size; i++)
		_data[i] = otherStack._data[i];
}
template <typename T>
ABS<T>& ABS<T>::operator=(const ABS& otherStack)
{
	_size = otherStack._size;
	_capacity = otherStack._capacity;
	delete[] _data;
	_data = new T[_capacity];

	for (unsigned int i = 0; i < _size; i++)
		_data[i] = otherStack._data[i];

	return *this;
}
template <typename T>
unsigned int ABS<T>::getSize()
{
	return _size;
}
template <typename T>
unsigned int ABS<T>::getMaxCapacity()
{
	return _capacity;
}
template <typename T>
T* ABS<T>::getData()
{
	return _data;
}
template <typename T>
T ABS<T>::peek()
{
	if (_size > 0)
		return _data[_size - 1];
	else throw std::runtime_error("Ya can't do that!");

}

template <typename T>
void ABS<T>::push(T data)
{
	// Resize if _size == _capacity
	if (_size == _capacity)
	{
		_capacity *= _scale_factor; // double capacity when size reached
		T* newArray = new T[_capacity];
		for (int i = 0; i < _size; i++)
			newArray[i] = _data[i];
		delete[] _data;
		_data = newArray; // newArray falls out of scope but data remains
	}
	// 1. Add new thing at right location
	_data[_size] = data;
	// 2. Increase size
	_size++;
}

template <typename T>
T ABS<T>::pop()
{
	
	if (_size > 0)
	{
		_size--; // decrement size
		T firstOut = _data[_size]; // store the thing we will remove
		if (((float)_size / _capacity) < (1 / _scale_factor)) // Resize if _size < 1/_scale_factor
		{
			_capacity /= _scale_factor; // half capacity
		}
		T* newArray = new T[_capacity];
		for (int i = 0; i < (_size); i++)
			newArray[i] = _data[i];
		delete[] _data;
		_data = newArray; // newArray falls out of scope but data remains

		return firstOut; // return the thingy we removed
	}
	else
		throw std::runtime_error("Ya can't do that!");
}