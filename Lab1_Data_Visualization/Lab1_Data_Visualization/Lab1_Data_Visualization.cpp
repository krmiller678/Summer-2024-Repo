// Lab1_Data_Visualization.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program handles basic input operations including validation and manipulation, it then uses output
// operations to take some data and format it in a way that's presentable.
// setw(int), int stoi(string&), try/catch

/*================================== INCLUDE STATEMENTS ==================================*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/*================================== FUNCTION PROTOTYPES ==================================*/

int main()
{
    // declare used variables
    string title;
    string col1Header;
    string col2Header;

    vector<string> strings;
    vector<int> ints;

    int keepGoing = 0;


    // Gather user defined names for chart headers
    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, col1Header);
    cout << "You entered: " << col1Header << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, col2Header);
    cout << "You entered: " << col2Header << endl;

    // while loop to gather inputs to form our vectors
    while (keepGoing != -1)
    {
        // variable declarations
        string dataPoint;
        string words;
        unsigned int comma;
        int x;

        // Get from user input the data point
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, dataPoint);

        // finding comma and validating only one comma exists
        if (dataPoint == "-1")
            break;
        else
            {
                unsigned int found = dataPoint.find_first_of(",");
                unsigned int found2 = dataPoint.find_last_of(",");
                if (found != found2)
                {
                    cout << "Error: Too many commas in input." << endl;
                    continue;
                }
                else if (dataPoint.find_first_of(",") == string::npos)
                {
                    cout << "Error: No comma in string." << endl;
                    continue;
                }
                else
                    comma = found;
            }

        // separating string into string and int components
        words = dataPoint.substr(0, comma);
        try
        {
            x = stoi(dataPoint.substr(comma + 1));
        }
        catch (invalid_argument)
        {
            cout << "Error: Comma not followed by an integer." << endl;
            continue;
        }

        cout << "Data string: " << words << endl;
        cout << "Data integer: " << x << endl;

        // Add data to vectors
        strings.push_back(words);
        ints.push_back(x);
      
    }

    // now outside of the while loop, our data has been added to our vectors and we need to display
    // syntax for setw == cout << setw(10) << left << "" << "|";
    // syntax for filling space == setfill('-') << setw(10) << "" << endl;
    cout << endl;
    cout << setw(33) << right << title << endl;
    cout << setw(20) << left << col1Header << "|";
    cout << setw(23) << right << col2Header << endl;
    cout << "--------------------------------------------" << endl;
    
    // print out words and ints
    unsigned int y = strings.size();
    for (unsigned int i = 0; i < y; i++)
    {
        cout << setw(20) << left << strings[i] << "|";
        cout << setw(23) << right << ints[i] << endl;
    }
    cout << endl;

    // print histogram
    for (unsigned int i = 0; i < y; i++)
    { 
        cout << setw(20) << right << strings[i] << " ";
        for (unsigned int j = 0; j < ints[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }


    return 0;
}

/*================================== FUNCTION DEFINITIONS ==================================*/