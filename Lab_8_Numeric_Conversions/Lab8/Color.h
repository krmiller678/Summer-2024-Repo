#pragma once
#include <string>
using std::string;

class Color
{
private:
	string _name;
	string _hex;
	unsigned char _r;
	unsigned char _g;
	unsigned char _b;

public:
	// Constructor
	Color(string name = "", int value = 0);
	// Accessors 
	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;
	string GetHexValue() const;
	string GetName() const;
	void SetHex();
	void Helper(string& hex, int temp);
};

