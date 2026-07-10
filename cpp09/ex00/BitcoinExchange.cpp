#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream data_f("data.csv");
	if (!data_f.is_open()) {
		std::cerr << "need data file to load !" << std::endl;
		ready = false;
		return ;
	}
	std::string	line;
	std::getline(data_f, line);
	int	i = 0;
	std::string current_date;
	while (std::getline(data_f, line)) {
		if (line == "")
			break;
		i = 0;
		std::istringstream	line_s(line);
		std::string			token;
		while (std::getline(line_s, token, ',')) {
			if (i % 2 == 0)
				current_date = token;
			else {
				char *end;
				float val = std::strtof(token.c_str(), &end);
				if (errno == ERANGE) throw std::exception();
				if (*end != '\0') throw std::exception();
				this->db[current_date] = val;
			}
			++i;
		}
	}
	data_f.close();
	this->ready = true;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {*this = other;}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->db = other.db;
		this->ready = other.ready;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::print_obj() {
	std::cout << this->db.size();
	for (std::map<std::string, float>::iterator it = this->db.begin(); it != this->db.end(); ++it) {
		std::cout << it->first << " | " << std::fixed << std::setprecision(2) << it->second << std::endl;
	}
}

void	BitcoinExchange::calcule_PNL(std::string input_file) {
	this->load_input(input_file);
}

float	BitcoinExchange::_getDateValue(std::string date) {
	std::map<std::string, float>::iterator i = this->db.lower_bound(date);
	if (i == this->db.begin()) return this->db.begin()->second;
	if (i == this->db.end()) {
		std::map<std::string, float>::iterator last = this->db.end();
		--last;
		return last->second;
	}
	if (date == i->first) return i->second;
	--i;
	return i->second;
}



bool	_handel_date(std::string date) {
	std::istringstream	line_s(date);
	std::string			token;
	int	i = 0;
	while (std::getline(line_s, token, '-')) {
		if (token.empty()) return false;
		if (i == 0) {
			if (!check_years(token))
				return false;
		}
		else if (i == 1) {
			if (!check_month(token))
				return false;
		}
		else if (i == 2) {
			if (!check_days(token))
				return false;
		}
		else if (i > 2) return false;
		++i;
	}
	return true;
}

bool	_handel_value(std::string value) {
	std::string error = "";
	ToInt(value, error);
	if (!error.empty()) {
		std::cerr << "Error: " << error << std::endl;
		return false;
	}
	return true;
}

float		ToInt(std::string s, std::string& error) {
	char* endptr;
	errno = 0;
	
	float f = std::strtof(s.c_str(), &endptr);

	if (errno == ERANGE) error = "too large a number.";
	else if (*endptr != '\0') error = "not a valid number";
	else if (f < 0) error = "not a positive number.";
	else if (f > 1000) error = "too large a number.";

	return f;
}

bool	check_days(std::string days) {
	if (days.length() != 2) return false;
	if (days.length() == 2 && (!std::isdigit(days.at(0)) || !std::isdigit(days.at(1)))) return false;
	if (days.at(0) - '0' > 3) return false;
	if (days.at(0) - '0' == 3 && days.at(1) - '0' > 1) return false;
	if (days.at(0) - '0' == 0 && days.at(1) - '0' == 0) return false;
	return true;
}

bool	check_month(std::string month) {
	if (month.length() == 1 && !std::isdigit(month.at(0))) return false;
	if (month.length() != 2) return false;
	if (month.length() == 2 && (!std::isdigit(month.at(0)) || !std::isdigit(month.at(1)))) return false;
	if (month.at(0) - '0' > 1) return false;
	if (month.at(0) - '0' == 1 && month.at(1) - '0' > 2) return false;
	if (month.at(0) - '0' == 0 && month.at(1) - '0' == 0) return false;
	return true;
}

bool	check_years(std::string year) {
	if (year.length() != 4) return false;
	while (!year.empty()) {
		if (!std::isdigit(year.at(0))) return false;
		year.erase(0, 1);
	}
	return true;
}

void	BitcoinExchange::load_input(std::string input_file) {
	std::ifstream ip_file(input_file.c_str());
	if (!ip_file.is_open()) {
		std::cerr << "Error: could not open file.\n";
		throw std::exception();
	}
	std::string	line;
	std::deque<std::string> dq;
	int i = 0;
	bool	header = false;
	bool	error = false;
	bool	value = false;
	bool	d = false;
	bool	v = false;
	while (std::getline(ip_file, line)) {
		// if (line.empty()) continue;
		line = _trim(line);
		if (line.empty()) continue;
		error = false;
		value = false;
		std::istringstream	line_s(line);
		std::string			token;
		i = 0;
		while (std::getline(line_s, token, '|')) {
			if (token.empty()) {
				std::cerr << "Error: bad input => " << line << std::endl;
				pop_intil(dq, i);
				error = true;
				break;
			}
			if (i > 1) {
				std::cerr << "Error: bad input => " << line << std::endl;
				pop_intil(dq, i);
				error = true;
				break;
			}
			else if (i == 1)
				value = true;
			token = _trim(token);
			dq.push_back(token);
			++i;
		}
		if (!error) {
			if (!value) {
				std::cerr << "Error: bad input => " << line << std::endl;
				pop_intil(dq, i);
			}
			else if (!header && (dq.at(0) != "date" || dq.at(1) != "value")) {
				std::cerr << "Erorr: bad header input => " << line << std::endl;
				pop_intil(dq, i);
				header = true;
			}
			else if (!header && (dq.at(0) == "date" && dq.at(1) == "value")) {
				pop_intil(dq, i);
				header = true;
			}
			else if ((d = _handel_date(dq.at(0)) == true) && (v = _handel_value(dq.at(1))) == true) {
				std::string place_holder = "";
				std::cout << dq.at(0) << " => " << dq.at(1) << " = " << ToInt(dq.at(1), place_holder) * this->_getDateValue(dq.at(0)) << std::endl;
				pop_intil(dq, i);
			}
			else if (!d) {
				// std::cout << "test ---" << std::endl;
				std::cerr << "Error: bad input => " << line << std::endl;
				pop_intil(dq, i);
			}
			else if (!v) {
				pop_intil(dq, i);
			}
		}
	}
	ip_file.close();
}

void	pop_intil(std::deque<std::string>& dq, int idx) {
	while (idx != 0 && !dq.empty()) {
		dq.pop_front();
		--idx;
	}
}

std::string _trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos) return "";
	size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, (last - first + 1));
}