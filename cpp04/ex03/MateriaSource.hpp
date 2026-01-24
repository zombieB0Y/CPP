#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*book[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource	&operator=(const MateriaSource &copy);
	~MateriaSource();


	void learnMateria(AMateria *m);
	AMateria *createMateria(const std::string &type);
};

