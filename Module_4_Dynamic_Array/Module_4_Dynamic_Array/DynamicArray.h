#pragma once
class DynamicArray
{
	int* _data; // What the class stores -- the real data
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
	const int* GetData() const; // sooo important -> cannot modify the data outside
	//int* GetData() const; protects "this->" data, good for accessor
	unsigned int GetCapacity();
	unsigned int GetSize();

	/*======== Mutators =========*/
	// Mutators MUTATE the class, bad place for const
	void Add(int newItem);
	void Remove();
	void Clear();

	/*======== Behaviors =========*/
	void Print() const;


};

