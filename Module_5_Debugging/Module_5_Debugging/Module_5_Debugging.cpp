// Module_5_Debugging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include "hero.h"
using namespace std;



int main()
{
    /* 4 main kinds of debugging operations:
    * Set breakpoints - stop here when debugging
    * Step Over - Execute the current line of code and move on to next
    * Step Into - Jump into a function for closer inspection
    * Step Out - Jump out of a function, running any remaining code,
    *   and return to the line after the function call
    */

    // Play around with the Debug menu option and keyboard shortcuts up top!
    // Lots of cool things to play around with. Stepping through issues line
    // by line and setting natural breakpoints. 

    // You can set breakpoints in class member functions as well

    vector<Hero> heroes(5);
    Hero hero("Thor", 120, 300);
    hero.PrintInfo();
    hero.GainExperience(1000);
    hero.PrintInfo();

    return 0;

}