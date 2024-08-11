#include "RNG.h"
#include <ctime>


// static variables must be redeclared in global space
std::mt19937 RNG::random(time(0));

int RNG::Int(int min, int max)
{
	std::uniform_int_distribution<int> dist(min, max);
	return dist(random);
}

float RNG::Float(float min, float max)
{
	std::uniform_real_distribution<float> dist(min, max);
	return dist(random);
}