#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

// Hit points(100)
// Energypoints(100)
// Attack damage(30)
class FragTrap : public ClapTrap
{
public:
	FragTrap(void); // override
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &src);
	~FragTrap(void); // override

	FragTrap(const std::string name); // overload

	// own capability
	void highFivesGuys(void);
};
#endif
