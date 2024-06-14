#include <iostream>
#include "DynamicArray.h"
using namespace std;

void DynamicArray::Reset(int initialCapacity)
{
	_size = 0;
	_capacity = initialCapacity;
	_data = new int[_capacity];
}

DynamicArray::DynamicArray(int initialCapacity)
{
	Reset(initialCapacity);
}
DynamicArray::~DynamicArray()
{
	delete[] _data;
}
const int* DynamicArray::GetData() const
{
	return _data; // This returns a pointer! Careful
}
unsigned int DynamicArray::GetCapacity()
{
	return _capacity;
}
unsigned int DynamicArray::GetSize()
{
	return _size;
}
void DynamicArray::Add(int newItem)
{
	// Should we resize this?
	if (_size == _capacity)
	{
		cout << "Container Full! Resizing..." << endl;
		_capacity++;
		// Resize our array
		int* newArray = new int[_capacity];
		
		for (int i = 0; i < _size; i++)
			newArray[i] = _data[i];

		delete[] _data;
		_data = newArray;
	}
	// 1. Add new thing to array at the right location
	_data[_size] = newItem;
	// 2. Increase size
	_size++;
}
void DynamicArray::Remove()
{
	// Remove 1 element from the end of the array
	if (_size > 0)
	{
		_size--; // this is the lazy way - leaves it until we overwrite
		int* newArray = new int[_capacity];
		for (int i = 0; i < _size; i++)
			newArray[i] = _data[i];
		delete[] _data;
		_data = newArray;

	}
	else
		cout << "Can't remove from empty container!" << endl;
}

// Reset the array as if it were in a defalt state
void DynamicArray::Clear()
{
	// 1. Get rid of any old data
	delete[] _data;
	// Reset everything to capacity of 1 
	Reset(1);
}
void DynamicArray::Print() const
{
	for (int i = 0; i < _size; i++)
		cout << _data[i] << endl;
}

// Copy constructor and copy assignment operator

DynamicArray::DynamicArray(const DynamicArray& otherObject)
{
	// Do a deep copy of all of the other objects data
	Set(otherObject);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& otherObject)
{
	// 0. Get rid of any old data
	delete[] _data;

	// 1. Do a deep copy of all data
	Set(otherObject);

	return *this; // last line always looks like this
}

void DynamicArray::Set(const DynamicArray& otherObject)
{
	_size = otherObject._size;
	_capacity = otherObject._capacity;
	_data = new int[_capacity];

	for (int i = 0; i < _size; i++)
		_data[i] = otherObject._data[i];
}