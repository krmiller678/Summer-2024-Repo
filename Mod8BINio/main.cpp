#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> numbers;
	// Generate some random numbers
	for (int i = 0; i < 20; i++)
		numbers.push_back(rand() % 50 + 1);

	// Write values to atext file
	ofstream textFile("data/numbers.txt");
	for (unsigned int i = 0; i < numbers.size(); i++)
		textFile << numbers[i] << endl;

	// Write values to a binary file
	// "bin" is just an extension, does not make the file binary
	// ios_base::binary flag == open the file in binary mode
	ofstream binaryFile("data/numbers.bin", ios_base::binary);

	int x = 10;
	// Always use write for binary files, first arg is address as a char ptr
	// second is byte count -> you can use sizeof()
	// &x == int*
	// (int)number == C-style cast, (char*) &x == C-style cast
	//binaryFile.write((char*) &x, sizeof(x));
	//binaryFile.write(reinterpret_cast<char*>(&x), sizeof(x)); // C++ cast

	// Write out the count
	unsigned int size = numbers.size();
	binaryFile.write(reinterpret_cast<char*>(&size), 4);

	// Write out the data
	for (unsigned int i = 0; i < numbers.size(); i++)
		binaryFile.write(reinterpret_cast<char*>(&numbers[i]), sizeof(numbers[i]));

	return 0;
}