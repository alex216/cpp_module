#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

// Hit points(10)
// Energy points(10)
// Attack damage(0)
class ClapTrap
{
protected: // change to protected to use in deribed class
	std::string _Name;
	unsigned int _Hit_points;
	unsigned int _Energy_points;
	unsigned int _Attack_damage;

	unsigned int HEALTH_PTS;

public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &src);			  // copy constructor
	ClapTrap &operator=(const ClapTrap &src); // copy assignment operator
	virtual ~ClapTrap(void);				  // base class destructor should be virtual

	ClapTrap(const std::string name);

	std::string getName(void) const;
	unsigned int getHit_points(void) const;
	unsigned int getEnergy_points(void) const;
	unsigned int getAttack_damage(void) const;

	void setHit_points(unsigned int amount);
	void setEnery_points(unsigned int amount);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
#endif
