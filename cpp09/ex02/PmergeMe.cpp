#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : count(0) {}
PmergeMe::PmergeMe(const PmergeMe &other) : count(0) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->v = other.v;
		count = other.count; // noo deep copy
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(std::string input) : count(0)
{
	_LoadVector(input); // input need to be pased before sending here
	_sortVector(0);
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v.at(i) << " ";
		if (i + 1 == v.size())	std::cout << "\n";
	}
	std::cout << count << "\n";
	std::cout << F(v.size()) << "\n";
}

void PmergeMe::_LoadVector(std::string input)
{
	std::istringstream line(input);
	std::string token;
	while (std::getline(line, token, ' '))
	{
		this->v.push_back(std::atoi(token.c_str()));
	}
}

void PmergeMe::_sortVector(int recuLevel)
{
	int C = _powerOf2(recuLevel);
	if (this->v.size() / C < 2)
		return;
	_sortPairs(recuLevel);
	_sortVector(recuLevel + 1);
	std::vector<int> _pend;
	std::vector<int> _main;
	_main.insert(_main.end(), v.begin(), v.begin() + (2 * C));
	for (size_t i = 2 * C; i + (2 * C) <= v.size(); i += 2 * C)
	{
		_main.insert(_main.end(), v.begin() + i + C, v.begin() + i + (2 * C));
		_pend.insert(_pend.end(), v.begin() + i, v.begin() + i + C);
	}
	if ((v.size() / C) % 2 != 0)
	{
		size_t leftover_start = (v.size() / (2 * C)) * (2 * C);
		_pend.insert(_pend.end(), v.begin() + leftover_start, v.begin() + leftover_start + C);
	}

	std::vector<size_t> jbc = _generateJacob(_pend.size() / C);
	size_t totalSize_P = _pend.size() / C;
	size_t inserted_count = 0;
	size_t i = 1;

	while (i < jbc.size())
	{
		size_t O_jNum = jbc[i - 1];
		size_t C_jNum = jbc[i];
		size_t safeJNum = std::min(C_jNum, totalSize_P + 1);

		for (size_t k = safeJNum; k > O_jNum; --k) // 3
		{
			int pend_idx = k - 2;
			std::vector<int>::iterator start = _pend.begin() + (pend_idx * C);
			std::vector<int>::iterator end = _pend.begin() + ((pend_idx + 1) * C);

			int b_val = *(end - 1); // 10 b4
			int low_chunk = 0;
			int high_chunk = k + inserted_count; // 7
			while (low_chunk < high_chunk) // 1th: 0 < 7 -- 2th: 0 < 3 -- 3th: 2<3 
			{
				int mid_chunk = low_chunk + (high_chunk - low_chunk) / 2; // 1th: 3 -- 2th: 1 -- 3th: 2
				int a_val = *(_main.begin() + ((mid_chunk + 1) * C) - 1); // 1th: 13 a1 -- 2th: 8 b1 -- 3th: 11 b3
				++this->count;
				if (a_val <= b_val) // 1th:13<10--2th:8<10--3th:11<10
				{
					low_chunk = mid_chunk + 1; // 1th: 2
				}
				else
				{
					high_chunk = mid_chunk; // 1th:3--2th:2
				}
			}

			_main.insert(_main.begin() + (low_chunk * C), start, end);
			++inserted_count; // 4
		}
		++i; // 2
	}
	for (size_t i = 0; i < _main.size(); ++i)
	{
		this->v[i] = _main[i];
	}

}

void PmergeMe::_sortPairs(int reculLevel)
{
	int C = _powerOf2(reculLevel);
	for (size_t i = 0; i + (2 * C) <= v.size(); i += 2 * C)
	{
		std::vector<int>::iterator startB = v.begin() + i;
		std::vector<int>::iterator startA = v.begin() + i + C;

		int b = *(startB + C - 1);
		int a = *(startA + C - 1);
		++this->count;
		if (a <= b)
			_swap(startA, startB, C);
	}
}

void PmergeMe::_swap(std::vector<int>::iterator startA, std::vector<int>::iterator startB, int C)
{
	std::swap_ranges(startA, startA + C, startB);
}

size_t _powerOf2(size_t n) { return 1 << n; }

std::vector<size_t> _generateJacob(size_t size)
{
	std::vector<size_t> jacob;
	jacob.push_back(1);
	if (size == 1) return jacob;
	jacob.push_back(3);
	while (jacob.back() < size + 1)
	{
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
