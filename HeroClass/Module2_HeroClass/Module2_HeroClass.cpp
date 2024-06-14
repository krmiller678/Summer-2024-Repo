// Module2_HeroClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;

int main_not_used()
{
    Hero myHero("Robert the Mighty", 10, 25);
    myHero.PrintInfo();

    Hero sidekick("thor", 100, 300);
    sidekick.PrintInfo();

    sidekick.GainExperience(110);
    sidekick.PrintInfo();
    
    return 0;
}


//This is a quirk of C++ syntax.The line CTest t1;
//declares a local variable of type CTest named t1.
//It implicitly calls the default constructor.On the other hand, the line
//CTest t2(); Is not a variable declaration, but a local prototype of a function 
//called t2 that takes no arguments and returns a CTest. 