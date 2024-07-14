#include <iostream>
#include <fstream>
#include <vector>
#include "Hero.h"
using namespace std;

int main()
{
	Hero h1("Thor Odinson", 100, 250);
	Hero h2("Batman", 50, 120);
	Hero h3;

	// Write the heroes to a file
	ofstream outFile("data/heroes.bin", ios_base::binary);
	
	unsigned int count = 3;
	outFile.write(reinterpret_cast<char*>(&count), sizeof(count)); // uses vector in liveLab

	// string/variable data needs to be written in a 2 step process
	// 1. Write the AMOUNT of data
	// 2. Write the data itself

	string name = h1.GetName();
	//name.c_str(); // returns a char* C-style string
	unsigned int length = name.size() + 1; // + 1 to account for NULL char \0
	outFile.write(reinterpret_cast<char*>(&length), sizeof(length));
	outFile.write(name.c_str(), length); // don't use sizeof because it's alwasy 4 bytes

	int strength = h1.GetStrength();
	outFile.write(reinterpret_cast<char*>(&strength), sizeof(strength));

	int hp = h1.GetHitpoints();
	outFile.write(reinterpret_cast<char*>(&hp), sizeof(hp));

	return 0;
}