#include "Weapon.hpp"
#include "Human.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q a.out > /dev/null 2> /dev/null"))
		system("leaks -q a.out");
}
#endif

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

		// B's attack() should be checked because it's a pointer
		// if setWeapon is not called and no NULL guard is implemented,
		// it will cause a segmentation fault
		jim.setWeapon(club);

		jim.attack();
		club.setType("club2");
		jim.attack();
	}

	return 0;
}
