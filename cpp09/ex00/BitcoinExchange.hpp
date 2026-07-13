#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cerrno>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <iterator>
#include <exception>

class BitcoinExchange
{
private:
	std::map<std::string, float> db;
	// bool ready;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void print_obj();
	void load_input(std::string input_file);
	void calcule_PNL(std::string input_file);
	float _getDateValue(std::string date);
};

std::string _trim(const std::string& str);
bool _handel_date(std::string date);
bool _handel_value(std::string value);
bool check_years(std::string year);
bool check_month(std::string month);
bool check_days(std::string days);
float ToFloat(std::string value, std::string &error);