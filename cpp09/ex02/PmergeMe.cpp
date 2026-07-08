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
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v.at(i) << " ";
	}
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
	// ------------- now pen and main is loaded, start inserting ---------

	// int total_b_elements = _pend.size() / C;
	// int start_K = std::min(curr_jacob, total_b_elements + 1);
	// for (int K = start_K; K > prev_jacob; --K) {
	// 	int pend_idx = K - 2;
	// 	std::vector<int>::iterator b_start = _pend.begin() + (pend_idx * C);
	// 	std::vector<int>::iterator b_end   = _pend.begin() + ((pend_idx + 1) * C);
	// 	int b_value = *(b_end - 1);
	// }

	std::vector<size_t>	jbc = _generateJacob(_pend.size());
	while (!_pend.empty()) {

	}
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

size_t	_powerOf2(size_t n) {return 1 << n;}

std::vector<size_t> _generateJacob(size_t size) {
	std::vector<size_t> jacob;
	jacob.push_back(1);
	if (size == 1) return jacob;
	jacob.push_back(3);
	while (jacob.back() < size) {
		size_t last_idx = jacob.size() - 1;
		size_t next = jacob[last_idx] + 2 * jacob[last_idx - 1];
		jacob.push_back(next);
	}
	
	return jacob;
}

// size_t	_generateJacob(int n) {
// 	if (n == 0) return 0;
// 	if (n == 1) return 1;
// 	return (_generateJacob(n - 1) + (2 * _generateJacob(n - 2)));
// }

