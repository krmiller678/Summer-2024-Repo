// Lab_4_File_IO.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This assignment will have you reading files and searching the data retrieved from them.
// Our LegoKit class is going to have all of our mutators and accessors, but overall we are going to save
// some time by using the vector class to house all the data we read as well as keep track of size. Could 
// also update in the future to use a static int in the LegoKit class.

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "LegoKit.h"
using namespace std;

void LegoKitPushBack(vector<LegoKit>& Kit, ifstream& fileToRead);

int main()
{

	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	/*======= Load data from file(s) =======*/
	ifstream fileToRead;
	vector<LegoKit> KitVector;


	if (option == 1)
	{
		fileToRead.open("lego1.csv");
		LegoKitPushBack(KitVector, fileToRead);
	}
	else if (option == 2)
	{
		fileToRead.open("lego2.csv");
		LegoKitPushBack(KitVector, fileToRead);
	}
	else if (option == 3)
	{
		fileToRead.open("lego3.csv");
		LegoKitPushBack(KitVector, fileToRead);
	}
	else if (option == 4)
	{
		fileToRead.open("lego1.csv");
		LegoKitPushBack(KitVector, fileToRead);
		fileToRead.close();
		fileToRead.clear();
		fileToRead.open("lego2.csv");
		LegoKitPushBack(KitVector, fileToRead);
		fileToRead.close();
		fileToRead.clear();
		fileToRead.open("lego3.csv");
		LegoKitPushBack(KitVector, fileToRead);
		fileToRead.clear();
	}
	/*======= Print out how many sets were loaded =======*/


	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;

	cout << "Total number of sets: " << KitVector.size() << endl;
	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Based on the choice, execute the appropriate task and show the results =======*/

	if (choice == 1)
	{
		unsigned int index = 0;
		for (unsigned int i = 0; i < KitVector.size(); i++)
		{
			if (KitVector.at(i).GetPrice() > KitVector.at(index).GetPrice())
				index = i;
		}
		cout << "The most expensive set is: " << endl;
		cout << "Name: " << KitVector.at(index).GetName() << endl;
		cout << "Number: " << KitVector.at(index).GetNumber() << endl;
		cout << "Theme: " << KitVector.at(index).GetTheme() << endl;
		cout << "Price: $" << KitVector.at(index).GetPrice() << endl;
		cout << "Minifigures: " << KitVector.at(index).GetMini() << endl;
		cout << "Piece count: " << KitVector.at(index).GetPieces() << endl;

	}
	else if (choice == 2)
	{
		unsigned int index = 0;
		for (unsigned int i = 0; i < KitVector.size(); i++)
		{
			if (KitVector.at(i).GetPieces() > KitVector.at(index).GetPieces())
				index = i;
		}
		cout << "The set with the highest parts count: " << endl;
		cout << "Name: " << KitVector.at(index).GetName() << endl;
		cout << "Number: " << KitVector.at(index).GetNumber() << endl;
		cout << "Theme: " << KitVector.at(index).GetTheme() << endl;
		cout << "Price: $" << KitVector.at(index).GetPrice() << endl;
		cout << "Minifigures: " << KitVector.at(index).GetMini() << endl;
		cout << "Piece count: " << KitVector.at(index).GetPieces() << endl;
	}
	else if (choice == 3)
	{
		unsigned int count = 0;
		string toSearch;
		getline(cin, toSearch);
		for (unsigned int i = 0; i < KitVector.size(); i++)
		{
			if (KitVector.at(i).GetName().find(toSearch) != string::npos)
			{
				if (count == 0)
				{
					cout << "Sets matching \"" << toSearch << "\":" << endl;
					count++;
				}
				cout << KitVector.at(i).GetNumber() << " ";
				cout << KitVector.at(i).GetName() << " ";
				cout << "$" << KitVector.at(i).GetPrice() << endl;
			}
		}
		if (count == 0)
			cout << "No sets found matching that search term";
	}
	else if (choice == 4)
	{
		unsigned int count = 0;
		string toSearch;
		getline(cin, toSearch);
		for (unsigned int i = 0; i < KitVector.size(); i++)
		{
			if (KitVector.at(i).GetTheme().find(toSearch) != string::npos)
			{
				if (count == 0)
				{
					cout << "Sets matching \"" << toSearch << "\":" << endl;
					count++;
				}
				cout << KitVector.at(i).GetNumber() << " ";
				cout << KitVector.at(i).GetName() << " ";
				cout << "$" << KitVector.at(i).GetPrice() << endl;
			}
		}
		if (count == 0)
			cout << "No sets found matching that search term";
	}
	else if (choice == 5)
	{
		cout << "Average part count for " << KitVector.size() << " sets: ";
		int totalParts = 0;
		for (unsigned int i = 0; i < KitVector.size(); i++)
		{
			totalParts += KitVector.at(i).GetPieces();
		}
		cout << totalParts / KitVector.size();
	}
	else if (choice == 6)
	{
		cout << "Average price for " << KitVector.size() << " sets: $";
		double totalPrice = 0;
		int minPriceIndex = 0;
		int maxPriceIndex = 0;
		for (unsigned int i = 0; i < KitVector.size(); i++)
		{
			totalPrice += KitVector.at(i).GetPrice();
			if (KitVector.at(i).GetPrice() < KitVector.at(minPriceIndex).GetPrice())
				minPriceIndex = i;
			if (KitVector.at(i).GetPrice() > KitVector.at(maxPriceIndex).GetPrice())
				maxPriceIndex = i;
		}
		cout << totalPrice / KitVector.size() << endl;
		cout << "Least expensive set: " << endl;
		cout << "Name: " << KitVector.at(minPriceIndex).GetName() << endl;
		cout << "Number: " << KitVector.at(minPriceIndex).GetNumber() << endl;
		cout << "Theme: " << KitVector.at(minPriceIndex).GetTheme() << endl;
		cout << "Price: $" << KitVector.at(minPriceIndex).GetPrice() << endl;
		cout << "Minifigures: " << KitVector.at(minPriceIndex).GetMini() << endl;
		cout << "Piece count: " << KitVector.at(minPriceIndex).GetPieces() << endl;

		cout << "Most expensive set: " << endl;
		cout << "Name: " << KitVector.at(maxPriceIndex).GetName() << endl;
		cout << "Number: " << KitVector.at(maxPriceIndex).GetNumber() << endl;
		cout << "Theme: " << KitVector.at(maxPriceIndex).GetTheme() << endl;
		cout << "Price: $" << KitVector.at(maxPriceIndex).GetPrice() << endl;
		cout << "Minifigures: " << KitVector.at(maxPriceIndex).GetMini() << endl;
		cout << "Piece count: " << KitVector.at(maxPriceIndex).GetPieces() << endl;

		
	}
	else if (choice == 7)
	{
		cout << "Average number of minifigures: ";
		int totalMinis = 0;
		int mostMinisIndex = 0;
		for (unsigned int i = 0; i < KitVector.size(); i++)
		{
			totalMinis += KitVector.at(i).GetMini();
			if (KitVector.at(i).GetMini() > KitVector.at(mostMinisIndex).GetMini())
				mostMinisIndex = i;
		}
		cout << totalMinis / KitVector.size() << endl;
		cout << "Set with the most minifigures: " << endl;
		cout << "Name: " << KitVector.at(mostMinisIndex).GetName() << endl;
		cout << "Number: " << KitVector.at(mostMinisIndex).GetNumber() << endl;
		cout << "Theme: " << KitVector.at(mostMinisIndex).GetTheme() << endl;
		cout << "Price: $" << KitVector.at(mostMinisIndex).GetPrice() << endl;
		cout << "Minifigures: " << KitVector.at(mostMinisIndex).GetMini() << endl;
		cout << "Piece count: " << KitVector.at(mostMinisIndex).GetPieces() << endl;
	}
	else if (choice == 8)
	{
		double totalCost = 0;
		int totalPieces = 0;
		int totalMinis = 0;
		for (unsigned int i = 0; i < KitVector.size(); i++)
		{
			totalCost += KitVector.at(i).GetPrice();
			totalPieces += KitVector.at(i).GetPieces();
			totalMinis += KitVector.at(i).GetMini();
		}
		cout << "If you bought one of everything..." << endl;
		cout << "It would cost: $" << totalCost;
		cout << "You would have " << totalPieces << " pieces in your collection" << endl;
		cout << "You would have an army of " << totalMinis << " minifigures!";
	}


	return 0;
}

void LegoKitPushBack(vector<LegoKit>& Kit, ifstream& fileToRead)
{
	string singleLine;
	std::string number;
	std::string theme;
	std::string name;
	int mini;
	int pieces;
	double price;
	
	if (fileToRead.is_open())
	{
		// Throw away the header line! 
		getline(fileToRead, singleLine);
		while (getline(fileToRead, singleLine))
		{
			string token;
			istringstream stream(singleLine);
			getline(stream, token, ',');
			number = token;
			getline(stream, token, ',');
			theme = token;
			getline(stream, token, ',');
			name = token;
			getline(stream, token, ',');
			mini = stoi(token);
			getline(stream, token, ',');
			pieces = stoi(token);
			getline(stream, token, ',');
			price = stod(token);
			Kit.push_back(LegoKit(number, theme, name, price, mini, pieces));
		}
	}
}