#include "Replacer.hpp"


Replacer::Replacer(const std::string& _file, const std::string& _s1, const std::string& _s2) : file(_file), s1(_s1), s2(_s2) {
	inx = 0;
}

void	Replacer::error_msg(std::string msg) {
	std::cerr << inx << " : " << msg;
	inx++;
}

bool    Replacer::replace(void) {
	if (file.empty() || s1.empty()) {
		error_msg("Argument empty\n");
		return false;
	}
	inputFile.open(file.c_str());
	file_to_rep = file + ".replace";
	outputFile.open(file_to_rep.c_str());
	if (!inputFile.is_open() || !outputFile.is_open()) {
		error_msg("error openning a file\n");
		return false;
	}
	while (std::getline(inputFile, line)) {
		size_t	pos = line.find(s1);
		while (pos != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}
		outputFile << line;
		if (inputFile.peek() != EOF) {
			outputFile << std::endl;
		}
	}
	inputFile.close();
	outputFile.close();
	return true;
}
