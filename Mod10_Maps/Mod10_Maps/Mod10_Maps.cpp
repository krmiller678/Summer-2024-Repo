// Mod10_Maps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    // Store some quiz scores
    map<string, int> scores; // string keys, int values

    // Add 2 pair<string, int> using emplace
    scores.emplace("Lee", 85);
    scores.emplace("Joseph", 78);

    // Add 2 pair<string, int> using operator[] (subscript operator)
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
        {
            cout << "Number of elements in the map: " << scores.size() << endl;
        }
        else
        {
            //cout << "The score for " << input << " is " << scores[input] << endl; // subscript operator will create a key value pair with int == 0
            cout << "The score for " << input << " is " << scores.at(input) << endl; // at() will throw an out of range exception if we call it with bad key
        }
        //12:57 stop time 
    }

    return 0;
}