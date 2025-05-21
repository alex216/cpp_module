#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog\tconstructed🔥" << std::endl;
	return;
}

Dog::Dog(const Dog &src) : Animal(src)
{
}

Dog &Dog::operator=(const Dog &src)
{
	Animal::operator=(src);
	return *(this);
}

Dog::~Dog(void)
{
	std::cout << "Dog\tDestructed💥" << std::endl;
	return;
}

void Dog::makeSound() const
{
	std::cout << "Bow-wow🐕" << std::endl;
	return;
}
