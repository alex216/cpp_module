#include <sstream>

#include "ZombieHorde.hpp"

std::string convertToString(int number)
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}

Zombie *zombieHorde(int N, const std::string &name)
{
	Zombie *zombieArray;

	if (N <= 0)
		return NULL;
	try
	{
		zombieArray = new Zombie[N];
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return NULL;
	}
	for (int i = 0; i < N; i++)
	{
		zombieArray[i].setName(name + convertToString(i));
	}
	return zombieArray;
}
