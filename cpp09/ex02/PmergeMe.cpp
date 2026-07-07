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
	_sortVector(0);
}

void	PmergeMe::_LoadVector(std::string input) {
	std::istringstream	line(input);
	std::string			token;
	while (std::getline(line, token, ' ')) {
		this->v.push_back(std::atoi(token.c_str()));
	}
}

void	PmergeMe::_sortVector(int recuLevel) { // recul Level need to start with 0 for _sortPair to work
	int C = _powerOf2(recuLevel);
	if (this->v.size() / C < 2) return ;
	_sortPairs(recuLevel);
	_sortVector(recuLevel + 1);
	std::vector<int> _pend;
	std::vector<int> _main;
	_main.insert(_main.end(), v.begin(), v.begin() + (2 * C));
	for (size_t i = 2 * C; i + (2 * C) <= v.size(); i+= 2 * C) {
		_main.insert(_main.end(), v.begin() + i + C, v.begin() + i + (2 * C)); // trying to insert all the a chunks 
		_pend.insert(_pend.end(), v.begin() + i, v.begin() + i + C);
	}
	if (v.size() % (2 * C) != 0) {
		int	leftOver = v.size() / (2 * C); // (size / two_paires) * two_pairs
		leftOver *= (2 * C);
		_pend.insert(_pend.end(), v.begin() + leftOver, v.end());
	}
	// std::vector<int> dV = this->v;
	// ++this->recuLevel;
}

void	PmergeMe::_sortPairs(int reculLevel) {
	int C = _powerOf2(reculLevel);
	for (size_t i = 0; i + (2 * C) <= v.size(); i+= 2 * C) {
		std::vector<int>::iterator startB = v.begin() + i;
		std::vector<int>::iterator startA = v.begin() + i + C;

		int	b = *(startB + C - 1);
		int	a = *(startA + C - 1);

		if (a < b) _swap(startA, startB, C);
	}
}

void	PmergeMe::_swap(std::vector<int>::iterator startA, std::vector<int>::iterator startB, int C) {
	std::swap_ranges(startA, startA + C, startB);
}

size_t	_powerOf2(int n) {return 1 << n;}