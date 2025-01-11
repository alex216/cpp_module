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
	randomChump("Charlie(stack)");
}
