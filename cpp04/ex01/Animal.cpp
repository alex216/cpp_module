#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal\tconstructed🔥" << std::endl;
	return;
}

Animal::Animal(const Animal &src) : _type(src._type)
{
	std::cout << "Animal\tCopy constructed🔥" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal\tCopy assigned🔥" << std::endl;
	this->_type = src._type;
	return *(this);
}

Animal::~Animal(void)
{
	std::cout << "Animal\tDestructed💥" << std::endl;
	return;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal\tconstructed with type🔥" << std::endl;
	return;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
	return;
}

std::string Animal::getType() const
{
	return this->_type;
}
