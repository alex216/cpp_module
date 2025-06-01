#include <iostream>

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat\tconstructed🔥" << std::endl;
	return;
}

Cat::Cat(const Cat &src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Cat\tCopy constructed🔥" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
		Animal::operator=(src);
	}
	std::cout << "Cat\tCopy assigned🔥" << std::endl;
	return *(this);
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat\tDestructed💥" << std::endl;
	return;
}

void Cat::makeSound() const
{
	std::cout << "Meow~~~🐱" << std::endl;
	return;
}

void Cat::setIdea(size_t index, const std::string &idea)
{
	this->_brain->setIdeaInIndex(index, idea);
}

const std::string &Cat::getIdea(size_t index) const
{
	return this->_brain->getIdeaInIndex(index);
}
