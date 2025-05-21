#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &src);			// copy constructor
	Cat &operator=(const Cat &src); // copy assignment operator
	~Cat(void);

	void makeSound() const;

private:
};
#endif
