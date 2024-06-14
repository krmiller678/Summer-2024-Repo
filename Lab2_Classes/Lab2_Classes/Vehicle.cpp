#include "Vehicle.h"
#include <iostream>
using namespace std;

// This will house our member function definitions for Vehicle.h

Vehicle::Vehicle()
{
	_make = "COP3503";
	_model = "Rust Bucket";
	_year = 1900;
	_price = 0;
	_miles = 0;
}

Vehicle::Vehicle(string make, string model, int year, float price, int miles)
{
	_make = make;
	_model = model;
	_year = year;
	_price = price;
	_miles = miles;
}

void Vehicle::Display()
{
	cout << _year << " " << _make << " " << _model << " $" << _price << " " << _miles << endl;
}

string Vehicle::GetYearMakeModel()
{
	string toReturn = "";
	toReturn += to_string(_year);
	toReturn += " ";
	toReturn += _make;
	toReturn += " ";
	toReturn += _model;

	return toReturn;
}

float Vehicle::GetPrice()
{
	return _price;
}