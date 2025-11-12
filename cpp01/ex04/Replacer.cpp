#include "Replacer.hpp"


Replacer::Replacer(const std::string& _file, const std::string& _s1, const std::string& _s2) : file(_file), s1(_s1), s2(_s2) {}


bool    Replacer::replace(void) {
	if (file.empty() || s1.empty() || s2.empty()) {
		error_msg("Argument empty\n");
		return false;
	}
	
}