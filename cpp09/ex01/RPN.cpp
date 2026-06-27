#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) {*this = other;}
RPN&	RPN::operator=(const RPN& other) {
	if (this != &other)
		this->s_t = other.s_t;
	return *this;
}
RPN::~RPN() {}

int	RPN::_ToInt(std::string value) const {return value[0] - '0';}

RPN::RPN(const std::string input) {
	std::string	ip = input;

	std::istringstream	line(ip);
	std::string			token;
	while (std::getline(line, token, ' ')) {
		// std::cout << token << std::endl;
		token = _trim(token);
		if (token.empty()) continue;
		if (token.length() > 1 || (!isdigit(token.at(0)) && !_checkSign(token))) {
			std::cerr << "Error" << std::endl;
			return;
		}
		else if (_checkSign(token)) { // switch case() !!!!
			if (this->s_t.size() > 1) {
				if (token.at(0) == '+') {
					int	b = this->s_t.top();
					this->s_t.pop();
					int a = this->s_t.top();
					this->s_t.pop();
					this->s_t.push(a + b);
				}
				else if (token.at(0) == '-') {
					int	b = this->s_t.top();
					this->s_t.pop();
					int a = this->s_t.top();
					this->s_t.pop();
					this->s_t.push(a - b);
				}
				else if (token.at(0) == '*') {
					int	b = this->s_t.top();
					this->s_t.pop();
					int a = this->s_t.top();
					this->s_t.pop();
					this->s_t.push(a * b);
				}
				else if (token.at(0) == '/') {
					int	b = this->s_t.top();
					this->s_t.pop();
					int a = this->s_t.top();
					this->s_t.pop();
					if (b == 0) {
						std::cerr << "Error\n";
						return ;
					}
					this->s_t.push(a / b);
				}
			}
			else {
				std::cerr << "Error\n";
				return;
			}
		}
		else this->s_t.push(this->_ToInt(token));
	}

	if (this->s_t.size() != 1) {
		std::cerr << "Error\n";
		return;
	}
	std::cout << this->s_t.top() << std::endl;
}

std::string _trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos) return "";
	size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, (last - first + 1));
}

bool		_checkSign(const std::string s) {return (s.at(0) == '-' || s.at(0) == '+' || s.at(0) == '/' || s.at(0) == '*');}