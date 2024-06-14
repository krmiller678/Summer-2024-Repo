#pragma once
#include <chrono>
#include <string>
using std::string;
using highResClock = std::chrono::high_resolution_clock; //alias, can use #define for functions

class SimpleTimer
{
	highResClock::time_point start;
	highResClock::time_point end;
	std::chrono::duration<double> elapsed;
	string message;

public:
	SimpleTimer(const char* msg);
	~SimpleTimer();
};

