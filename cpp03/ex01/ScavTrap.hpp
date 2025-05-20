#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void); // override
	ScavTrap(const ScavTrap &src);
	ScavTrap &operator=(const ScavTrap &src);
	~ScavTrap(void); // override

	ScavTrap(const std::string name); // overload

	void attack(const std::string &target); // override

	// own capability
	void guardGate();

private:
	static const unsigned int HEALTH_PTS = 100;
	static const unsigned int ENERGY_PTS = 50;
	static const unsigned int ATTACK_PTS = 20;
};
#endif
