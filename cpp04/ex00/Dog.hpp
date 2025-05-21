#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &src);			// copy constructor
	Dog &operator=(const Dog &src); // copy assignment operator
	virtual ~Dog(void);

	virtual void makeSound() const;

private:
};
#endif
