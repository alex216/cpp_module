#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() // : ClapTrap() is not necessary
{
	std::cout << this->_Name << "\tConstructed\t\t\t(FragTrap override)" << std::endl;
	this->_Name = "Default";
	this->_Hit_points = 100;
	this->_Energy_points = 100;
	this->_Attack_damage = 30;
	FragTrap::HEALTH_PTS = 100; // actually it is ClapTrap's member variable
	return;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) // override
{
	std::cout << this->_Name << "\tConstructed\t\t\t(FragTrap override)" << std::endl;
	this->_Name = name;
	this->_Hit_points = 100;
	this->_Energy_points = 100;
	this->_Attack_damage = 30;
	FragTrap::HEALTH_PTS = 100; // actually it is ClapTrap's member variable
	return;
}

// Derived class's copy constructor must explicitly call base class's copy constructor at initialization list
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) // ClapTrap(src) is necessary
{
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this == &src)
		return *(this);
	this->_Name = src.getName();
	this->_Hit_points = src.getHit_points();
	this->_Energy_points = src.getEnergy_points();
	this->_Attack_damage = src.getAttack_damage();
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
