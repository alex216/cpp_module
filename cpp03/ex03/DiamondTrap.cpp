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
	std::cout << this->_Name << "\tConstructed(with name)\t\t(DiamondTrap override)" << std::endl;
	this->_Hit_points = FragTrap::FragTrap_HEALTH_PTS;
	this->_Energy_points = ScavTrap::ScavTrap_ENERGY_PTS;
	this->_Attack_damage = FragTrap::FragTrap_ATTACK_DMG;
	DiamondTrap::HEALTH_PTS = FragTrap::FragTrap_HEALTH_PTS;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << this->_Name << "\tConstructed(with copy)\t\t(DiamondTrap override)" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this == &src)
		return (*this);
	// this->_Name = src.getName(); // {name}_clap_name is ClapTrap's member function
	this->_Name = src._Name; // {name} copying DiamondTrap's member field
	std::cout << this->_Name << "\tAssigned\t\t\t(DiamondTrap override)" << std::endl;
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
	std::cout << "name (this->_Name)\t" << this->_Name << std::endl;					 // {name}
	std::cout << "name (this->ClapTrap::_Name)\t" << this->ClapTrap::_Name << std::endl; // {name}_clap_name
	// std::cout << "name (this->getName())\t" << this->getName() << std::endl;			 // {name}_clap_name
	std::cout << "Hit points:\t" << this->getHit_points() << std::endl;
	std::cout << "Energy points:\t" << this->getEnergy_points() << std::endl;
	std::cout << "Attack damage:\t" << this->getAttack_damage() << std::endl;
}
