#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &src);			  // copy constructor
	WrongCat &operator=(const WrongCat &src); // copy assignment operator
	~WrongCat(void);						  // diff

	void makeSound() const;

private:
};
#endif
