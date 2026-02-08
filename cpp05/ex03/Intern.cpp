#include "Intern.hpp"

Intern::Intern() {};
Intern::Intern(const Intern &copy) {
	*this = copy;
};
Intern	&Intern::operator=(const Intern &copy) {
	if (this != &copy) {}
	return *this;
}
Intern::~Intern() {}

//*------------------------*

AForm	*Intern::makeForm(const std::string name, const std::string target) {
	std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*(*func[])(const std::string) = {&creat_shrub, &creat_robot, &creat_pardon};
	int	count = sizeof(names) / sizeof(names[0]);
	for (int i = 0; i < count; i++) {
		if (name == names[i])
			return func[i](target);
	}
	std::cerr << "there is no Form in the name '" << name << "', u can choose from this :" << std::endl;
	for (int i = 0; i < count; i++) {
		std::cout << names[i] << std::endl;
	}
	return 0;
}

AForm	*creat_shrub(const std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm	*creat_robot(const std::string target) {
	return new RobotomyRequestForm(target);
}

AForm	*creat_pardon(const std::string target) {
	return new PresidentialPardonForm(target);
}