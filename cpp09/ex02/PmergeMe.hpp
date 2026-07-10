#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <climits>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	std::vector<int> _input;
	std::vector<int> _vec;
	std::deque<int> _deq;

	int _parsePositiveInt(const std::string &token) const;
	// ----------------------- template -------------------------------
	template <typename Container>
	void _sortPairs(Container &c, int recuLevel)
	{
		size_t C = _powerOf2(recuLevel);
		for (size_t i = 0; i + (2 * C) <= c.size(); i += 2 * C)
		{
			typename Container::iterator startB = c.begin() + i;
			typename Container::iterator startA = c.begin() + i + C;

			int b = *(startB + C - 1);
			int a = *(startA + C - 1);

			if (a <= b)
				_swap(startA, startB, C);
		}
	}

	template <typename Iterator>
	void _swap(Iterator startA, Iterator startB, size_t C) { std::swap_ranges(startA, startA + C, startB); }

	template <typename Container>
	void _print(const std::string &label, const Container &c) const
	{
		std::cout << label;
		typename Container::const_iterator it = c.begin();
		typename Container::const_iterator ite = c.end();
		bool first = true;

		for (; it != ite; ++it)
		{
			if (!first)
				std::cout << " ";
			std::cout << *it;
			first = false;
		}
		std::cout << std::endl;
	}

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	void parseArguments(int argc, char **argv);
	void execute();
	size_t _powerOf2(size_t n);
	std::vector<size_t> _generateJacob(size_t size);

	// ---------------------- template ----------------------------

	template <typename Container>
	void _sort(Container &c, int recuLevel)
	{
		size_t C = _powerOf2(recuLevel);
		if (c.size() / C < 2)
			return;
		_sortPairs(c, recuLevel);
		_sort(c, recuLevel + 1);

		Container _main;
		Container _pend;

		_main.insert(_main.end(), c.begin(), c.begin() + (2 * C));
		for (size_t i = 2 * C; i + (2 * C) <= c.size(); i += 2 * C)
		{
			_main.insert(_main.end(), c.begin() + i + C, c.begin() + i + (2 * C));
			_pend.insert(_pend.end(), c.begin() + i, c.begin() + i + C);
		}
		if ((c.size() / C) % 2 != 0)
		{
			size_t leftover_start = (c.size() / (2 * C)) * (2 * C);
			_pend.insert(_pend.end(), c.begin() + leftover_start, c.begin() + leftover_start + C);
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

			for (size_t k = safeJNum; k > O_jNum; --k)
			{
				size_t pend_idx = k - 2;
				typename Container::iterator start = _pend.begin() + (pend_idx * C);
				typename Container::iterator end = _pend.begin() + ((pend_idx + 1) * C);

				int b_val = *(end - 1);
				size_t low_chunk = 0;
				size_t high_chunk = k + inserted_count;
				while (low_chunk < high_chunk)
				{
					size_t mid_chunk = low_chunk + (high_chunk - low_chunk) / 2;
					int a_val = *(_main.begin() + ((mid_chunk + 1) * C) - 1);
					if (a_val <= b_val)
						low_chunk = mid_chunk + 1;
					else
						high_chunk = mid_chunk;
				}

				_main.insert(_main.begin() + (low_chunk * C), start, end);
				++inserted_count;
			}
			++i;
		}

		for (size_t j = 0; j < _main.size(); ++j)
			c[j] = _main[j];
	}
};
