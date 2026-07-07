#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) {*this = other;}
PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->v = other.v; // noo deep copy
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(std::string input) {
	_LoadVector(input); // input need to be pased before sending here
}

void	PmergeMe::_LoadVector(std::string input) {
	std::istringstream	line(input);
	std::string			token;
	while (std::getline(line, token, ' ')) {
		this->v.push_back(std::atoi(token.c_str()));
	}
}

void	PmergeMe::_sortVector(int recuLevel) {
	// if (this->v.size() / _powerOf2(this->recuLevel) < 2) // if only one element
	
	if (recuLevel == 1) {_sortPairs();}
	else if (v.size() / _powerOf2(recuLevel) >= 2) {
		std::vector<int>* pairs = new std::vector<int>[this->v.size() / _powerOf2(recuLevel)];
		_loadPairs(pairs);
	}
	std::vector<int> dV = this->v;
	// ++this->recuLevel;
}

void	PmergeMe::_loadPairs(std::vector<int>* pairs) {
	for (int i = 0; i < v.size())
}

void	PmergeMe::_sortPairs() {
	for (int i = 0; i <= this->v.size() / 2; ++i) { // i guess its safe now !!
		if (this->v.size() >= ((i * 2) - 1)) {
			if (this->v.at((i * 2) - 1) < this->v.at((i * 2) - 2))
				_swap((i * 2) - 1, (i * 2) - 2);
		}
	}
}

void	PmergeMe::_swap(int a, int b) {
	int tmp = v.at(a);
	v.at(a) = v.at(b);
	v.at(b) = tmp;
}

size_t	_powerOf2(int n) {return 1 << n;}