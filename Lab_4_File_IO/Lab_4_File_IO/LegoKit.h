#pragma once
#include <string>

class LegoKit
{
	std::string _setNumber;
	std::string _theme;
	std::string _name;
	double _price;
	int _miniFigures;
	int _pieces;

public:
	// Constructor
	LegoKit(std::string number, std::string theme, std::string name, double price, int mini, int pieces);

	// Accessors
	std::string GetNumber();
	std::string GetTheme();
	std::string GetName();
	double GetPrice();
	int GetMini();
	int GetPieces();
};

