#pragma once

#include <string>
#include <iostream>
#include <fstream>

void	error_msg(std::string msg);

class Replacer
{
private:
    std::string line;
    std::string file;
	std::string s1;
	std::string s2;
public:
    bool    replace();
    Replacer(const std::string& file, const std::string& s1, const std::string& s2);
};

