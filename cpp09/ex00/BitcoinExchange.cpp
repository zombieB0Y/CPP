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