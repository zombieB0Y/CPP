#include "Form.hpp"

Form::Form() : name("none"), sign(false), req_grade_to_sign(150), req_grade_to_exe(150) {}

Form::Form(const Form &copy) : name(copy.getName()), sign(copy.getSign()), req_grade_to_sign(copy.getReqGradeToSign()), req_grade_to_exe(copy.getReqGradeToExe()) {}

Form	&Form::operator=(const Form &copy) {
	if (this != &copy)
		this->sign = copy.getSign();
	return *this;
}

Form::~Form() {}

//*-----------------------*

Form::Form(std::string _name, int grade_to_sign, int grade_to_exe) : name(_name), sign(false), req_grade_to_sign(grade_to_sign), req_grade_to_exe(grade_to_exe) {
	if (grade_to_sign <= 0 || grade_to_exe <= 0) {
		if (grade_to_sign <= 0)
			throw GradeTooHighException(grade_to_sign);
		else
			throw GradeTooHighException(grade_to_exe);
	}
	else if (grade_to_sign > 150 || grade_to_exe > 150) {
		if (grade_to_sign > 150)
			throw GradeTooLowException(grade_to_sign);
		else
			throw GradeTooLowException(grade_to_exe);
	}
}

std::string		Form::getName() const {
	return this->name;
}

bool			Form::getSign() const {
	return this->sign;
}

unsigned int	Form::getReqGradeToSign() const {
	return this->req_grade_to_sign;
}

unsigned int	Form::getReqGradeToExe() const {
	return this->req_grade_to_exe;
}

void			Form::beSigned(Bureaucrat &officer) {
	if (this->sign)
		return;
	if (this->getReqGradeToSign() < officer.getGrade())
		throw GradeTooLowException(officer.getGrade());
	else
		this->sign = true;
}

Form::GradeTooHighException::GradeTooHighException(int _grade) {
	std::stringstream ss;
    ss << "Error: Grade " << _grade << " is too hight!";
	this->msg = RED;
	this->msg += ss.str();
	this->msg += RESET;
}

Form::GradeTooLowException::GradeTooLowException(int _grade) {
	std::stringstream ss;
    ss << "Error: Grade " << _grade << " is too low!";
	this->msg = RED;
	this->msg += ss.str();
	this->msg += RESET;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Form::GradeTooHighException::what() const throw() {
	return (this->msg.c_str());
}

const char *Form::GradeTooLowException::what() const throw() {
	return (this->msg.c_str());
}

std::ostream		&operator<<(std::ostream &stream, const Form &ins) {
	std::string sign = ins.getSign() ? "signed" : "not signed";
	stream << ins.getName() << " is " << sign << " and the grade to sign is " << ins.getReqGradeToSign() << " and to execute it is " << ins.getReqGradeToExe() << std::endl;
	return stream;
}

