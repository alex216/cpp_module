#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain\tConstructed🧠" << std::endl;
	return;
}

Brain::Brain(const Brain &src)
{
	for (size_t i = 0; i < Brain::MAX_IDEAS; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain\tCopy constructed🧠" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	for (size_t i = 0; i < Brain::MAX_IDEAS; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain\tCopy assigned🧠" << std::endl;
	return *(this);
}

Brain::~Brain(void)
{
	std::cout << "Brain\tDestructed💥" << std::endl;
	return;
}

void Brain::setIdeaInIndex(size_t index, const std::string ideas)
{
	if (index >= Brain::MAX_IDEAS)
	{
		throw std::out_of_range("Index out of range");
	}
	this->_ideas[index] = ideas;
	return;
}

const std::string &Brain::getIdeaInIndex(size_t index) const
{
	if (index >= Brain::MAX_IDEAS)
	{
		throw std::out_of_range("Index out of range");
	}
	return this->_ideas[index];
}
