#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat\tconstructed🔥" << std::endl;
	return;
}

Cat::Cat(const Cat &src) : Animal(src)
{
}

Cat &Cat::operator=(const Cat &src)
{
	Animal::operator=(src);
	return *(this);
}

Cat::~Cat(void)
{
	std::cout << "Cat\tDestructed💥" << std::endl;
	return;
}

void Cat::makeSound() const
{
	std::cout << "Meow~~~🐱" << std::endl;
	return;
}
