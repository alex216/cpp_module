#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << this->_Name << "\tConstructed\t\t\t(ScavTrap override)" << std::endl;
	this->_Hit_points = ScavTrap::ScavTrap_HEALTH_PTS;
	this->_Energy_points = ScavTrap::ScavTrap_ENERGY_PTS;
	this->_Attack_damage = ScavTrap::ScavTrap_ATTACK_DMG;
	ScavTrap::HEALTH_PTS = ScavTrap::ScavTrap_HEALTH_PTS;
	return;
}

ScavTrap::ScavTrap(const std::string name)
{
	this->_Name = name;
	std::cout << this->_Name << "\tConstructed(with name)\t\t\t(ScavTrap override)" << std::endl;
	this->_Hit_points = ScavTrap::ScavTrap_HEALTH_PTS;
	this->_Energy_points = ScavTrap::ScavTrap_ENERGY_PTS;
	this->_Attack_damage = ScavTrap::ScavTrap_ATTACK_DMG;
	ScavTrap::HEALTH_PTS = ScavTrap::ScavTrap_HEALTH_PTS;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) // ClapTrap(src) is necessary
{
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this == &src)
		return (*this);
	this->_Name = src.getName();
	this->_Hit_points = ScavTrap::ScavTrap_HEALTH_PTS;
	this->_Energy_points = ScavTrap::ScavTrap_ENERGY_PTS;
	this->_Attack_damage = ScavTrap::ScavTrap_ATTACK_DMG;
	ScavTrap::HEALTH_PTS = ScavTrap::ScavTrap_HEALTH_PTS;
	return *(this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->_Name << "\tDestructed💥\t\t\t(ScavTrap override)" << std::endl;
	return;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getHit_points() == 0)
		return;
	unsigned int energy_pts = this->getEnergy_points();
	if (energy_pts == 0)
		return;
	this->setEnery_points(energy_pts - 1);

	std::cout << this->getName() << "\tattacks " << target << " with "
			  << this->getAttack_damage() << " damage\t(ScavTrap override)" << std::endl;
}

// own capability
void ScavTrap::guardGate()
{
	if (this->getHit_points() == 0)
		return;
	unsigned int energy_pts = this->getEnergy_points();
	if (energy_pts == 0)
		return;
	this->setEnery_points(energy_pts - 1);

	std::cout << this->getName() << "\tis in Gate keeper mode." << std::endl;
}
