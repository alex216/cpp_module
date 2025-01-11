#include "HumanA.hpp"
#include <iostream>

HumanA::~HumanA(void)
{
	std::cout << this->name << "\tDestructed💥" << std::endl;
	return;
}

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon)
{
	return;
}

void HumanA::attack()
{
	std::cout << this->name << "\tattacks with their " << this->weapon.getType() << std::endl;
}
