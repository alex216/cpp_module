#include <iostream>

#include "Animal.hpp"

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ORANGE "\033[38;5;214m"
#define RESET "\033[0m"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q ex01 > /dev/null 2> /dev/null"))
		system("leaks -q ex01");
}
#endif

static void copyTest()
{
	Dog src_dog;
	src_dog.setIdea(0, "old_idea");
	{
		Dog dst_dog = src_dog;
		dst_dog.setIdea(0, "new_idea");

		std::cout << ORANGE "dst_dog's idea[0]: " << dst_dog.getIdea(0) << RESET << std::endl;
	}
	// dog's brain must not be deleted
	// dog's brain must not be overwritten
	std::cout << ORANGE "src_dog's idea[0]: " << src_dog.getIdea(0) << RESET << std::endl;
}

// appropriate destructors must be called in expected order
static void AnimalArrayTest()
{
	const size_t animalCount = 2;
	Animal *animals[animalCount];
	for (size_t i = 0; i < animalCount / 2; i++)
		animals[i] = new Dog();
	for (size_t i = animalCount / 2; i < animalCount; i++)
		animals[i] = new Cat();

	for (size_t i = 0; i < animalCount; i++)
		delete animals[i];
}

// Brain must be copied deeply
static void DeepCopyTest()
{
	Dog src;
	src.setIdea(0, "good-idea");

	std::cout << ORANGE "src idea[0]: " << src.getIdea(0) << " addr: " << &src.getIdea(0) << RESET << std::endl;

	Dog dst = src;

	std::cout << ORANGE "dst idea[0]: " << dst.getIdea(0) << " addr: " << &dst.getIdea(0) << RESET << std::endl;
}

int main()
{
	std::cout << "[Copy test]" << std::endl;
	copyTest();

	std::cout << std::endl
			  << "[Animal array test]" << std::endl;
	AnimalArrayTest();

	std::cout << std::endl
			  << "[Deep copy test]" << std::endl;
	DeepCopyTest();
}
