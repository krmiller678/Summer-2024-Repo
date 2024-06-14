#include "Showroom.h"
#include <iostream>

Showroom::Showroom(string name, unsigned int capacity)
{
	_name = name;
	_capacity = capacity;
}

vector<Vehicle> Showroom::GetVehicleList()
{
	return _vehicles;
}

void Showroom::AddVehicle(Vehicle V)
{
	if (_vehicles.size() == _capacity)
	{
		cout << "Showroom is full! Cannot add " << V.GetYearMakeModel() << endl;
	}
	else
		_vehicles.push_back(V);
}

void Showroom::ShowInventory()
{
	if (_vehicles.size() == 0)
		cout << _name << " is empty!" << endl;
	else
	{
		cout << "Vehicles in " << _name << endl;
		for (unsigned int i = 0; i < _vehicles.size(); i++)
		{
			_vehicles.at(i).Display();
		}
	}
}

float Showroom::GetInventoryValue()
{
	float inventoryValue = 0;
	for (unsigned int i = 0; i < _vehicles.size(); i++)
	{
		inventoryValue += _vehicles.at(i).GetPrice();
	}
	return inventoryValue;
}

int Showroom::GetVehiclesOnLot()
{
	return _vehicles.size();
}