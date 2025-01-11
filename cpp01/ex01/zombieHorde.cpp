#include "ZombieHorde.hpp"
#include <algorithm>
#include <functional>

Zombie *zombieHorde(int N, const std::string &name)
{
	Zombie *zombieArray = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombieArray[i].setName(name + std::to_string(i));
	}
	return zombieArray;
}
