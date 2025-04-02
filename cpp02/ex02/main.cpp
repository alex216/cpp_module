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
			  << "#### " << str << " ####" << std::endl;
}

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}
