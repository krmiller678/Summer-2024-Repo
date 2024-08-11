#pragma once
#include <random>
class RNG
{
	// One instance of the x variable, shared across all instances  Exists for the lifetime of the program
	static std::mt19937 random;
public:
	// One and only one of this function, there is no "this" with the function
	static int Int(int min, int max);
	static float Float(float min, float max);

};