#include "Color.h"
#include <iostream>

Color::Color(string name, int value)
{
	_name = name;
	// initialize rgb
	_b = value & 255;
	value >>= 8;
	_g = value & 255;
	value >>= 8;
	_r = value & 255;
	_hex = "0x";
	SetHex();
}

unsigned char Color::GetR() const
{
	return _r;
}

unsigned char Color::GetG() const
{
	return _g;
}

unsigned char Color::GetB() const
{
	return _b;
}

string Color::GetHexValue() const
{
	return _hex;
}

string Color::GetName() const
{
	return _name;
}

void Color::SetHex()
{
	int temp = int(GetR());
	Helper(_hex, temp);
	temp = int(GetG());
	Helper(_hex, temp);
	temp = int(GetB());
	Helper(_hex, temp);
}

void Color::Helper(string& hex, int temp)
{
	if (temp / 16 > 9)
		hex += char(temp / 16 + 55);
	else
		hex += std::to_string(temp / 16);
	if (temp % 16 > 9)
		hex += char(temp % 16 + 55);
	else
		hex += std::to_string(temp % 16);
}