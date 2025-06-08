#include "Ice.hpp"

#define ORANGE "\033[38;5;214m"
#define RESET "\033[0m"

Ice::Ice() : AMateria("ice")
{
	std::cerr << "Ice\tdefault constructor" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cerr << "Ice\tcopy constructor" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cerr << "Ice\tcopy assignment operator" << std::endl;
	if (this == &other)
		return *this;
	// AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	std::cerr << "Ice\tdestructor" << std::endl;
}

// member functions
AMateria *Ice::clone() const
{
	std::cerr << ORANGE "Ice\tclone" << RESET << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cerr << ORANGE "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
