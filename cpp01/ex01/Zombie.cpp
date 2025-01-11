#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
	return;
}

Zombie::Zombie(const std::string &name) : name(name)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << ":\tDestructed💥" << std::endl;
	return;
}

void Zombie::announce(void)
{
	std::cout << this->name << ":\tBraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name)
{
	this->name = name;
}
