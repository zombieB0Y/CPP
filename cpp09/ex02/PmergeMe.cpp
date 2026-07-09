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
	for (size_t i = 2 * C; i + (2 * C) <= v.size(); i += 2 * C) {
		_main.insert(_main.end(), v.begin() + i + C, v.begin() + i + (2 * C)); // trying to insert all the a chunks 
		_pend.insert(_pend.end(), v.begin() + i, v.begin() + i + C);
	}
	if (_pend.empty()) return ;
	
	// ------------- now pen and main is loaded, start inserting ---------
	bool	isLeft = false;
	int left_O = 0;
	if (recuLevel == 0 && v.size() % 2 != 0) {
		isLeft = true;
		left_O = v.back();
	}
	std::vector<size_t> jbc = _generateJacob(_pend.size() / C); // based on chunk count
	size_t totalSize_P = _pend.size() / C;
	size_t inserted_count = 0; // the shifting in _main
	size_t i = 1;
	
	while (i < jbc.size()) {
		size_t O_jNum = jbc[i - 1];
		size_t C_jNum = jbc[i];
		size_t safeJNum = std::min(C_jNum, totalSize_P + 1);
		
		for (int k = safeJNum; k > O_jNum; --k) {
			int pend_idx = k - 2;
			std::vector<int>::iterator start = _pend.begin() + (pend_idx * C);
			std::vector<int>::iterator end = _pend.begin() + ((pend_idx + 1) * C);
			
			int b_val = *(end - 1);
			
			int low_chunk = 0;
			int high_chunk = k + inserted_count;
			
			while (low_chunk < high_chunk) {
				int mid_chunk = low_chunk + (high_chunk - low_chunk) / 2;
				int a_val = *(_main.begin() + ((mid_chunk + 1) * C) - 1);
				
				if (a_val < b_val) {
					low_chunk = mid_chunk + 1;
				} else {
					high_chunk = mid_chunk;
				}
			}
			_main.insert(_main.begin() + (low_chunk * C), start, end);
			++inserted_count;
		}
		++i;
	}
	if (!_pend.empty()) {
		std::cerr << "Error\n";
		return;
	}
	if (isLeft) {
		std::vector<int>::iterator it = std::lower_bound(_main.begin(), _main.end(), left_O);
		if (it == _main.begin())
			_main.insert(_main.begin(), _main.begin(), left_O);
	}
	for (size_t i = 0; i < _main.size(); ++i) {
		this->v[i] = _main[i];
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

