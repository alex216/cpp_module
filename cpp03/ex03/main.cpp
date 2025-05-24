#include <cassert>
#include <stdlib.h>
#include <stdio.h>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q claptrap > /dev/null 2> /dev/null"))
		system("leaks -q claptrap");
}
#endif

int main()
{
	DiamondTrap a("Alice");
	DiamondTrap b(a);
	DiamondTrap c;
	c = b;
	std::cerr << "++++++++++++++++++++++++++++++++++" << std::endl;

	a.whoAmI();
	b.whoAmI();
	c.whoAmI();

	std::cerr << "++++++++++++++++++++++++++++++++++" << std::endl;
	a.attack("A's enemy");
	b.attack("B's enemy");
	c.attack("C's enemy");
}
