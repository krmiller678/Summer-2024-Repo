#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <map>
#include "Color.h"
using namespace std;

void ReadFile(const char* filename, map<string, Color>& colors);
void PrintColors(const map<string, Color>& colors);
void PrintColor(const Color& color);
void SearchForColor(map<string, Color>& colors);

int main()
{
	cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
	cout << "7. Load all 6 files" << endl;
	int choice;
	cin >> choice;

	map<string, Color> colors;
	if (choice >= 1 && choice <= 6)
	{
		string file = "colors" + to_string(choice) + ".txt";
		ReadFile(file.c_str(), colors);
	}
	else if (choice == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}

	}

	// Secondary menu
	cout << "1. Show all colors" << endl;
	cout << "2. Search for a color" << endl;
	cin >> choice;

	if (choice == 1)
		PrintColors(colors);
	else if (choice == 2)
		SearchForColor(colors);
	return 0;
}

void ReadFile(const char* filename, map<string, Color>& colors)
{
	ifstream inFile(filename);
	string lineToRead;
	string name;
	istringstream buffer;
	string tempVal;
	int value;
	if (inFile.is_open())
	{
		while (getline(inFile, lineToRead))
		{
			buffer.str(lineToRead);
			getline(buffer, name, ' ');
			getline(buffer, tempVal);
			value = stoi(tempVal);
			buffer.clear();
			colors.emplace(name, Color(name, value));
		}
	}
		
}
void PrintColors(const map<string, Color>& colors)
{
	auto iter = colors.begin();
	while (iter != colors.end())
	{
		PrintColor(iter->second);
		iter++;
	}
	cout << "Number of colors: " << colors.size();

}
void PrintColor(const Color& color)
{
	cout << left << setw(20) << color.GetName();
	cout << right << setw(10) << color.GetHexValue();
	cout << "\t\t" << (int)color.GetR() << "," << (int)color.GetG() << "," << (int)color.GetB() << endl;
}
void SearchForColor(map<string, Color>& colors)
{
	string findMe;
	cin >> findMe;
	if (colors.find(findMe) != colors.end())
		PrintColor(colors.find(findMe)->second);
	else
		cout << findMe << " not found!" << endl;
}