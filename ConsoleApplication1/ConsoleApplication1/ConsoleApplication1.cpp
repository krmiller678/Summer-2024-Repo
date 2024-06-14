// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void PrintMessage(const char* message) // const char* is the most basic form of a string we can have... does not have UDFs (methods)
{
	cout << message << endl;
}

int main()
{
	const char* str = "Robin";
	string name = "Batman";
	name.append(" and");
	name.append(" Robin");

	string message = "Hello, World";

	int commaLocation = 0;
	commaLocation = message.find_first_of(',');

	string firstHalf = message.substr(0, commaLocation); // range function is inclusive of first value, excluive of second
	cout << "First half: " << firstHalf << endl;

	string secondHalf = message.substr(commaLocation + 2);
	cout << "Second Half: " << secondHalf << endl;

	//const char* stringData = name.c_str();
	//PrintMessage(stringData);

	PrintMessage(name.c_str());

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
