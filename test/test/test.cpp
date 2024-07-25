// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Screwing around with some git functionality!

#include <iostream>
#include <sstream>

int main()
{
    std::string input;
    input = "hello world \n hello hello";
    std::stringstream ss(input);
    while (ss.good())
    {
        std::string token;
        ss >> token;

        std::cout << token << std::endl;
    }
}