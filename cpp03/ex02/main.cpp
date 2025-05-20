#include <cassert>
#include <stdlib.h>
#include <stdio.h>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q claptrap > /dev/null 2> /dev/null"))
		system("leaks -q claptrap");
}
#endif

int main()
{
	const unsigned int health_pts = 100;
	const unsigned int energy_pts = 100;
	const unsigned int attack_pts = 30;

	std::cout << "\033[32mTesting default constructor\033[0m" << std::endl;
	FragTrap Default;
	assert(Default.getName() == "Default");
	assert(Default.getHit_points() == health_pts);
	assert(Default.getEnergy_points() == energy_pts);
	assert(Default.getAttack_damage() == attack_pts);

	std::cout << "\033[32mTesting parameterized constructor\033[0m" << std::endl;
	FragTrap Alice("Alice");
	assert(Alice.getName() == "Alice");
	assert(Alice.getHit_points() == health_pts);
	assert(Alice.getEnergy_points() == energy_pts);
	assert(Alice.getAttack_damage() == attack_pts);

	std::cout << "\033[32mTesting attack functionality\033[0m" << std::endl;
	unsigned int initial_energy = Alice.getEnergy_points();
	Alice.attack("Enemy");
	assert(Alice.getEnergy_points() == initial_energy - 1);

	std::cout << "\033[32mTesting takeDamage functionality\033[0m" << std::endl;
	unsigned int initial_hp = Alice.getHit_points();
	Alice.takeDamage(5);
	assert(Alice.getHit_points() == initial_hp - 5);

	std::cout << "\033[32mTesting repair functionality\033[0m" << std::endl;
	initial_hp = Alice.getHit_points();
	initial_energy = Alice.getEnergy_points();
	Alice.beRepaired(3);
	assert(Alice.getHit_points() == initial_hp + 3);
	assert(Alice.getEnergy_points() == initial_energy - 1);

	std::cout << "\033[32mTesting repair with just enough health\033[0m" << std::endl;
	Alice.takeDamage(5);
	initial_hp = Alice.getHit_points();
	initial_energy = Alice.getEnergy_points();
	Alice.beRepaired(2);
	assert(Alice.getHit_points() == initial_hp + 2);
	assert(Alice.getEnergy_points() == initial_energy - 1);

	std::cout << "\033[32mTesting repair with too much health\033[0m" << std::endl;
	initial_hp = Alice.getHit_points();
	initial_energy = Alice.getEnergy_points();
	Alice.beRepaired(142);
	assert(Alice.getHit_points() == health_pts); // HP should not exceed max
	assert(Alice.getEnergy_points() == initial_energy - 1);

	std::cout << "\033[32mTesting taking excessive damage\033[0m" << std::endl;
	Alice.takeDamage(1000);
	assert(Alice.getHit_points() == 0); // HP should not go below 0

	std::cout << "\033[32mTesting energy_points depletion\033[0m" << std::endl;
	FragTrap Bob("Bob");
	for (unsigned int i = 0; i < energy_pts; ++i)
	{
		unsigned int initial_energy = Bob.getEnergy_points();
		Bob.attack("Enemy");
		assert(Bob.getEnergy_points() == initial_energy - 1);
	}
	// After ENERGY_PTS attacks, energy_points should be 0
	assert(Bob.getEnergy_points() == 0);

	// Attempting to attack with 0 energy_points should not decrease energy further
	std::cout << "\033[32mTesting attack with 0 energy points\033[0m" << std::endl;
	Bob.attack("Enemy");
	std::cout << "\033[32mAbove line should not crash and nothing should happen\033[0m" << std::endl;
	assert(Bob.getEnergy_points() == 0);

	std::cout << "\033[32mAll tests passed successfully!\033[0m" << std::endl;
}
