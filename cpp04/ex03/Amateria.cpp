#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cerr << "AMateria\tdefault constructor" << std::endl;
}

AMateria::~AMateria()
{
	std::cerr << "AMateria\tdefault destructor" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	std::cerr << "AMateria\tcopy constructor" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cerr << "AMateria\tcopy assignment operator" << std::endl;
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

// parametarized constructor
AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cerr << "AMateria\tparameterized constructor" << std::endl;
}

// setter, getter
std::string const &AMateria::getType() const
{
	return this->_type;
}

// member functions
void AMateria::use(ICharacter &target)
{
	std::cerr << "AMateria\tuse: " << this->getType() << " on " << target.getName() << std::endl;
}
