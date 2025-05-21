#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

// Hit points(10)
// Energy points(10)
// Attack damage(0)
class ClapTrap
{
protected:
	static const unsigned int ClapTrap_HEALTH_PTS = 10;
	static const unsigned int ClapTrap_ENERGY_PTS = 10;
	static const unsigned int ClapTrap_ATTACK_DMG = 0;

	std::string _Name;
	unsigned int _Hit_points;
	unsigned int _Energy_points;
	unsigned int _Attack_damage;

	unsigned int HEALTH_PTS;

public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &src);
	virtual ~ClapTrap(void);

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
