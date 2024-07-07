#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Hero.h"
using namespace std;

void FileCreator()
{
	ofstream outFile("data/info.csv");
	Hero h1("Thor Odinson", 100, 250);
	Hero h2("Batman", 50, 120);
	Hero h3;
	vector<Hero> heroes;
	heroes.push_back(h1);
	heroes.push_back(h2);
	heroes.push_back(h3);
	// Write header data to the file
	outFile << "Name," << "Strength," << "Hitpoints" << ',';
	outFile << "Level," << "Experience," << "Max HP" << endl;

	for (unsigned int i = 0; i < heroes.size(); i++)
	{
		heroes[i].Serialize(outFile);
		//outFile << heroes[i].GetName() << ',';
		//outFile << heroes[i].GetStrength() << ',';
		//outFile << heroes[i].GetHitpoints();

		if (i != heroes.size() - 1)
			outFile << endl;
	}
}

int main()
{
	vector<Hero> heroes;
	// Read afile with a count
	ifstream inFile("data/info.heroes");
	if (inFile.is_open())
	{
		// 1. Read the count
		int count;
		inFile >> count;
		cout << "Count: " << count << endl;
		inFile.get(); // gets the \n char at the end of first line

		// 2. for (count)
			// Read individual objects
		for (unsigned int i = 0; i < count; i++)
		{
			string name;
			string strength;
			string hp;
			getline(inFile, name, ',');
			getline(inFile, strength, ',');
			getline(inFile, hp, '\n');
			heroes.push_back(Hero(name, stoi(strength), stoi(hp)));
		}
		
		for (unsigned int i = 0; i < count; i++)
		{
			heroes[i].PrintInfo();
		}
	}
	


	// Read a CSV file
	ifstream csv("data/info.csv");

	// 1. Read from the header and ignore the first line!
	string lineFromFile;
	getline(csv, lineFromFile);

	// Start getting the data
	while (getline(csv, lineFromFile))
	{
		if (lineFromFile != "")
		{
			// break the data into tokens based on delimiters
			istringstream stream(lineFromFile);
			string token;
			getline(stream, token, ',');
		}
	}


	return 0;

}

// Important note from this live lab - getline uses \n as default delimiter