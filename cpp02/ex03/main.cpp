#include "Fixed.hpp"
#include <iostream>

#include "Point.hpp"
#include "bsp.hpp"

__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q bsp > /dev/null 2> /dev/null"))
		system("leaks -q bsp");
}

void title(std::string str)
{
	std::cout << std::endl
			  << "#### " << str << " ####" << std::endl;
}

// bsp is for experiment use only, since Fixed class has many undefined behaviour.
int main(void)
{
	// y
	// ^
	// |
	// |.b..    p:inside
	// |.p.q    q:outside
	// |a.dc
	// +------->x
	Point a(1, 1);
	Point b(2, 4);
	Point c(4, 1);
	Point d(3, 1);

	Point p(2, 2);
	Point q(4, 2);

	// inside 1
	std::cout << bsp(a, b, c, p) << std::endl;

	// outside 0
	std::cout << bsp(a, b, c, q) << std::endl;

	// vertex 0
	std::cout << bsp(a, b, c, c) << std::endl;

	// edge 0
	std::cout << bsp(a, b, c, d) << std::endl;

	// not a triangle
	std::cout << bsp(a, b, d, d) << std::endl;

	return 0;
}
