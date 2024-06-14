#include "Dealership.h"
#include<iostream>

Dealership::Dealership(string name, unsigned int capacity)
{
	_name = name;
	_capacity = capacity;
}

void Dealership::AddShowroom(Showroom s)
{
	if (_showrooms.size() == _capacity)
	{
		cout << "Dealership is full, can't add another showroom!" << endl;
	}
	else
		_showrooms.push_back(s);
}

float Dealership::GetAveragePrice()
{
	float totalValue = 0;
	int inventory = 0;
	if (_showrooms.size() > 0)
	{
		for (unsigned int i = 0; i < _showrooms.size(); i++)
		{
			totalValue += _showrooms.at(i).GetInventoryValue();
			inventory += _showrooms.at(i).GetVehiclesOnLot();
		}
		return totalValue / inventory;
	}
	else
		return totalValue;
}

void Dealership::ShowInventory()
{
	if (_showrooms.size() == 0)
		cout << _name << " is empty!" << endl;
	else 
	{
		for (unsigned int i = 0; i < _showrooms.size(); i++)
		{
			_showrooms.at(i).ShowInventory();
			cout << endl;
		}
	}
	cout << "Average car price: $" << GetAveragePrice();
}