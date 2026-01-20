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
		Brain *_new = new Brain;
		for (int i = 0; i < 100; i++) {
			_new->ideas[i] = copy.ideas[i];
		}
		return *_new;
	}
	return *this;
}

Brain::~Brain() {
	print_msg("brain destructor called !");
}