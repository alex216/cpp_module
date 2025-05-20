#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() // : ClapTrap() is not necessary
{
	this->_Name = "Default";
	this->_Hit_points = 100;
	this->_Energy_points = 50;
	this->_Attack_damage = 20;
	ScavTrap::HEALTH_PTS = 100; // actually it is ClapTrap's member variable

	std::cout << this->_Name << "\tConstructed\t\t\t(ScavTrap override)" << std::endl;
	return;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) // override
{
	this->_Name = name;
	this->_Hit_points = 100;
	this->_Energy_points = 50;
	this->_Attack_damage = 20;
	ScavTrap::HEALTH_PTS = 100; // actually it is ClapTrap's member variable

	std::cout << this->_Name << "\tConstructed\t\t\t(ScavTrap override)" << std::endl;
	return;
}

// Derived class's copy constructor must explicitly call base class's copy constructor at initialization list
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) // ClapTrap(src) is necessary
{
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this == &src)
		return (*this);
	this->_Name = src.getName();
	this->_Hit_points = src.getHit_points();
	this->_Energy_points = src.getEnergy_points();
	this->_Attack_damage = src.getAttack_damage();
	return *(this);
}

ScavTrap::~ScavTrap(void) // override
{
	std::cout << this->_Name << "\tDestructed💥\t\t\t(ScavTrap override)" << std::endl;
	return;
}

void ScavTrap::attack(const std::string &target) // override
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
