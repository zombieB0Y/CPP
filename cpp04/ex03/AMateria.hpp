#pragma once

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(const AMateria &copy);
	AMateria &operator=(const AMateria &copy);
	~AMateria();

	AMateria(const std::string &type);
	virtual AMateria* clone() const = 0;
	virtual void	use(ICharacter &target);
};
