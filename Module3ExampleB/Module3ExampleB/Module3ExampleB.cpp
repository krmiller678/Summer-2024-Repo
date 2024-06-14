// Module3ExampleB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int* ptr1 = array;
    int* ptr2 = &array[0];

    cout << array << ptr1 << ptr2;
}