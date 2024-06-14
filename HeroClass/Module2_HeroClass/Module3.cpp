// Module 3 Example Video 1
#include <iostream>
#include<string>
#include <vector>
#include "Hero.h"
using namespace std;

void StrongestHero(Hero* one, Hero& two); // must match definition
vector<int> GetSomeEvenNumbers(int count, vector<int>& output); // without reference we are passing a copy

int main_not_used_again()
{
	Hero wolverine("Wolverine", 50, 60);
	Hero cyclops("Cyclops", 30, 80);
	cout << "Address in main wolverine: " << &wolverine << endl;
	cout << "Address in main cyclops: " << &cyclops << endl;

	StrongestHero(&wolverine, cyclops);

	vector<int> numbers;
	GetSomeEvenNumbers(10, numbers);
	
	for (unsigned int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << " ";

	return 0;
}

vector<int> GetSomeEvenNumbers(int count, vector<int>& output)
{
	for (int i = 0, value = 2; i < count; i++, value += 2)
		output.push_back(value);
	return output;
}

void StrongestHero(Hero* one, Hero& two) // pass by reference in definition and prototype, same with pointer
{
	cout << "Address in func wolverine: " << one << endl; // pointer stores address of pointee
	cout << "Address in func cyclops: " << &two << endl; // reference has same address as object

	if (one->GetStrength() > two.GetStrength())
		cout << one->GetName() << " is stronger than " << two.GetName() << endl;
	else if (two.GetStrength() > one->GetStrength())
		cout << two.GetName() << " is stronger than " << one->GetName() << endl;
	else
		cout << "An equal match!";
}
