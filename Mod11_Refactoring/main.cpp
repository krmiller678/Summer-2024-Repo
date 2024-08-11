/* Refactoring Example*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void WriteDataOut() 
{
	ofstream outFile("data.bin", ios_base::binary);
	string name = "Batman";
	string nickname = "The Dark Knight";
	string sidekick = "Robin";
	int array[] = { 2, 4, 6, 8, 10 };
	float valueOne = 3.14159f;
	short valueTwo = 32;
	unsigned long long valueThree = 293871938571;

	// Write a string
	unsigned int size = name.size() + 1;
	outFile.write(reinterpret_cast<char*>(&size), sizeof(size));
	outFile.write(name.c_str(), size);

	// Write a string
	size = nickname.size() + 1;
	outFile.write(reinterpret_cast<char*>(& size), sizeof(size));
	outFile.write(nickname.c_str(), size);

	// Write a string
	size = sidekick.size() + 1;
	outFile.write(reinterpret_cast<char*>(&size), sizeof(size));
	outFile.write(sidekick.c_str(), size);

	// Write an array
	for (int i = 0; i < 5; i++)
		outFile.write(reinterpret_cast<char*>(&array[i]), 4);


}


int main()
{
	WriteDataOut();

	ifstream inFile("data.bin", ios_base::binary);
	string name;
	string nickname;
	string sidekick;

	// Read the name from the file
	unsigned int strLength;
	inFile.read(reinterpret_cast<char*>(&strLength), 4); // Read the length of the strength
	char* buffer = new char[strLength];
	inFile.read(buffer, strLength);
	name = buffer;
	delete[] buffer;

	// Read the nickname from the file
	inFile.read(reinterpret_cast<char*>(&strLength), 4); // Read the length of the strength
	buffer = new char[strLength];
	inFile.read(buffer, strLength);
	nickname = buffer;
	delete[] buffer;

	// Read the sidekick from the file
	inFile.read(reinterpret_cast<char*>(&strLength), 4); // Read the length of the strength
	buffer = new char[strLength];
	inFile.read(buffer, strLength);
	sidekick = buffer;
	delete[] buffer;

	int numbers[5];
	for (int i = 0; i < 5; i++)
		inFile.read(reinterpret_cast<char*>(&numbers[i]), 4);
}