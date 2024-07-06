#include <iostream>
using namespace std;
#include "Hero.h"

int main()
{
	string name;
	int strength;
	int hitpoints;
	cout << "Enter a name for the hero: ";
	getline(cin, name);

	cout <<"Enter a strength value: ";
	cin >> strength;

	cout << "Enter a hitpoints value: ";
	cin >> hitpoints;

	Hero hero(name, strength, hitpoints);
	cout << "Your hero's data:" << endl;;
	hero.PrintInfo();

	return 0;

}