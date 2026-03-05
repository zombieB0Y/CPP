#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base	*generate(void) {
	std::ifstream urandom("/dev/urandom");
	if (urandom.is_open()) {
        char ch = 0;
		urandom.read(&ch, 1);
        urandom.close();
		int mod = ch % 3;
		if (mod == 0)
			return new A;
		else if (mod == 1)
			return new B;
		return new C;
	}
	else {
		std::cerr << "opening file error !" << std::endl;
		return 0;
	}
}

void	identify(Base* p) {
	if (!p) {
		std::cout << "NULL" << std::endl;
		return;
	}
	A	*a = dynamic_cast<A*>(p);
	if (a) {
		std::cout << "Type : A" << std::endl;
		return;
	}
	B	*b = dynamic_cast<B*>(p);
	if (b) {
		std::cout << "Type : B" << std::endl;
		return;
	}
	C	*c = dynamic_cast<C*>(p);
	if (c) {
		std::cout << "Type : C" << std::endl;
		return;
	}
}

void	identify(Base& p) {
	try {
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type : A" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	
	try {
		B	&a = dynamic_cast<B&>(p);
		(void)a;
		std::cout << "Type : B" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	
	try {
		C	&a = dynamic_cast<C&>(p);
		(void)a;
		std::cout << "Type : C" << std::endl;
		return;
	}
	catch (std::exception &e) {}

}