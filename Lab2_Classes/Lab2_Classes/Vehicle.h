#pragma once
#include <string>
using namespace std;

class Vehicle
{
private:
	string _make;
	string _model;
	unsigned int _year;
	float _price;
	unsigned int _miles;

public:
	Vehicle();
	Vehicle(string make, string model, int year, float price, int miles);
	void Display();
	string GetYearMakeModel();
	float GetPrice();

};