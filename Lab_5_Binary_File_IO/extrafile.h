#pragma once
#include <string>
#include <vector>
using namespace std;

class Ship
{
	string _name;
	string _class;
	short _length;
	int _shield;
	float _speed;
	int _numWeapons;
	struct Weapon
	{
		string _wepName;
		int _wepPower;
		float _wepCons;
		Weapon(string wepName, int wepPower, float wepCons);
	};
	vector<Weapon> vecOfWeps;

public:

	// Constructor
	Ship(string name, string classy, short length, int shield, float speed, int numWeapons);

	// Getters
	int MostPowerfulWep();
	int TotalPower();

	// Setters
	void WeaponSetter(string wepName, int wepPower, float wepCons);

	// Behaviors
	void PrintShip();
};