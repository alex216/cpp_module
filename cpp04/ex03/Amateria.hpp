#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria();
	AMateria(const AMateria &);
	AMateria &operator=(const AMateria &);
	virtual ~AMateria();

	std::string const &getType() const;

	AMateria(std::string const &type);
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif // AMATERIA_HPP
