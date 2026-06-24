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
	while (std::getline(data_f, line)) {
		if (line == "")
			break;
		i = 0;
		std::istringstream	line_s(line);
		std::string			token;
		while (std::getline(line_s, token, ',')) {
			if (i % 2 == 0)
				this->dates.push_back(token);
			else {
				char *end;
				this->values.push_back(std::strtof(token.c_str(), &end));
				if (errno == ERANGE) throw std::exception();
				if (*end != '\0') throw std::exception();
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
		this->dates = other.dates;
		this->values = other.values;
		this->ready = other.ready;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::print_obj() {
	std::cout << this->dates.size() ;
	for (size_t i = 0; i < this->dates.size(); i++) {
		std::cout << this->dates[i] << " | " << std::fixed << std::setprecision(2) << this->values[i] << std::endl;
	}
}

int	BitcoinExchange::calcule_PNL(std::string input_file) {
	std::deque<std::string>	dq = this->load_input(input_file);
	if (dq.at(0) != "data" || dq.at(1) != "value") {
		std::cerr << "Erorr: bad header input.\n";
		dq.pop_front();
		dq.pop_front();
	}
	bool	odd = false;
	if (dq.size() % 2 == 1) {
		std::string	last_elem = dq.back();
		dq.pop_back();
		odd = true;
	}
	while (dq.size()) {
		if (_handel_date(dq.at(0)) && _handel_value(dq.at(1))) {

		}
	}
}

bool	_handel_date(std::string date) {
	std::istringstream	line_s(date);
	std::string			token;
	int	i = 0;
	while (std::getline(line_s, token, '-')) {
		if (token.empty()) return false;
		if (i == 0)
			if (!check_years(token)) return false;
		else if (i == 1)
			if (!check_month(token)) return false;
		else if (i == 2)
			if (!check_days(token)) return false;
		else if (i > 2) return false;
		++i;
	}
}

bool	_handel_value(std::string value) {
	
}

bool	check_days(std::string days) {

}

bool	check_month(std::string month) {
	size_t 		i = 0;
	long long	count = 0;
	while (i < month.length()) {
		if (!isdigit(month.at(i))) return false;
		count = count * 10 + (month.at(i) - '0');
		if (count > std::numeric_limits<int>::max()) return false;
		++i;
	}
	
}

bool	check_years(std::string year) {
	while (!year.empty()) {
		if (!isdigit(year.at(0))) return false;
		year.erase(0, 1);
	}
	return true;
}

std::deque<std::string>	BitcoinExchange::load_input(std::string input_file) {
	std::ifstream ip_file(input_file);
	if (!ip_file.is_open()) {
		std::cerr << "Error: could not open file.\n";
		throw std::exception();
	}
	std::string	line;
	// std::getline(ip_file, line);
	std::deque<std::string> dq;
	int i = 0;
	while (std::getline(ip_file, line)) {
		if (line.empty()) continue;
		std::istringstream	line_s(line);
		std::string			token;
		i = 0;
		while (std::getline(line_s, token, '|')) {
			if (token.empty()) {
				std::cerr << "Error: bad input => " << line << std::endl;
				// throw std::exception();
				break;
			}
			if (i > 1) {
				std::cerr << "Error: bad input => " << line << std::endl;
				// throw std::exception();
				dq.pop_back();
				dq.pop_back();
				break;
			}
			token = _trim(token);
			dq.push_back(token);
			++i;
		}
	}
	return dq;
}

std::string	_trim(std::string& input) {
	std::string::size_type start = input.find_first_not_of(" \t\n\r\v\f");
	std::string::size_type end = input.find_last_not_of(" \t\n\r\v\f");
	return input.substr(start, end - start + 1);
}