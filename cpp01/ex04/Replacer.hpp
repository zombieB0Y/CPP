#pragma once

#include <string>
#include <iostream>
#include <fstream>

class Replacer
{
private:
	size_t			inx;
	std::string		line;
	std::string		file;
	std::string		file_to_rep;
	std::string		s1;
	std::string		s2;
	std::ifstream	inputFile;
	std::ofstream	outputFile;
public:
	bool    replace();
	void	error_msg(std::string msg);
	Replacer(const std::string& file, const std::string& s1, const std::string& s2);
};

