#pragma once
#include <string>
#include <vector>
#include "Vehicle.h"
using namespace std;

class Showroom
{
private:
	string _name;
	vector<Vehicle> _vehicles;
	unsigned int _capacity;

public:
	// Default Constructor
	Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0); 
	// Accessor
	vector<Vehicle> GetVehicleList();
	// Behaviors
	void AddVehicle(Vehicle V);
	void ShowInventory();
	float GetInventoryValue();
	int GetVehiclesOnLot();
};

