// Module1Examples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string example = "Batman";
    size_t search = example.find_first_of('$'); // unsigned int fails to catch npos
    if (search == string::npos)
    {
        cout << "$ not found!";
    }
}
