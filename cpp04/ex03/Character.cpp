#include "Character.hpp"

#define ORANGE "\033[38;5;214m"
#define RESET "\033[0m"

Character::Character()
{
	std::cerr << "Character\tdefault constructor" << std::endl;
	for (int i = 0; i < MAX_ITEMS; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	std::cerr << "Character\tcopy constructor" << std::endl;
	_name = other._name;
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	std::cerr << "Character\tassignment operator" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < MAX_ITEMS; ++i)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	std::cerr << "Character\tdestructor" << std::endl;
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		delete _inventory[i];
	}
}

// parameterized constrcutor
Character::Character(const std::string &name) : _name(name)
{
	std::cerr << "Character\tparameterized constructor" << std::endl;
	for (int i = 0; i < MAX_ITEMS; ++i)
		_inventory[i] = NULL;
}

// setter,getter
std::string const &Character::getName() const
{
	return this->_name;
}

// member functions
void Character::equip(AMateria *m)
{
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cerr << ORANGE "Equipped " << m->getType() << " at index " << i << RESET << std::endl;
			return;
		}
	}
	std::cerr << ORANGE "Inventory is full, cannot equip " << m->getType() << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_ITEMS || _inventory[idx] == NULL)
	{
		std::cerr << ORANGE "Cannot unequip from index " << idx << RESET << std::endl;
		return;
	}
	std::cerr << ORANGE "Unequipped " << _inventory[idx]->getType() << " from index " << idx << RESET << std::endl;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= MAX_ITEMS || _inventory[idx] == NULL)
	{
		std::cerr << ORANGE "Cannot use from index " << idx << RESET << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
