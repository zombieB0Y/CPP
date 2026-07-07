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
	void	_sortPairs();
	void	_swap(int a, int b);
	void	_loadPairs(std::vector<int> *pairs);
};

size_t	_powerOf2(int n);