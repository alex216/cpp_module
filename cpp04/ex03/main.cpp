#include <cassert>

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	std::cerr << "------------------" << std::endl;
	{
		Ice ice;
		Cure cure;
	}

	std::cerr << "------------------" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		(void)src;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	std::cerr << "------------------" << std::endl;
	{
		Character ch("alice");
		Ice *m1 = new Ice();
		Ice *m2 = new Ice();
		Cure *m3 = new Cure();
		Cure *m4 = new Cure();
		Ice *m5 = new Ice();

		ch.equip(m1);
		ch.equip(m2);
		ch.equip(m3);
		ch.equip(m4);
		// fails
		ch.equip(m5);
		delete m5;

		ch.unequip(1);
		delete m2;

		ICharacter *me = new Character("me");
		ch.use(1, *me);
		ch.use(2, *me);
		ch.use(3, *me);
		ch.use(4, *me);

		delete me;
	}

	std::cerr << "------------------" << std::endl;
	{
		Ice ice;
		Cure cure;
		AMateria *ice_clone = ice.clone();
		AMateria *cure_clone = cure.clone();

		assert(ice_clone != NULL);
		assert(cure_clone != NULL);
		assert(ice_clone->getType() == "ice");
		assert(cure_clone->getType() == "cure");

		delete ice_clone;
		delete cure_clone;
	}
	return 0;
}
