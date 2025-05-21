#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal\tconstructed🔥" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	this->_type = src._type;
	return *(this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal\tDestructed💥" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal\tconstructed with type🔥" << std::endl;
	return;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
	return;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}
