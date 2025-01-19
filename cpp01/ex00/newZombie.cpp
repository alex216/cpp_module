#include <cstdlib>
#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *z;

	try
	{
		z = new Zombie(name);
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return z;
}
