#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		book[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	*this = copy;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy) {
	if (this != &copy) {
		for (int i = 0; i < 4; i++) {
			delete this->book[i];
			if (copy.book[i])
				this->book[i] = copy.book[i]->clone();
			else
				this->book[i] = 0;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete this->book[i];
}

void	MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {
		if (this->book[i] == 0) {
			this->book[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria	*MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; i++) {
		if (this->book[i]) {
			if (this->book[i]->getType() == type)
				return (this->book[i]->clone());
		}
	}
	return 0;
}