#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cerrno>
#include <cstdlib>
#include <limits>
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

	void		print_obj();
	std::deque<std::string>	load_input(std::string input_file);
	int			calcule_PNL(std::string input_file);
};

std::string	_trim(std::string& input);
bool		_handel_date(std::string date);
bool		_handel_value(std::string value);