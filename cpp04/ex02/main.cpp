#include <iostream>

#include "Animal.hpp"

#include "Cat.hpp"
#include "Dog.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q ex02 > /dev/null 2> /dev/null"))
		system("leaks -q ex02");
}
#endif

int main()
{
	// error
	// error: invalid new-expression of abstract class type 'Animal'
	// Animal *animal = new Animal();

	// ok
	Dog *dog = new Dog();
	dog->makeSound();
	delete dog;
}
