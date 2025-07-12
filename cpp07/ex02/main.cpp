#include <iostream>

#include "Array.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q main > /dev/null 2> /dev/null"))
		system("leaks -q main");
}
#endif

int main()
{
	// example 0
	Array<int> array0(void);

	// example 1
	Array<int> array1(5);
	(void)array1;

	// example 2 // "Try to compile int * a = new int(); then display *a."
	// int *a = new int();
	// std::cout << *a << std::endl;
	// delete a;

	// just like declaring *a, but with a class
	Array<int> *array2 = new Array<int>(5);
	std::cout << (*array2)[0] << std::endl;

	// // example 3
	// test assign ment
	std::cout << "test assignment" << std::endl;
	Array<int> array3_a;
	array3_a = *array2;
	array3_a[0] = 42;
	std::cout << array3_a[0] << std::endl;
	std::cout << (*array2)[0] << std::endl;

	// // test copy constructor
	std::cout << "test copy constructor" << std::endl;
	Array<int> array3_c(*array2);
	array3_c[1] = 42;
	std::cout << array3_c[1] << std::endl;
	std::cout << (*array2)[1] << std::endl;

	// example 4 error
	try
	{
		std::cout << (*array2)[5] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete array2;
}
