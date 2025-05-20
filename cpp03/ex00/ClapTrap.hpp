#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &src);			  // copy constructor
	ClapTrap &operator=(const ClapTrap &src); // copy assignment operator
	~ClapTrap(void);

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

private:
	std::string _Name;
	unsigned int _Hit_points;
	unsigned int _Energy_points;
	unsigned int _Attack_damage;

	static const unsigned int HEALTH_PTS = 10;
	static const unsigned int ENERGY_PTS = 10;
	static const unsigned int ATTACK_PTS = 0;
};
#endif
