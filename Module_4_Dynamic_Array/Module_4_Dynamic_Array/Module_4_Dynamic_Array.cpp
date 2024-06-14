// Module_4_Dynamic_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Sometimes we need to mimic some functionality of a vector class, but not all of it
// Recall - we cannot just expand memory ie grow an array

#include <iostream>
#include "DynamicArray.h"
using namespace std;

//  need const functions in const reference function
//  void Foo(const DynamicArray& obj)
//  {
//      for (int i = 0; i < obj.GetSize(); i++) // GetSize is not const
//      {
//  
//      }
//  }

void Foo(DynamicArray someArray) // calling the copy constructor, deleting
// the data that the array points to at the end when it falls out of scope
{
    someArray.Print();
}

int main()
{
    DynamicArray array(5);
    array.Add(500);
    array.Add(200);
    array.Add(99);
    array.Add(-99);
    array.Add(-99);
    array.Add(-99);
    array.Print();

    array.Remove();
    array.Print();

    // (const int)    pointer. The ints are constant not the pointer
    const int* thePrivateData = array.GetData(); // not modifiable
    // thePrivateData[10] = 10; won't work! 
    thePrivateData = new int[10]; // This is okay - pointer is movable

    // int* someMemory = new int[100];
    // int* copy = someMemory;
    // 
    // someMemory[0] = 50;
    // 
    // cout << copy[0] << endl;
    // delete[] someMemory;
    // cout << copy[0] << endl; // dangling pointer

    DynamicArray copy = array; // copy constructor time!
    copy.Add(100);
    copy.Print();
    array.Print();


    return 0;
}


//int count;
//cin >> count;
//int* someArray = new int[10];
//// Awesome cool stuff being done with the array! 
//
//// Goal: "Grow" the array by 1 element
//// 1. Allocate space for the new array (10+1 elements)
//int* newArray = new int[10 + 1]; // temporary pointer to new space for data
//
//// 2. Copy elements from the current / soon to be old array into the new array
//for (int i = 0; i < 10; i++)
//    newArray[i] = someArray[i]; // [] dereference pointer automatically
//
//// 3. Delete the current array
//delete[] someArray;
//
//// 4. Redirect the pointer to the new array
//someArray = newArray;
//someArray[10] = 500;