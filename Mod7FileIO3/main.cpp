#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void FileCreator() {
	ofstream outFile("data/file1.txt");

	for (unsigned int i = 0; i < 20; i++)
	{
		outFile << rand() % 50 + 1;
		if (i != 19)
			outFile << ',';
	}

	outFile.close();
	outFile.open("data/file2.txt");

	for (unsigned int i = 0; i < 20; i++)
	{
		outFile << rand() % 50 + 1;
		if (i != 19)
			outFile << endl;
	}
}

int main()
{
	vector<int> numbers;
	ifstream inFile("data/file1.txt");
	if (inFile.is_open())
	{
		string token;

		// Get each token as a string, convert it later! 
		while (getline(inFile, token, ','))
		{
			numbers.push_back(stoi(token));
		}
	}

	cout << "Numbers from file: " << numbers.size() << endl;

}