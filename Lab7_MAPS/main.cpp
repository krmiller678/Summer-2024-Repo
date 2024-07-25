#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

mt19937 random_mt;

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

class State
{
	int _income;
	int _population;
	int _median;
	int _households;
public:
	State(int income = 0, int population = 0, int median = 0, int households = 0)
		: _income(income), _population(population), _median(median), _households(households)
	{/*NOTHING*/}
	void PrintState() const
	{
		cout << "Population: " << _population << endl;
		cout << "Per Capita Income: " << _income << endl;
		cout << "Median Household Income: " << _median << endl;
		cout << "Number of Households: " << _households << endl;
	}
};

void RollDice(unsigned int numberOfRolls, int numberOfSides)
{
	map<int, int> mapOfDice;
	for (int j = 0; j < numberOfSides; j++)
		mapOfDice.emplace((j + 1), 0);
	for (unsigned int i = 0; i < numberOfRolls; i++)
	{
		int roll = Random(1, numberOfSides);
		if (mapOfDice.emplace(roll,0).second == false)
			mapOfDice[roll]++;
	}
	// Iterate and print stuff out
	map<int, int>::iterator _iter = mapOfDice.begin();
	for (; _iter != mapOfDice.end(); ++_iter)
		cout << _iter->first << ": " << _iter->second << endl;
}

int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);


		cout << "Number of times to roll the die: ";
		unsigned int diceRolls;
		cin >> diceRolls;

		cout << "Number of sides on this die: ";
		int diceSides;
		cin >> diceSides;

		  // Roll Dice
		RollDice(diceRolls, diceSides);
	}
	else if (option == 2)
	{
		// Load the states
		ifstream inFile("states.csv");
		string lineToHandle;
		map<string, State> mapOfStates;
		string name;
		int income;
		int population;
		int median;
		int households;
		string token;
		getline(inFile, lineToHandle); //burn through the header line, remember default delimiter is \n
		while (getline(inFile, lineToHandle))
		{
			istringstream stream(lineToHandle);
			getline(stream, token, ',');
			name = token;
			getline(stream, token, ',');
			income = stoi(token);
			getline(stream, token, ',');
			population = stoi(token);
			getline(stream, token, ',');
			median = stoi(token);
			getline(stream, token, ',');
			households = stoi(token);
			mapOfStates[name] = State(income, population, median, households);
		}


		// Get input for option 1 (show all states) or 2 (do a search for a particular state)
		cout << "1. Print all states" << endl;
		cout << "2. Search for a state" << endl;
		cin >> option;
		if (option == 1)
		{
			map<string, State>::iterator iter = mapOfStates.begin();
			for (;iter != mapOfStates.end(); ++iter)
			{
				cout << iter->first << endl;
				iter->second.PrintState();
			}
		}
		else if (option == 2)
		{
			cin >> name;
			if (mapOfStates.find(name) != mapOfStates.end())
			{
				cout << name << endl;
				mapOfStates[name].PrintState();
			}
			else
				cout << "No match found for " << name << endl;
		}

	}

	return 0;
}
