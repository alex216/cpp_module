#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

// Hit points(100)
// Energypoints(100)
// Attack damage(30)
class FragTrap : virtual public ClapTrap
{
protected:
	static const unsigned int FragTrap_HEALTH_PTS = 100;
	static const unsigned int FragTrap_ENERGY_PTS = 100;
	static const unsigned int FragTrap_ATTACK_DMG = 30;

public:
	FragTrap(void);
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &src);
	~FragTrap(void);

	FragTrap(const std::string name);

	// own capability
	void highFivesGuys(void);
};
#endif
