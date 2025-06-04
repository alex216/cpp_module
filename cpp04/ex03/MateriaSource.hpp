#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const int MAX_ITEMS = 4;
	AMateria *_materia[MAX_ITEMS];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();

	// member functions
	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

#endif // MATERIASOURCE_HPP
