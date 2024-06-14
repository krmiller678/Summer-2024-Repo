#include "SimpleTimer.h"
#include <iostream>
using std::cout;
using std::endl; // only use this in cpp file so that anything that grabs the header does not get the using

SimpleTimer::SimpleTimer(const char* msg)
{
	message = msg;
	// 1. Get the current time
	start = highResClock::now();
}

SimpleTimer::~SimpleTimer()
{
	end = highResClock::now();
	elapsed = end - start;
	cout << message << elapsed.count() << endl;
}