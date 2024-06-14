// Module2Examples.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This example shows that you can declare libraries in the subset functions that do not need to be accessed by
// the main functions or program.

/*================================== INCLUDE STATEMENTS ==================================*/
#include <iostream>
#include "someFile.h"


/*================================== FUNCTION PROTOTYPES ==================================*/

int main()
{
    std::cout << SomeFunction(1,2);
}

/*================================== FUNCTION DEFINITIONS ==================================*/