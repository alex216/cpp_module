#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
public:
	~HumanA(void);

	HumanA(const std::string &name, Weapon &weapon);

	void attack();

private:
	std::string name;

	// Human has reference of weapon, for subject requirement.
	Weapon &weapon;
};
#endif
