#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void)
{
	return;
}

Weapon::~Weapon(void)
{
	// std::cout << this->type << "\tDestructed💥" << std::endl;
	return;
}

Weapon::Weapon(const std::string &type) : type(type)
{
	return;
}

const std::string &Weapon::getType(void) const
{
	return type;
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}
