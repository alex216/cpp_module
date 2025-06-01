#include <iostream>

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat\tconstructed🔥" << std::endl;
	return;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	WrongAnimal::operator=(src);
	return *(this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat\tDestructed💥" << std::endl;
	return;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow~~~🐱" << std::endl;
	return;
}
