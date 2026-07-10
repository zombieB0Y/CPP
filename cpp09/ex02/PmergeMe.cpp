#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::_parsePositiveInt(const std::string &token) const
{
	if (token.empty())
		throw std::invalid_argument("empty argument");

	if (token[0] == '-')
		throw std::invalid_argument("negative numbers are not allowed: '" + token + "'");

	for (size_t i = 0; i < token.size(); ++i)
	{
		if (i == 0 && token[i] == '+')
			continue;
		if (!std::isdigit(static_cast<unsigned char>(token[i])))
			throw std::invalid_argument("non-numeric character in argument: '" + token + "'");
	}

	errno = 0;
	char *endptr = 0;
	long value = std::strtol(token.c_str(), &endptr, 10);

	if (endptr == token.c_str() || *endptr != '\0')
		throw std::invalid_argument("could not parse argument: '" + token + "'");
	if (errno == ERANGE || value > static_cast<long>(INT_MAX))
		throw std::out_of_range("integer overflow: '" + token + "'");

	if (value <= 0)
		throw std::invalid_argument("only strictly positive integers are allowed: '" + token + "'");

	return static_cast<int>(value);
}

void PmergeMe::parseArguments(int argc, char **argv)
{
	_input.clear();
	if (argc < 2)
		throw std::invalid_argument("no arguments provided");
	for (int i = 1; i < argc; ++i)
		_input.push_back(_parsePositiveInt(std::string(argv[i])));
}

void PmergeMe::execute()
{
	if (_input.empty())
		return;
	_print("Before: ", _vec);

	std::clock_t vecStart = std::clock();
	_vec.insert(_vec.end(), _input.begin(), _input.end());
	_sort(_vec, 0);
	std::clock_t vecEnd = std::clock();

	std::clock_t deqStart = std::clock();
	_deq.insert(_deq.end(), _input.begin(), _input.end());
	_sort(_deq, 0);
	std::clock_t deqEnd = std::clock();

	_print("After: ", _vec);

	double vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000.0;
	double deqTime = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size()
			   << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			   << " elements with std::deque : " << deqTime << " us" << std::endl;
}

size_t PmergeMe::_powerOf2(size_t n)
{
	return static_cast<size_t>(1) << n;
}

std::vector<size_t> PmergeMe::_generateJacob(size_t size)
{
	std::vector<size_t> jacob;
	jacob.push_back(1);
	if (size == 1)
		return jacob;
	jacob.push_back(3);
	while (jacob.back() < size + 1)
	{
		size_t last_idx = jacob.size() - 1;
		size_t next = jacob[last_idx] + 2 * jacob[last_idx - 1];
		jacob.push_back(next);
	}
	return jacob;
}