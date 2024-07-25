// Mod10_Maps_Continued.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	// Store some quiz scores
	map<string, int> scores;

	// Add 2 pair<string, int> using emplace
	scores.emplace("Lee", 85);
	scores.emplace("Joseph", 78);
	scores.emplace("Lee", 90); // emplace only places if has not been created - does nothing here

	// Add 2 pair<string, int> using operator[]
	scores["Alberto"] = 79;
	scores["Martina"] = 92;

	while (true)
	{
		string input;
		cout << "Enter a name to search for (-1 to quit): ";
		getline(cin, input);

		if (input == "-1")
			break;
		if (input == "size")
			cout << "Number of elements in the map: " << scores.size() << endl;
		else
		{
			// 1. Convert user input to lowercase
			string inputLowerCase = input;
			for (unsigned int i = 0; i < inputLowerCase.size(); i++)
				inputLowerCase[i] = tolower(inputLowerCase[i]);
			cout << "Lowercase version of input: " << inputLowerCase << endl;
			
			bool found = false;
			// 2. Iterate over all elements in the container
			map<string, int>::iterator iter = scores.begin(); // this IS the initialization
			for (;iter != scores.end(); ++iter)
			{
				// 3. Convert the key of an element to lowercase
				string keyLowerCase = iter->first;
				for (unsigned int i = 0; i < keyLowerCase.size(); i++)
					keyLowerCase[i] = tolower(keyLowerCase[i]);
			// 4. Compare the lower_input to lower_key for a match
				if (keyLowerCase == inputLowerCase)
				{
					// 5. Print that particular element
					cout << "The score for " << iter->first << " is " << iter->second << endl;
					found = true;
					break;
				}
			}

			if (!found)
				cout << "Person not found!" << endl;
			
			//// Search for the key to verify if it exists before trying to use ie
			// if (scores.find(input) != scores.end())
			//	cout << "The score for " << input << " is " << scores.at(input) << endl;
			//else
			//	cout << "Wrong name!" << endl;
		}

	}
	return 0;
}