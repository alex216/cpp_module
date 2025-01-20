#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(void) : name("unnamed"), weapon(NULL)
{
	return;
}

HumanB::~HumanB(void)
{
	std::cout << this->name << "\tDestructed💥" << std::endl;
	return;
}

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL)
{
	return;
}

HumanB::HumanB(const std::string &name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
	return;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if (this->weapon == NULL)
	{
		std::cout << this->name << "\thas no weapon" << std::endl;
		return;
	}
	std::cout << this->name << "\tattacks with their " << this->weapon->getType() << std::endl;
}
