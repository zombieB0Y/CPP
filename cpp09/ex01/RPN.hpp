#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <sstream>


class RPN {
private:
	std::stack<int>	s_t;
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	RPN(const std::string input);
	int	_ToInt(std::string	value) const;
};

std::string _trim(const std::string& str);
bool		_checkSign(const std::string s);