#include <iostream>
#include <memory>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q claptrap > /dev/null 2> /dev/null"))
		system("leaks -q claptrap");
}
#endif

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

#define RED_CROSS RED "✗" RESET
#define GREEN_CHECK GREEN "✓" RESET

int main()
{
	std::cout << BLUE "ScavTrap is derived from ClapTrap." RESET << std::endl;
	{
		std::cout << GREEN "[default constructor] won't cause problem whether there is virtual keyword at base class destructor." RESET << std::endl;
		ScavTrap Bob("Bob");
	}

	std::cout << std::endl;
	{
		std::cout << GREEN "[new] delete derived class instance using derived class pointer" RESET << std::endl;
		ScavTrap *Charlie = new ScavTrap();
		delete Charlie;
	}

	std::cout << std::endl;
	{
		std::cout << GREEN "[new] delete derived class instance using base class pointer (upcasting)" RESET << std::endl;
		ScavTrap *Charlie = new ScavTrap();
		delete (ClapTrap *)Charlie; // upcasting then delete
	}

	std::cout << std::endl;
	{
		std::cout << GREEN "[new] delete derived class instance using base class pointer (upcasting) with auto_ptr" RESET << std::endl;

		// auto_ptr will automatically delete the object when it goes out of scope
		std::auto_ptr<ScavTrap> Charlie(new ScavTrap());
	}

	std::cout << std::endl
			  << BLUE "[conclusion] " << std::endl

#ifdef DEBUG
			  << BLUE "[ ] when there is virtual keyword at base class destructor....." RESET << std::endl
#else
			  << BLUE "[" << YELLOW "o" << BLUE "] when there is virtual keyword at base class destructor....." RESET << std::endl
#endif
			  << std::endl
			  << BLUE "default constructor -> [" << GREEN_CHECK << BLUE "]" << std::endl
			  << BLUE "new && delete derived class -> [" << GREEN_CHECK << BLUE "]" << std::endl
			  << BLUE "new && upcasting then delete derived class -> [" << GREEN_CHECK << BLUE "]" << std::endl
			  << BLUE "new && upcasting then delete derived class using auto_ptr->[" << GREEN_CHECK << BLUE "]" RESET << std::endl
			  << std::endl
#ifdef DEBUG
			  << BLUE "[" << YELLOW "o" << BLUE "] when there is " << YELLOW "no" << BLUE " virtual keyword at base class destructor....." RESET << std::endl
#else
			  << BLUE "[ ] when there is " << YELLOW "no" << BLUE " virtual keyword at base class destructor....." RESET << std::endl
#endif
			  << std::endl
			  << BLUE "default constructor -> [" << GREEN_CHECK << BLUE "]" << std::endl
			  << BLUE "new && delete derived class -> [" << GREEN_CHECK << BLUE "]" << std::endl
			  << BLUE "new && upcasting then delete derived class -> [" << RED_CROSS << BLUE "]" << std::endl
			  << BLUE "new && upcasting then delete derived class using auto_ptr->[" << GREEN_CHECK << BLUE "]" RESET << std::endl;
}
