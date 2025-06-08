#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog\tconstructed🔥" << std::endl;
	return;
}

Dog::Dog(const Dog &src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Dog\tCopy constructed🔥" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		Animal::operator=(src); // "this = src" will call Animal's copy assignment operator
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	std::cout << "Dog\tCopy assigned🔥" << std::endl;
	return *(this);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog\tDestructed💥" << std::endl;
	return;
}

void Dog::makeSound() const
{
	std::cout << "Bow-wow🐕" << std::endl;
	return;
}

void Dog::setIdea(size_t index, const std::string &idea)
{
	this->_brain->setIdeaInIndex(index, idea);
}

const std::string &Dog::getIdea(size_t index) const
{
	return this->_brain->getIdeaInIndex(index);
}
