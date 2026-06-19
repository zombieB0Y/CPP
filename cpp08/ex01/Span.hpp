#pragma once

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>


class Span {
private:
	unsigned int	N;
	std::vector<int>	span;
public:
	Span();
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	Span(int n);
	void	addNumber(int value);
	template <typename iterator>
	void	addNumber(iterator begin, iterator end) {
		if (this->span.size() + std::distance(begin, end) > this->N)
			throw std::exception();
		this->span.insert(this->span.end(), begin, end);
	}
	long	longestSpan() const;
	long	shortestSpan() const;
};