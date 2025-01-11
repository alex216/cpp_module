#include "Zombie.hpp"
#include "ZombieHorde.hpp"

__attribute__((destructor)) void end(void)
{
	system("leaks Zombie");
}

int main()
{
	int num = 3;
	Zombie *zombieArray = zombieHorde(num, "alice");
	for (int i = 0; i < num; i++)
	{
		zombieArray[i].announce();
	}

	delete[] zombieArray;
}
