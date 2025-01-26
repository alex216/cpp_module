#include "Fixed.hpp"
#include <iostream>

__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q Fixed > /dev/null 2> /dev/null"))
		system("leaks -q Fixed");
}

void title(std::string str)
{
	std::cout << std::endl
			  << "#### " << str << " ####" << std::endl;
}

int main(void)
{
	title("Fixed a");
	Fixed a;
	title("b(10)");
	Fixed const b(10);
	title("c(42.42.f)");
	Fixed const c(42.42f);
	title("const d(b)");
	Fixed const d(b);
	title("a = Fixed(1234.4321f)");
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
