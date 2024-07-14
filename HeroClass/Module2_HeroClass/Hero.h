#pragma once
#include <string>
using std::string;

// Class definition
class Hero
{
    // private by default
    int _hitpoints; // How much damage can they take?
    int _level; // What level are they?
    int _experience; // Get experience points to level up
    int _maxHitpoints;
    void LevelUp();

protected:
    string _name; // Who is this?
    int _strength; // How strong are they?


public: // member access operator to get access to these variables and functions
    // Prototype == declaration
    // Only declare defaults in prototype
    // Hero(string name = "Bob"); // Default constructor - must be public
    Hero(string name = "Bob", int strength = 10, int hitpoints = 25);
    void PrintInfo();

    // Accessors or Getters
    int GetHitpoints();
    int GetStrength();
    string GetName();
    int GetLevel();
    int GetExperience();
    
    int GetPowerLevel();

    /*========= MUTATORS ==========*/
    void SetName(string name);
    //void SetStrength(int value);
    //void SetHitpoints(int value);
    //void SetLevel(int value);
    //void SetExperience(int value);
    // Only write mutators if you want to access something and 
    // add some conditions. Otherwise it's basically public

    virtual void TakeDamage(int amount);
    void Heal(int amount);
    void GainExperience(int amount);

    virtual ~Hero() { /* do nothing - virtual only goes on the prototype */ }
    // virtual ~Hero() = 0; would make this an abstract class
};