#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class DynamicArray
{
	T* _data; // What the class stores -- the real data
	int _capacity; // How many can we store
	int _size; // How many elements are we storing
	void Reset(int initialCapacity);

	void Set(const DynamicArray& otherObject);

public:
	// Construction / Destruction
	DynamicArray(int initialCapacity = 1);
	~DynamicArray();

	// Copy constructor
	DynamicArray(const DynamicArray& otherObject);

	// Copy assignment operator
	DynamicArray& operator=(const DynamicArray& otherObject);

	/*======== Accessors =========*/
	const T* GetData() const; // sooo important -> cannot modify the data outside
	//int* GetData() const; protects "this->" data, good for accessor
	unsigned int GetCapacity();
	unsigned int GetSize();

	/*======== Mutators =========*/
	// Mutators MUTATE the class, bad place for const
	void Add(T newItem);
	void Remove();
	void Clear();

	/*======== Behaviors =========*/
	void Print() const;


};


template <typename T>
void DynamicArray<T>::Reset(int initialCapacity)
{
	_size = 0;
	_capacity = initialCapacity;
	_data = new T[_capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(int initialCapacity)
{
	Reset(initialCapacity);
}
template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] _data;
}
template <typename T>
const T* DynamicArray<T>::GetData() const
{
	return _data; // This returns a pointer! Careful
}
template <typename T>
unsigned int DynamicArray<T>::GetCapacity()
{
	return _capacity;
}
template <typename T>
unsigned int DynamicArray<T>::GetSize()
{
	return _size;
}
template <typename T>
void DynamicArray<T>::Add(T newItem)
{
	// Should we resize this?
	if (_size == _capacity)
	{
		cout << "Container Full! Resizing..." << endl;
		_capacity++;
		// Resize our array
		T* newArray = new T[_capacity];

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
template <typename T>
void DynamicArray<T>::Remove()
{
	// Remove 1 element from the end of the array
	if (_size > 0)
	{
		_size--; // this is the lazy way - leaves it until we overwrite
		T* newArray = new T[_capacity];
		for (int i = 0; i < _size; i++)
			newArray[i] = _data[i];
		delete[] _data;
		_data = newArray;

	}
	else
		cout << "Can't remove from empty container!" << endl;
}

// Reset the array as if it were in a defalt state
template <typename T>
void DynamicArray<T>::Clear()
{
	// 1. Get rid of any old data
	delete[] _data;
	// Reset everything to capacity of 1 
	Reset(1);
}
template <typename T>
void DynamicArray<T>::Print() const
{
	for (int i = 0; i < _size; i++)
		cout << _data[i] << endl;
}

// Copy constructor and copy assignment operator
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& otherObject)
{
	// Do a deep copy of all of the other objects data
	Set(otherObject);
}
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& otherObject)
{
	// 0. Get rid of any old data
	delete[] _data;

	// 1. Do a deep copy of all data
	Set(otherObject);

	return *this; // last line always looks like this
}
template <typename T>
void DynamicArray<T>::Set(const DynamicArray& otherObject)
{
	_size = otherObject._size;
	_capacity = otherObject._capacity;
	_data = new T[_capacity];

	for (int i = 0; i < _size; i++)
		_data[i] = otherObject._data[i];
}