#pragma once

#include <iostream>

class base {
	public:
		virtual void	print() {
			std::cout << "ana  base\n";
		}
		base(){};
		virtual ~base(){};
};

class child : public base {
	public:
		void	print() {
			std::cout << "ana child\n";
		}
};

class child2 : public base {
	public:
		void	print() {
			std::cout << "ana child 2\n";
		}
};