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
	virtual ~AMateria();

	const std::string &getType() const;
	AMateria(const std::string &_type);
	virtual AMateria* clone() const = 0;
	virtual void	use(ICharacter &target);
};
