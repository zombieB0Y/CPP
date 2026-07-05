#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class PmergeMe {
private:
	std::vector<int> v;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
};