#include "Fixed.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q Fixed > /dev/null 2> /dev/null"))
		system("leaks -q Fixed");
}
#endif

void title(std::string str)
{
	std::cout << std::endl
			  << "#### " << str << std::endl;
}

int main(void)
{
	title("Fixed a");
	Fixed a; // default

	title("Fixed b(a)");
	Fixed b(a); // copy

	title("Fixed c");
	Fixed c; // default

	title("c = b");
	c = b; // assignment

	std::cout << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
