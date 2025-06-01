#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	~Dog(void);

	void makeSound() const;
	void setIdea(size_t index, const std::string &idea);
	const std::string &getIdea(size_t index) const;

private:
	Brain *_brain;
};
#endif
