#include <iostream>

#include "whatever.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q main > /dev/null 2> /dev/null"))
		system("leaks -q main");
}
#endif

int main()
{
	int a = 2;
	int b = 4;
	::swap(a, b);
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "min: " << ::min(a, b) << std::endl;
	std::cout << "max: " << ::max(a, b) << std::endl;

	float c = 2.2;
	float d = 4.4;
	::swap(c, d);
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "min: " << ::min(c, d) << std::endl;
	std::cout << "max: " << ::max(c, d) << std::endl;

	std::string e = "chaine1";
	std::string f = "chaine2";
	::swap(e, f);
	std::cout << "e: " << e << ", f: " << f << std::endl;
	std::cout << "min: " << ::min(e, f) << std::endl;
	std::cout << "max: " << ::max(e, f) << std::endl;
}
