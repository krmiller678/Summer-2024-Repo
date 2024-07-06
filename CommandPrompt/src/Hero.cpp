#include "Hero.h"
#include <iostream>
using namespace std;

//Hero::Hero(string name)
//{
//    _name = name;
//    _strength = 1;
//    _hitpoints = 1;
//    _level = 1;
//    _experience = 0;
//}


Hero::Hero(string name, int strength, int hitpoints)
{
    _name = name;
    _strength = strength;
    _hitpoints = hitpoints;

    // Use defaults
    _level = 1;
    _experience = 0;
    _maxHitpoints = _hitpoints;
}

void Hero::PrintInfo()
{
    cout << "Name: " << _name << endl;
    cout << "Strength: " << _strength << endl;
    cout << "Hitpoints: " << _hitpoints << "/" << _maxHitpoints << endl;
    cout << "Level: " << _level << endl;
    cout << "Experience: " << _experience << endl;
    cout << "Power Level: " << GetPowerLevel() << endl;
}

int Hero::GetHitpoints()
{
    return _hitpoints;
}

int Hero::GetStrength()
{
    return _strength;
}

string Hero::GetName()
{
    return _name;
}

int Hero::GetLevel()
{
    return _level;
}

int Hero::GetExperience()
{
    return _experience;
}

int Hero::GetPowerLevel()
{
    return (_level * 5) + _strength;
}

void Hero::TakeDamage(int amount)
{
    _hitpoints -= amount;
    if (_hitpoints < 0)
        _hitpoints = 0; // gives us an option to set a condition on the mutator
}

void Hero::Heal(int amount)
{
    _hitpoints += amount;
    if (_hitpoints > _maxHitpoints)
        _hitpoints = _maxHitpoints; // gives us an option to set a condition on the mutator
}

void Hero::GainExperience(int amount)
{
    _experience = amount;
    // Level up
    if (_experience > 100)
    {
        LevelUp();
        _experience -= 100;
    }
}

void Hero::LevelUp()
{
    _level++;
    _strength++;
    _hitpoints += 5;
    _maxHitpoints += 5;
}