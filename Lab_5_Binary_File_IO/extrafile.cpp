#include <iostream>
#include "extrafile.h"
using namespace std;

Ship::Ship(string name, string classy, short length, int shield, float speed, int numWeapons)
{
	_name = name;
	_class = classy;
	_length = length;
	_shield = shield;
	_speed = speed;
	_numWeapons = numWeapons;
}

int Ship::MostPowerfulWep()
{
	if (_numWeapons > 0)
	{
		int mostPower = vecOfWeps[0]._wepPower;
		for (int i = 0; i < _numWeapons; i++)
		{
			if (vecOfWeps[i]._wepPower > mostPower)
				mostPower = vecOfWeps[i]._wepPower;
		}
		return mostPower;
	}
	else
		return 0;
}

int Ship::TotalPower()
{
	if (_numWeapons > 0)
	{
		int totalPower = 0;
		for (int i = 0; i < _numWeapons; i++)
		{
			totalPower += vecOfWeps[i]._wepPower;
		}
		return totalPower;
	}
	else
		return 0;
}

void Ship::WeaponSetter(string wepName, int wepPower, float wepCons)
{
	vecOfWeps.push_back(Ship::Weapon(wepName, wepPower, wepCons));
}

void Ship::PrintShip()
{
	cout << "Name: " << _name << endl;
	cout << "Class: " << _class << endl;
	cout << "Length: " << _length << endl;
	cout << "Shield Capacity: " << _shield << endl;
	cout << "Maximum Warp: " << _speed << endl;
	cout << "Armaments: " << endl;

	int totalPower = TotalPower();
	if (totalPower > 0)
	{
		for (int i = 0; i < _numWeapons; i++)
		{
			cout << vecOfWeps[i]._wepName << ", " << vecOfWeps[i]._wepPower << ", "
				<< vecOfWeps[i]._wepCons << endl;
		}
		cout << "Total Firepower: " << totalPower << endl;
	}
	else
		cout << "Unarmed" << endl;

	cout << endl;
}

Ship::Weapon::Weapon(string wepName, int wepPower, float wepCons)
{
	_wepName = wepName;
	_wepPower = wepPower;
	_wepCons = wepCons;
}