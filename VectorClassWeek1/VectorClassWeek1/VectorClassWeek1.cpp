// VectorClassWeek1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std; // intentionally restating namespace below

void PrintNumbers(vector<int> numbers); // prototype of function

int main()
{
    int numbersNotUsed[5] = { 2, 4, 6, 8, 10 }; // this lacks expandability
    //numbers.expand, .shrink, etc will not work because we do not have UDFs

    std::vector<int> numbers_vector; // this is called a template, indicated by <>
    std::vector<std::string> strings_vector; 
    numbers_vector.push_back(2); // this pushes values to the back of a vector, cannot push to the back of an array
    numbers_vector.push_back(4); 
    numbers_vector.push_back(6); 
    numbers_vector.push_back(8); 
    numbers_vector.push_back(10); 
    
    vector<int> v2(5); //size == 5
    v2[0] = 2; // internally, a vector is storing a dynamic array
    v2[1] = 4;
    v2[2] = 6;
    v2[3] = 8;
    v2[4] = 10;

    // Looking at 3 ways of storing the array, but the last way is the fastest because we are predetermining the memory allocation

    // cout << "Number of elements: " << numbers_vector.size() << endl; put this in PrintNumbers function
    PrintNumbers(numbers_vector);
    cout << "Size: " << numbers_vector.size();

    std::vector<std::string> words;
    words.push_back("Batman");
    words.push_back(" and ");
    words.push_back("Robin");

    for (unsigned int i = 0; i < words.size(); i++)
        cout << words[i];



    return 0;
}

void PrintNumbers(vector<int> numbers)
{

    cout << "Number of elements: " << numbers.size() << endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
        cout << numbers.at(i) << " "; // essentially the same as indexing, brackets don't check for errors ie range
    }

    numbers.clear();
    cout <<"Size: " << numbers.size(); // it appears as though a copy is passed to this function
}