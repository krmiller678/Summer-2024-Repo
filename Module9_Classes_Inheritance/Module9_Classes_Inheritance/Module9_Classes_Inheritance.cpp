// Module9_Classes_Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "Z:\CODE\UF SUMMER 2024\Summer-2024-Repo\HeroClass\Module2_HeroClass\Hero.h"
using namespace std;

class Wizard : virtual public Hero // Wizard IS-A Hero
{
    int _mana;
    int _maxMana;
public:
    Wizard(string name = "Bob", int strength = 10, int hitpoints = 25, int mana = 100);
    void PrintInfo();
    void TakeDamage(int amount);
};
Wizard::Wizard(string name, int strength, int hitpoints, int mana)
    : _mana(mana), Hero(name,strength,hitpoints) // constructor initializer list, calls base class constructor
{
    //this->_name = name;
    //this->_strength = strength;
    //this-> method works when you move the base class variables into a protected category -> they are accessible by derived classes
    // don't do this: Hero(name, strength, hitpoints);
    _maxMana = mana;
}
void Wizard::PrintInfo()
{
    // Print Hero specific information
    Hero::PrintInfo();

    // Print wizard specific information
    cout << "Mana: " << _mana << "/" << _maxMana << endl;

}
void Wizard::TakeDamage(int amount)
{
    if (_mana >= amount)
    {
        // Take 0 damage, our magic barrier negates all of it!
        _mana -= amount;
        amount = 0;
    }
    else if (_mana < amount)
    {
        amount -= _mana;
    }
    Hero::TakeDamage(amount);
    cout << "This was a virtual damage call!";
}

class Fighter : virtual public Hero
{
    int _fury;
public:
    Fighter(string name, int strength, int hitpoints)
        : Hero(name, strength, hitpoints), _fury(100)
    {
    }
};

int main()
{
    Wizard merlin("Merlin the Magnificent", 15, 70);
    merlin.PrintInfo();
    merlin.TakeDamage(120);
    merlin.PrintInfo();
    Fighter conan("Conan", 80, 350);
    conan.PrintInfo();

    vector<Hero*> heroes;
    heroes.push_back(new Wizard("Merlin", 15, 70, 250));
    heroes.push_back(new Fighter("Conan", 80, 350));
    cout << "Heroes are dealt 100 damage... \n";
    for (unsigned int i = 0; i < heroes.size(); i++)
        heroes[i]->TakeDamage(100); // going to the virtual table at runtime to determine which take damage, super cool! 

    for (unsigned int i = 0; i < heroes.size(); i++)
    {
        delete heroes[i]; // ~Hero() is called after ~Wizard() or ~Fighter()
        // Hero is constructed first, then Wizard is constructed. Deleting goes in the opposite direction
    }
}