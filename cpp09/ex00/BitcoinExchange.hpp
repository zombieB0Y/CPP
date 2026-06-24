#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <exception>

class BitcoinExchange {
private:
	std::deque<std::string>	dates;
	std::deque<float>		values;
	bool					ready;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	print_obj();
};