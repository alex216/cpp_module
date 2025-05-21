#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->_Name = "Default";
	std::cout << this->_Name << "\tConstructed\t\t\t(DiamondTrap override)" << std::endl;
	this->_Hit_points = FragTrap::FragTrap_HEALTH_PTS;
	this->_Energy_points = ScavTrap::ScavTrap_ENERGY_PTS;
	this->_Attack_damage = FragTrap::FragTrap_ATTACK_DMG;
	DiamondTrap::HEALTH_PTS = FragTrap::FragTrap_HEALTH_PTS;
	return;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), _Name(name)
{
	this->_Name = name;
	std::cout << this->_Name << "\tConstructed\t\t\t(DiamondTrap override)" << std::endl;
	this->_Hit_points = FragTrap::FragTrap_HEALTH_PTS;
	this->_Energy_points = ScavTrap::ScavTrap_ENERGY_PTS;
	this->_Attack_damage = FragTrap::FragTrap_ATTACK_DMG;
	DiamondTrap::HEALTH_PTS = FragTrap::FragTrap_HEALTH_PTS;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
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

// own capability
void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_Name << " and my ClapTrap name is " << this->ClapTrap::_Name << std::endl;
	std::cout << "Hit points: " << this->getHit_points() << std::endl;
	std::cout << "Energy points: " << this->getEnergy_points() << std::endl;
	std::cout << "Attack damage: " << this->getAttack_damage() << std::endl;
}
