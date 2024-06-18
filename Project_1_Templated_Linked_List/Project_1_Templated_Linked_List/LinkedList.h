#pragma once
using namespace std;
#include <vector>
#include <iostream>

template <typename T>
class LinkedList
{
public:
	// Nested Class
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
		Node(T nodeData);
	};

	// Constructors / Destructor
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	~LinkedList();

	// Operators
	LinkedList<T>& operator=(const LinkedList<T>& rhs);
	T& operator[](unsigned int index);
	bool operator==(const LinkedList<T>& rhs);


	// Mutators
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);

	// Accessors
	unsigned int NodeCount() const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	Node* Head();
	Node* Tail();
	Node* GetNode(unsigned int index) const;
	Node* Find(const T& data) const;

	// Removal
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(unsigned int index);
	void Clear();

	// Behaviors
	void PrintForward() const;
	void PrintReverse() const;
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;

private:
	Node* _head;
	Node* _tail;
};

template <typename T>
LinkedList<T>::Node::Node(T nodeData)
{
	data = nodeData;
	next = nullptr;
	prev = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList()
{
	_head = nullptr;
	_tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node* currentNode = _head;
	while (currentNode != nullptr)
	{
		Node* tempNode = currentNode->next;
		delete currentNode;
		currentNode = tempNode;
	}
}

template <typename T>
void LinkedList<T>::AddHead(const T& data)
{
	if (_head == nullptr)
	{
		_head = new Node(data);
		_tail = _head;
	}
	else
	{
		Node* tempNodePtr = _head;
		_head = new Node(data);
		_head->next = tempNodePtr;
		tempNodePtr->prev = _head;
	}
}

template <typename T>
void LinkedList<T>::AddTail(const T& data)
{
	if (_head == nullptr)
	{
		AddHead(data);
	}
	else
	{
		Node* tempNodePtr = _tail;
		_tail = new Node(data);
		_tail->prev = tempNodePtr;
		tempNodePtr->next = _tail;
	}
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	for (unsigned int i =0; i < count; i++)
	{
		AddHead(data[count-1-i]);
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		AddTail(data[i]);
	}
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const
{
	Node* currentPtr = _head;
	unsigned int nodeCount = 0;
	while (currentPtr != nullptr)
	{
		nodeCount++;
		currentPtr = currentPtr->next;
	}
	return nodeCount;
}

template <typename T>
void LinkedList<T>::PrintForward() const
{
	Node* currentPtr = _head;
	while (currentPtr != nullptr)
	{
		cout << currentPtr->data << endl;
		currentPtr = currentPtr->next;
	}
}

template <typename T>
void LinkedList<T>::PrintReverse() const
{
	Node* currentPtr = _tail;
	while (currentPtr != nullptr)
	{
		cout << currentPtr->data << endl;
		currentPtr = currentPtr->prev;
	}
}

template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const
{
	Node* currentPtr = _head;
	while (currentPtr != nullptr)
	{
		if (currentPtr->data == value)
			outData.push_back(currentPtr);
		currentPtr = currentPtr->next;
	}
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	return _head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail()
{
	return _tail;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const
{
	if (index >= this->NodeCount())
		throw out_of_range("ERROR INDEX OUT OF RANGE");
	unsigned int i = 0;
	Node* currentPtr = _head;
	while (i < index)
	{
		currentPtr = currentPtr->next;
		i++;
	}
	return currentPtr;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const
{
	Node* currentPtr = _head;
	while (currentPtr->data != data)
	{
		currentPtr = currentPtr->next;
		if (currentPtr == nullptr)
			return nullptr;
	}
	return currentPtr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	_head = nullptr;
	_tail = nullptr;
	Node* thingToCopy = list._head;
	while (thingToCopy != nullptr)
	{
		this->AddTail(thingToCopy->data);
		thingToCopy = thingToCopy->next;
	}
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	Node* currentNode = _head;
	while (currentNode != nullptr)
	{
		Node* tempNode = currentNode->next;
		delete currentNode;
		currentNode = tempNode;
	}
	_head = nullptr;
	_tail = nullptr;
	Node* thingToCopy = rhs._head;
	while (thingToCopy != nullptr)
	{
		this->AddTail(thingToCopy->data);
		thingToCopy = thingToCopy->next;
	}
	return *this;
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index)
{
	if (index >= this->NodeCount())
		throw out_of_range("ERROR INDEX OUT OF RANGE");
	unsigned int i = 0;
	Node* currentPtr = _head;
	while (i < index)
	{
		currentPtr = currentPtr->next;
		i++;
	}
	return currentPtr->data;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs)
{
	if (rhs.NodeCount() != this->NodeCount())
		return false;

	Node* currentPtr1 = _head;
	Node* currentPtr2 = rhs._head;
	while (currentPtr1 != nullptr)
	{
		if (currentPtr1->data != currentPtr2->data)
			return false;
		currentPtr1 = currentPtr1->next;
		currentPtr2 = currentPtr2->next;
	}
	return true;
}

template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data)
{
	Node* tempPtr = node->next;
	Node* newNode = new Node(data);
	newNode->prev = node;
	node->next = newNode;
	newNode->next = tempPtr;
	tempPtr->prev = newNode;
}

template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data)
{
	Node* tempPtr = node->prev;
	Node* newNode = new Node(data);
	newNode->next = node;
	node->prev = newNode;
	newNode->prev = tempPtr;
	tempPtr->next = newNode;
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{
	if (index > this->NodeCount())
		throw out_of_range("ERROR INDEX OUT OF RANGE");
	unsigned int i = 0;
	Node* currentPtr = _head;
	while (i < index)
	{
		currentPtr = currentPtr->next;
		i++;
	}
	if (currentPtr == nullptr)
		AddTail(data);
	else if (currentPtr->prev == nullptr)
		AddHead(data);
	else
	{
		Node* tempPtr = currentPtr->prev;
		Node* newNode = new Node(data);
		newNode->next = currentPtr;
		currentPtr->prev = newNode;
		newNode->prev = tempPtr;
		tempPtr->next = newNode;
	}
}

template <typename T>
bool LinkedList<T>::RemoveHead()
{
	if (_head != nullptr)
	{
		Node* tempPtr = _head->next;
		delete _head;
		_head = tempPtr;
		if (_head != nullptr)
			_head->prev = nullptr;
		return true;
	}
	return false;
}

template <typename T>
bool LinkedList<T>::RemoveTail()
{
	if (_tail != nullptr)
	{
		Node* tempPtr = _tail->prev;
		delete _tail;
		_tail = tempPtr;
		if (_tail != nullptr)
			_tail->next = nullptr;
		else
			_head = nullptr;
		return true;
	}
	return false;
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data)
{
	unsigned int removals = 0;
	Node* currentPtr = _head;
	while (currentPtr != nullptr)
	{
		if (currentPtr->data == data)
		{
			Node* prevPtr = currentPtr->prev;
			Node* nextPtr = currentPtr->next;
			delete currentPtr;
			removals++;
			prevPtr->next = nextPtr;
			nextPtr->prev = prevPtr;
			currentPtr = nextPtr;
		}
		else
			currentPtr = currentPtr->next;
	}
	return removals;
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index)
{
	if (index >= this->NodeCount())
		return false;
	unsigned int i = 0;
	Node* currentPtr = _head;
	while (i < index)
	{
		currentPtr = currentPtr->next;
		i++;
	}
	Node* prevPtr = currentPtr->prev;
	Node* nextPtr = currentPtr->next;
	delete currentPtr;
	prevPtr->next = nextPtr;
	nextPtr->prev = prevPtr;
	return true;
}

template <typename T>
void LinkedList<T>::Clear()
{
	Node* currentNode = _head;
	while (currentNode != nullptr)
	{
		Node* tempNode = currentNode->next;
		delete currentNode;
		currentNode = tempNode;
	}
	_head = nullptr;
	_tail = nullptr;
}

template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const
{
	cout << node->data << endl;
	Node* currentPtr = node->next;
	while (currentPtr != nullptr)
	{
		cout << currentPtr->data << endl;
		currentPtr = currentPtr->next;
	}
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const
{
	cout << node->data << endl;
	Node* currentPtr = node->prev;
	while (currentPtr != nullptr)
	{
		cout << currentPtr->data << endl;
		currentPtr = currentPtr->prev;
	}
}
