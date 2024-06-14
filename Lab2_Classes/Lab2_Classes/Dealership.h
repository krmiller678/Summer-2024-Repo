#pragma once
#include "Showroom.h"
using namespace std;

class Dealership
{
private:
	string _name;
	vector<Showroom> _showrooms;
	unsigned int _capacity;

public:
	// Default Constructor
	Dealership(string name = "Generic Dealership", unsigned int capacity = 0); 

	// Behaviors
	void AddShowroom(Showroom s);
	float GetAveragePrice();
	void ShowInventory();
};

