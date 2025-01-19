#include "Zombie.hpp"
#include "extraZombie.hpp"

// low address
// heap
// |
// v
//
// ^
// |
// stack
// high address

// __attribute__((destructor)) void end()
// {
// 	system("leaks Zombie");
// }

int main()
{
	// first
	Zombie a = Zombie("alice(stack)");
	std::cout << "alice address:\t" << &a << std::endl;
	a.announce();
	std::cout << std::endl;

	// second
	Zombie *b = newZombie("bob(heap)");
	std::cout << "bob address:\t" << b << std::endl;
	b->announce();
	delete b; // destruction code needed
	std::cout << std::endl;

	// third
	// since randomChump is a function to create a Zombie,
	// it is better to use newZombie inside the function to create a Zombie.
	randomChump("Charlie(stack)");

	// it is easier to use newZombie to create a Zombie.
	// randomChump("Charli1(stack)");
	// randomChump("Charli2(stack)");
	// randomChump("Charli3(stack)");
}
