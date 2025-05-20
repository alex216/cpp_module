#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

// Hit points(100)
// Energypoints(50)
// Attack damage(20)
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
};
#endif
