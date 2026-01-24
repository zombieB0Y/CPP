#include "Character.hpp"

// ********************************************************************************

Character::Character() {
	for (int i = 0; i < 4; i++) {
		slots[i] = 0;
	}
	this->gc_head = 0;
}

Character::Character(const Character &copy) : name(copy.name)
{
    for (int i = 0; i < 4; i++) {
        this->slots[i] = 0;
    }
    this->gc_head = 0;
    *this = copy;
}

Character	&Character::operator=(const Character &copy) {
	if (this != &copy) {
		for (int i = 0; i < 4; i++) {
			this->gc_remove_ptr(this->slots[i]);
			delete this->slots[i];
			if (copy.slots[i] != 0)
				this->slots[i] = copy.slots[i]->clone();
			else
				this->slots[i] = 0;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete this->slots[i];
		this->slots[i] = 0;
	}
	this->gc_collect();
}

// ********************************************************************************


const std::string	&Character::getName() const {
	return this->name;
}

void	Character::gc_register(AMateria *data) {
    if (!data) {
        return;
	}
	
	// t_gb *current = this->gc_head;
	// while (current) {
	// 	if (current->data == data)
	// 		return ;
	// 	current = current->next;
	// }
    t_gb *node = new t_gb;
    node->data = data;
    node->next = this->gc_head;
	this->gc_head = node;
}

void	Character::gc_collect(void) {
    t_gb *current = this->gc_head;
    while (current) {
        t_gb *next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
    this->gc_head = 0;
}

void	Character::gc_remove_ptr(AMateria *data)
{
	if (!data || !this->gc_head)
		return ;
	t_gb *curr = this->gc_head;
	t_gb *prev = 0;

	while (curr != 0)
	{
		if (curr->data == data)
		{
			if (prev != 0)
				prev->next = curr->next;
			else
				this->gc_head = curr->next;

			curr->next = 0;
			delete curr;
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

Character::Character(const std::string _name) : name(_name) {
	for (int i = 0; i < 4; i++) {
		slots[i] = 0;
	}
	this->gc_head = 0;
}

void	Character::equip(AMateria *m) {
	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] == m) {
			std::cout << "alredy Equiped !" << std::endl;
			return ;
		}
	}	
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] == 0) {
			this->gc_remove_ptr(m);
			this->slots[i] = m;
			return ;
		}
	}
	std::cout << "cant equip all slots all are full !" << std::endl;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	if (this->slots[idx] != 0) {
		this->gc_register(this->slots[idx]);
		this->slots[idx] = 0;
	}
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3 || !this->slots[idx])
		return ;
	this->slots[idx]->use(target);
}