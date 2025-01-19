#include "ZombieHorde.hpp"
#include <algorithm>
#include <functional>

Zombie *zombieHorde(int N, const std::string &name)
{
	Zombie *zombieArray;

	if (N <= 0)
		return nullptr;
	try
	{
		zombieArray = new Zombie[N];
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return nullptr;
	}
	for (int i = 0; i < N; i++)
	{
		zombieArray[i].setName(name + std::to_string(i));
	}
	return zombieArray;
}
