#include "ClapTrap.hpp"
#include <cassert>

#define HEALTH_PTS 10
#define ENERGY_PTS 10
#define ATTACK_PTS 0

int main()
{
	std::cout << "\033[32mTesting default constructor\033[0m" << std::endl;
	ClapTrap Default;
	assert(Default.getName() == "Default");
	assert(Default.getHit_points() == HEALTH_PTS);
	assert(Default.getEnergy_points() == ENERGY_PTS);
	assert(Default.getAttack_damage() == ATTACK_PTS);

	std::cout << "\033[32mTesting parameterized constructor\033[0m" << std::endl;
	ClapTrap Alice("Alice");
	assert(Alice.getName() == "Alice");
	assert(Alice.getHit_points() == HEALTH_PTS);
	assert(Alice.getEnergy_points() == ENERGY_PTS);
	assert(Alice.getAttack_damage() == ATTACK_PTS);

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
	Alice.beRepaired(42);
	assert(Alice.getHit_points() == HEALTH_PTS); // HP should not exceed max
	assert(Alice.getEnergy_points() == initial_energy - 1);

	std::cout << "\033[32mTesting taking excessive damage\033[0m" << std::endl;
	Alice.takeDamage(42);
	assert(Alice.getHit_points() == 0); // HP should not go below 0

	std::cout << "\033[32mTesting energy_points depletion\033[0m" << std::endl;
	ClapTrap Bob("Bob");
	for (unsigned int i = 0; i < ENERGY_PTS; ++i)
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
