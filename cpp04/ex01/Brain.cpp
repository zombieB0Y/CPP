#include "Brain.hpp"

Brain::Brain() {
	print_msg("Brain constructor called !");
}

Brain::Brain(const Brain &copy) {
	print_msg("Brain copy constructor called !");
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy) {
	print_msg("Brain operator called !");
	if (this != &copy) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = copy.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	print_msg("brain destructor called !");
}