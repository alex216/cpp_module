#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap() // : ClapTrap() is not necessary
{
	std::cout << this->_Name << "\tConstructed\t\t\t(DiamondTrap override)" << std::endl;
	this->_Name = "Default";
	this->_Hit_points = FragTrap::FragTrap_HEALTH_PTS;
	this->_Energy_points = ScavTrap::ScavTrap_ENERGY_PTS;
	this->_Attack_damage = FragTrap::FragTrap_ATTACK_DMG;
	DiamondTrap::HEALTH_PTS = FragTrap::FragTrap_HEALTH_PTS;
	return;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name) // override
{
	std::cout << this->_Name << "\tConstructed\t\t\t(DiamondTrap override)" << std::endl;
	this->_Name = name;
	this->_Hit_points = FragTrap::FragTrap_HEALTH_PTS;
	this->_Energy_points = ScavTrap::ScavTrap_ENERGY_PTS;
	this->_Attack_damage = FragTrap::FragTrap_ATTACK_DMG;
	DiamondTrap::HEALTH_PTS = FragTrap::FragTrap_HEALTH_PTS;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this == &src)
		return (*this);
	this->_Hit_points = FragTrap::FragTrap_HEALTH_PTS;
	this->_Energy_points = ScavTrap::ScavTrap_ENERGY_PTS;
	this->_Attack_damage = FragTrap::FragTrap_ATTACK_DMG;
	DiamondTrap::HEALTH_PTS = FragTrap::FragTrap_HEALTH_PTS;
	return *(this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << this->_Name << "\tDestructed💥\t\t\t(DiamondTrap override)" << std::endl;
	return;
}

void DiamondTrap::attack(const std::string &target)
{
	if (this->getHit_points() == 0)
		return;
	unsigned int energy_pts = this->getEnergy_points();
	if (energy_pts == 0)
		return;
	this->setEnery_points(energy_pts - 1);

	std::cout << this->getName() << "\tattacks " << target << " with "
			  << this->getAttack_damage() << " damage\t(DiamondTrap override)" << std::endl;
}

// own capability
void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->getName() << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
	std::cout << "Hit points: " << this->getHit_points() << std::endl;
	std::cout << "Energy points: " << this->getEnergy_points() << std::endl;
	std::cout << "Attack damage: " << this->getAttack_damage() << std::endl;
}
