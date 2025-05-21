#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

// Hit points(100)
// Energypoints(50)
// Attack damage(20)
class ScavTrap : virtual public ClapTrap
{
protected:
	static const unsigned int ScavTrap_HEALTH_PTS = 100;
	static const unsigned int ScavTrap_ENERGY_PTS = 50;
	static const unsigned int ScavTrap_ATTACK_DMG = 20;

public:
	ScavTrap(void);
	ScavTrap(const ScavTrap &src);
	ScavTrap &operator=(const ScavTrap &src);
	~ScavTrap(void);

	ScavTrap(const std::string name);

	void attack(const std::string &target);

	// own capability
	void guardGate();
};
#endif
