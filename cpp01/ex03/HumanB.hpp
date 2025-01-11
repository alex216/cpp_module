#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(void);
	~HumanB(void);

	HumanB(const std::string &name);
	HumanB(const std::string &name, Weapon &weapon);

	void setWeapon(Weapon &weapon);

	void attack();

private:
	std::string name;

	Weapon *weapon;
};
#endif
