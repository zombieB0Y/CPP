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
		throw GradeTooHighException(this->getName());
	else if (_grade > 150)
		throw GradeTooLowException(this->getName());
	else
		grade = _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return (this->msg.c_str());
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return (this->msg.c_str());
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string name) {
	this->msg = name + ", bureaucrat grade is too Hight";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string name) {
	this->msg = name + ", bureaucrat grade is too Low";
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
		throw GradeTooHighException(this->getName());
	else
		this->grade--;
}

void			Bureaucrat::dec_grade() {
	if (grade == 150)
		throw GradeTooLowException(this->getName());
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