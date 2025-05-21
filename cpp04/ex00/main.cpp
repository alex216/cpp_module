#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q ex00 > /dev/null 2> /dev/null"))
		system("leaks -q ex00");
}
#endif

void testNormal()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "Dog.getType(): " << j->getType() << std::endl;
	std::cout << "Cat.getType(): " << i->getType() << std::endl;

	std::cout << "Dog.makeSound(): ";
	j->makeSound();

	std::cout << "Cat.makeSound(): ";
	i->makeSound();

	std::cout << "Animal.makeSound(): ";
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void testWrong()
{
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *i = new WrongCat();

	std::cout << "WrongCat.getType(): " << i->getType() << std::endl;

	std::cout << "WrongCat.makeSound(): ";
	i->makeSound(); // WrongCat's makeSound() is not called

	std::cout << "WrongAnimal.makeSound(): ";
	meta->makeSound();

	delete meta;
	delete i; // WrongCat's destructor is not called
}

int main()
{
	std::cout << "[Normal test]" << std::endl;
	testNormal();

	std::cout << std::endl;

	std::cout << "[Wrong test]" << std::endl;
	testWrong();
}
