#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Creating a function to write numbers - have to pass file by reference
//void WriteNumbers(ofstream& file, vector<int>& numbers, char delimiter)
void WriteNumbers(string filePath, vector<int>& numbers, char delimiter)
{
	ofstream file(filePath);
	// Did the file actually open?
	if (file.is_open())
	{
		// Write the data out
		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			file << numbers[i];

			// Is this the last element in the container?
			if (i < numbers.size() - 1)
				file << delimiter; // comma separated data
		}
		// we use file.close() when we want to reuse the "file" object

	}
	else
		cout << "Error! File " << filePath << " was not opened!";
}

int main()
{
	vector<int> numbers;
	for (int i = 0; i < 20; i++)
		numbers.push_back(rand() % 50 + 1);

	WriteNumbers("data/file1.txt", numbers, ',');
	WriteNumbers("save/file2.txt", numbers, '|');

	return 0;
}