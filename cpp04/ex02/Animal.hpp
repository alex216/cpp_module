#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "Brain.hpp"

class Animal
{
public:
	Animal(void);
	Animal(const Animal &src);			  // copy constructor
	Animal &operator=(const Animal &src); // copy assignment operator
	virtual ~Animal(void);

	Animal(std::string type);
	virtual void makeSound() const = 0;
	std::string getType() const;

private:
	std::string _type;
};
#endif
