#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main()
{
	int num = 3;

	// two ways to create a zombie horde
	// 1. using zombieHorde function
	// 2. using new operator
	Zombie *zombieArray = zombieHorde(num, "alice");
	// Zombie *zombieArray = new Zombie[num];

	if (zombieArray == nullptr)
	{
		std::cerr << "Failed to create zombie horde." << std::endl;
		return EXIT_FAILURE;
	}
	for (int i = 0; i < num; i++)
	{
		zombieArray[i].announce();
	}

	// delete[] is necessary
	delete[] zombieArray;
}
