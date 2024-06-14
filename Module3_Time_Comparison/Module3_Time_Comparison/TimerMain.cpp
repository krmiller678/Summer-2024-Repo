#include <chrono>
#include <iostream>
#include <fstream>
#include <limits>
#include "SimpleTimer.h"
using namespace std;
using highResClock = std::chrono::high_resolution_clock; //alias, can use #define for functions

int main_not_used()
{
	/*=======SETUP=======*/
	// Create a big bunch of numbers
	const int numCount = 1000000;
	unsigned long long* someValues = new unsigned long long[numCount];
	for (unsigned int i = 0; i < numCount; i++)
		someValues[i] = std::numeric_limits<unsigned long long>::max();

	ofstream textFile("FileA.txt");
	ofstream binaryFile("fileB.bin");

	/*=========EXECUTION==========*/
	{
		// Write the data in text format
		SimpleTimer timer("Writing values in text format: ");
		for (unsigned i = 0; i < numCount; i++)
			textFile << someValues[i];
	}
	{
		// Write the data in binary format
		SimpleTimer timer("Writing values in binary format: ");
		for (size_t i = 0; i < numCount; i++)
			binaryFile.write((char*)&someValues[i], sizeof(someValues[i]));
	}
	/*========END OF EXECUTION========*/
	textFile.close();
	binaryFile.close();

	return 0;
}