#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_ITEMS; ++i)
		_materia[i] = NULL;
	std::cerr << "MateriaSource\tdefault constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (other._materia[i])
			_materia[i] = other._materia[i]->clone();
		else
			_materia[i] = NULL;
	}
	std::cerr << "MateriaSource\tcopy constructor" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAX_ITEMS; ++i)
		{
			delete _materia[i];
			if (other._materia[i])
				_materia[i] = other._materia[i]->clone();
			else
				_materia[i] = NULL;
		}
	}
	std::cerr << "MateriaSource\tassignment operator" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_ITEMS; ++i)
		delete _materia[i];
	std::cerr << "MateriaSource\tdestructor" << std::endl;
}

// member functions
void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = m;
			return;
		}
	}
	std::cerr << "error: materia source is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (_materia[i] && _materia[i]->getType() == type)
		{
			return _materia[i]->clone();
		}
	}
	std::cerr << "error: materia of type '" << type << "' not found" << std::endl;
	return NULL;
}
