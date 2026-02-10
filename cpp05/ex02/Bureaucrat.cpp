#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat() : name("none"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName()) {
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy)
		this->grade = copy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

// -------------------------------------------------------------------

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name) {
	if (_grade <= 0)
		throw GradeTooHighException(_grade);
	else if (_grade > 150)
		throw GradeTooLowException(_grade);
	else
		grade = _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return (this->msg.c_str());
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return (this->msg.c_str());
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int _grade) {
	std::stringstream ss;
    ss << "Error: Grade " << _grade << " is too hight!";
	this->msg = RED;
	this->msg += ss.str();
	this->msg += RESET;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int _grade) {
	std::stringstream ss;
    ss << "Error: Grade " << _grade << " is too low!";
	this->msg = RED;
	this->msg += ss.str();
	this->msg += RESET;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

std::string		Bureaucrat::getName() const {
	return (name);
}

unsigned int	Bureaucrat::getGrade() const {
	return (grade);
}

void			Bureaucrat::inc_grade() {
	if (this->grade == 1)
		throw GradeTooHighException(grade);
	else
		this->grade--;
}

void			Bureaucrat::dec_grade() {
	if (grade == 150)
		throw GradeTooLowException(grade);
	else
		this->grade++;
}

void			Bureaucrat::signForm(AForm &form) {
	if (form.getSign())
		return;
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " form because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &ins) {
	stream << ins.getName() << ", bureaucrat grade " << ins.getGrade();
	return stream;
}

void			Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &err) {
		std::cerr << this->getName() << " couldn't execute " << form.getName() << "  because " << err.what() << std::endl;
	}
}