#include "Weapon.hpp"
#include "Human.hpp"

__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q a.out > /dev/null 2> /dev/null"))
		system("leaks -q a.out");
}

// Human A using reference
// Human B using pointer
int main()
{
	{
		Weapon club = Weapon("club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("club2");
		bob.attack();
	}
	{
		Weapon club = Weapon("club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("club2");
		jim.attack();
	}

	return 0;
}
