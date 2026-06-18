#include "Span.hpp"

Span::Span() {this->N = 0;}
Span::Span(const Span& other) {*this = other;}
Span	&Span::operator=(const Span& other) {
	if (this != &other) {
		this->N = other.N;
		this->span = other.span;
	}
	return *this;
}
Span::~Span() {}

Span::Span(int n) {
	if (n < 0)
		throw std::exception();
	this->N = n;
	this->span.reserve(n);
}

void	Span::addNumber(int value) {
	if (this->N == span.size())
		throw std::exception();
	this->span.push_back(value);
}

long	Span::longestSpan() const {
	if (span.size() < 2)
		throw std::exception();
	long	max = *std::max_element(this->span.begin(), this->span.end());
	long	min	= *std::min_element(this->span.begin(), this->span.end());
	return std::abs(max - min);
}

long	Span::shortestSpan() const {
	if (span.size() < 2)
		throw std::exception();
	std::vector<int> sp = this->span;
	std::sort(sp.begin(), sp.end());
	long min = sp[1] - sp[0];
	for (size_t i = 1; i + 1 < span.size(); ++i) {
		if (sp[i+1] - sp[i] < min)
			min = sp[i+1] - sp[i];
	}
	return min;
}
