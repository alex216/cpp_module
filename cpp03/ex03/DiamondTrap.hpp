#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// Hit points(FragTrap)(100)
// Energy points(ScavTrap)(50)
// Attack damage(FragTrap)(30)
class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap &operator=(const DiamondTrap &src);
	~DiamondTrap(void);

	DiamondTrap(const std::string name);

	void attack(const std::string &target);

	// own capability
	void whoAmI(void);
};
#endif
