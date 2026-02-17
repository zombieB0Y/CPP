#include <iostream>
#include "class.hpp"


int	main() {
	base *base1 = new base();
	child	*child1 = new child();
	// child1->print();
	base1->print();
	base1 = dynamic_cast<base*>(child1);
	base1->print();
}