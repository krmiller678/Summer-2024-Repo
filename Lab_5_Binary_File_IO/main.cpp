#include <iostream>
#include <fstream>
#include <vector>
#include "extrafile.h"
using namespace std;

void FileReader(ifstream& inFile, vector<Ship>& vecOfShips);

int main()
{
	vector<Ship> ships;

	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;
	
	if (option == 1)
	{
		ifstream inFile("data/friendlyships.shp", ios_base::binary);
		FileReader(inFile, ships);
		inFile.close();
	}
	else if (option == 2)
	{
		ifstream inFile("data/enemyships.shp", ios_base::binary);
		FileReader(inFile, ships);
		inFile.close();
	}
	else
	{
		ifstream inFile("data/friendlyships.shp", ios_base::binary);
		FileReader(inFile, ships);
		inFile.close();

		inFile.open("data/enemyships.shp", ios_base::binary);
		FileReader(inFile, ships);
		inFile.close();
	}


	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	if (option == 1)
	{
		for (unsigned int i = 0; i < ships.size(); i++)
		{
			ships[i].PrintShip();
		}
	}
	else if (option == 2)
	{
		int strongestWeapon = 0;
		for (unsigned int i = 0; i < ships.size(); i++)
		{
			if (ships[i].MostPowerfulWep() > ships[strongestWeapon].MostPowerfulWep())
				strongestWeapon = i;
		}
		ships[strongestWeapon].PrintShip();
	}
	else if (option == 3)
	{
		unsigned int strongestOverall = 0;
		for (unsigned int i = 0; i < ships.size(); i++)
		{
			if (ships[i].TotalPower() > ships[strongestOverall].TotalPower())
				strongestOverall = i;
		}
		ships[strongestOverall].PrintShip();
	}
	else if (option == 4)
	{
		unsigned int weakestOverall = 0;
		for (unsigned int i = 0; i < ships.size(); i++)
		{
			if ((ships[i].TotalPower() < ships[weakestOverall].TotalPower()) && (ships[i].TotalPower() != 0))
				weakestOverall = i;
		}
		ships[weakestOverall].PrintShip();
	}
	else if (option == 5)
	{
		for (unsigned int i = 0; i < ships.size(); i++)
		{
			if (ships[i].TotalPower() == 0)
				ships[i].PrintShip();
		}
	}

	return 0;
}

void FileReader(ifstream& inFile, vector<Ship>& vecOfShips)
{
	int count;
	inFile.read(reinterpret_cast<char*>(&count), sizeof(count));
	for (int i = 0; i < count; i++)
	{
		// String name array
		string name;
		int length;
		inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
		char* tempArray = new char[length];
		inFile.read(tempArray, length);
		name = tempArray;
		delete[] tempArray;

		// String classy array
		string classy;
		inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
		tempArray = new char[length];
		inFile.read(tempArray, length);
		classy = tempArray;
		delete[] tempArray;

		// Easy read variables
		short lengthOfShip;
		int shield;
		float speed;
		int numWeapons;

		inFile.read(reinterpret_cast<char*>(&lengthOfShip), sizeof(lengthOfShip));
		inFile.read(reinterpret_cast<char*>(&shield), sizeof(shield));
		inFile.read(reinterpret_cast<char*>(&speed), sizeof(speed));
		inFile.read(reinterpret_cast<char*>(&numWeapons), sizeof(numWeapons));

		Ship tempShip(name, classy, lengthOfShip, shield, speed, numWeapons);

		if (numWeapons > 0)
		{

			for (int i = 0; i < numWeapons; i++)
			{
				string nameOfWep;
				inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
				tempArray = new char[length];
				inFile.read(tempArray, length);
				nameOfWep = tempArray;
				delete[] tempArray;

				int wepPower;
				float wepCons;
				inFile.read(reinterpret_cast<char*>(&wepPower), sizeof(wepPower));
				inFile.read(reinterpret_cast<char*>(&wepCons), sizeof(wepCons));

				tempShip.WeaponSetter(nameOfWep, wepPower, wepCons);
			}
		}
		vecOfShips.push_back(tempShip);
	}

}