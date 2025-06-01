#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &src);			// copy constructor
	WrongAnimal &operator=(const WrongAnimal &src); // copy assignment operator
	~WrongAnimal(void);								// diff

	WrongAnimal(std::string type);
	void makeSound() const; // diff
	std::string getType() const;

private:
	std::string _type;
};
#endif
