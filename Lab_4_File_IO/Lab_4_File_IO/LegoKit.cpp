#include "LegoKit.h"

LegoKit::LegoKit(std::string number, std::string theme, std::string name, double price, int mini, int pieces)
{
	_setNumber = number;
	_theme = theme;
	_name = name;
	_price = price;
	_miniFigures = mini;
	_pieces = pieces;
}

std::string LegoKit::GetNumber()
{
	return _setNumber;
}

std::string LegoKit::GetTheme()
{
	return _theme;
}

std::string LegoKit::GetName()
{
	return _name;
}

double LegoKit::GetPrice()
{
	return _price;
}

int LegoKit::GetMini()
{
	return _miniFigures;
}

int LegoKit::GetPieces()
{
	return _pieces;
}