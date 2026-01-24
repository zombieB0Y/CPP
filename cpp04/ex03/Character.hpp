#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "gb.h"
#include <iostream>

class Character : public ICharacter
{
private:
	const std::string	name;
	AMateria			*slots[4];
	t_gb				*gc_head;
public:
	Character();
	Character(const Character &copy);
	Character	&operator=(const Character &copy);
	~Character();

	Character(const std::string _name);
	const std::string	&getName() const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);
	void				gc_register(AMateria *data);
	void				gc_collect(void);
	void				gc_remove_ptr(AMateria *data);
};

///////////  waaaaaa 3art lah ma delitich dik AMateria hem bak