#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *z;

	try
	{
		z = new Zombie(name);
	}
	catch (std::bad_alloc e)
	{
		std::abort();
	}
	return z;
}
