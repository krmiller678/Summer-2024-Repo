// Module3_Time_Comparison.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SimpleTimer.h"
using namespace std;

class BigObject
{
    int LotsOfData[100000];
};

void PassByCopy(BigObject copy)
{
    // not doing anything, just passing a copy of a lot of data
    // Our program still has to "pay" to copy the parameter
}

void PassByReference(BigObject& ref)
{
    // Nothing 
}

void PassByPointer(BigObject* ref)
{
    // nothing
}

int main()
{
    BigObject theObject;
    int count = 300000;
    {
        SimpleTimer t("Passing by copy: ");
        for (int i = 0; i < count; i++)
            PassByCopy(theObject);
    } // the braces are key here! They cause the timer t to be destroyed at the end of the block
    {
        SimpleTimer t("Passing by reference: ");
        for (int i = 0; i < count; i++)
            PassByReference(theObject);
    }
    {
        SimpleTimer t("Passing by pointer: ");
        for (int i = 0; i < count; i++)
            PassByPointer(&theObject);
    }


    return 0;
}
