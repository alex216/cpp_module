#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cerr << "Cure\tdefault constructor" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cerr << "Cure\tcopy constructor" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cerr << "Cure\tcopy assignment operator" << std::endl;
	if (this == &other)
		return *this;
	// AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
	std::cerr << "Cure\tdestructor" << std::endl;
}

// member functions
AMateria *Cure::clone() const
{
	std::cerr << "Cure\tclone" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cerr << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
