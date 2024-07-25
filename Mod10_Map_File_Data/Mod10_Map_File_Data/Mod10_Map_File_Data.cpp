// Mod10_Map_File_Data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<string, vector<string>> dictionary; // a little bit faster - does not do sorting
	ifstream inFile("dictionary.txt");

	/*======== LOAD DICTIONARY DATA FROM A FILE	=========*/
	string lineFromFile;
	while (getline(inFile, lineFromFile))
	{
		// Break the line into two parts: Word | Definition
		int delimiter = lineFromFile.find_first_of('|');
		string word = lineFromFile.substr(0, delimiter);
		string definition = lineFromFile.substr(delimiter + 1);

		// Store the pair
		//auto result = dictionary.emplace(word, vector<string>()); // emplace fails to add duplicate key, emplace returns pair <iterator, bool>
		//if (result.second == true)
		//	dictionary[word].push_back(definition);
		//else
		dictionary[word].push_back(definition); // simultaneously does everything! 
		// Alternatively: dictionary[word] = definition;

	}
	cout << "Number of entries: " << dictionary.size() << endl;

	string input;
	cout << "Enter a word: ";
	getline(cin, input);
	for (unsigned int i = 0; i < dictionary[input].size(); i++)
		cout << dictionary[input].at(i) << endl;

}