#include <string>

std::string SomeFunction(int num1, int num2)
{
	std::string x = std::to_string(num1 + num2);
	return x;
}