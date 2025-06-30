#include <iostream>

#include "iter.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q main > /dev/null 2> /dev/null"))
		system("leaks -q main");
}
#endif

static void printChar(const char &c)
{
	std::cout << c << " ";
}

static void printInt(const int &i)
{
	std::cout << i << " ";
}

static void doubleIt(int &i)
{
	i *= 2;
}

int main()
{
	const char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	int intArray[] = {1, 2, 3, 4, 5};

	iter(intArray, 5, printInt);
	std::cout << std::endl;

	iter(charArray, 5, printChar);
	std::cout << std::endl;

	iter(intArray, 5, doubleIt);
	iter(intArray, 5, printInt);
	std::cout << std::endl;
}
