#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << this->_Name << "\tConstructed\t\t\t(FragTrap override)" << std::endl;
	this->_Name = "Default";
	this->_Hit_points = FragTrap::FragTrap_HEALTH_PTS;
	this->_Energy_points = FragTrap::FragTrap_ENERGY_PTS;
	this->_Attack_damage = FragTrap::FragTrap_ATTACK_DMG;
	FragTrap::HEALTH_PTS = FragTrap::FragTrap_HEALTH_PTS;
	return;
}

FragTrap::FragTrap(const std::string name)
{
	std::cout << this->_Name << "\tConstructed\t\t\t(FragTrap override)" << std::endl;
	this->_Name = name;
	this->_Hit_points = FragTrap::FragTrap_HEALTH_PTS;
	this->_Energy_points = FragTrap::FragTrap_ENERGY_PTS;
	this->_Attack_damage = FragTrap::FragTrap_ATTACK_DMG;
	FragTrap::HEALTH_PTS = FragTrap::FragTrap_HEALTH_PTS;
	return;
}

// Derived class's copy constructor must explicitly call base class's copy constructor at initialization list
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this == &src)
		return *(this);
	this->_Name = src.getName();
	this->_Hit_points = FragTrap::FragTrap_HEALTH_PTS;
	this->_Energy_points = FragTrap::FragTrap_ENERGY_PTS;
	this->_Attack_damage = FragTrap::FragTrap_ATTACK_DMG;
	FragTrap::HEALTH_PTS = FragTrap::FragTrap_HEALTH_PTS;
	return *(this);
}

FragTrap::~FragTrap(void) // override
{
	std::cout << this->_Name << "\tDestructed💥\t\t\t(FragTrap override)" << std::endl;
	return;
}

void FragTrap::highFivesGuys()
{
	if (this->getHit_points() == 0)
		return;
	unsigned int energy_pts = this->getEnergy_points();
	if (energy_pts == 0)
		return;
	this->setEnery_points(energy_pts - 1);

	std::cout << this->getName() << "\tpositive high fives" << std::endl;
}
