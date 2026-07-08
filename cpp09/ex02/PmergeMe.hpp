#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
// #include <iomanip>
#include <sstream>


class PmergeMe {
private:
	std::vector<int>	v;
	// int					recuLevel;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	PmergeMe(std::string input);
	void	_LoadVector(std::string input);
	void	_sortVector(int recuLevel);
	void	_sortPairs(int recuLevel);
	void	_swap(std::vector<int>::iterator startA, std::vector<int>::iterator startB, int C);
};

size_t	_powerOf2(size_t n);
// size_t	_generateJacob(int n);
std::vector<size_t> _generateJacob(size_t size);