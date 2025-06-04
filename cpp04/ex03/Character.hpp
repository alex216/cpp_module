#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	static const int MAX_ITEMS = 4;
	std::string _name;
	AMateria *_inventory[MAX_ITEMS];

public:
	Character();
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character();

	// parameterized constructor
	Character(const std::string &name);

	// setter,getter
	std::string const &getName() const;

	// member functions
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif // CHARACTER_HPP
