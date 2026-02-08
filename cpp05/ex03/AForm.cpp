#include "AForm.hpp"

AForm::AForm() : name("none"), sign(false), req_grade_to_sign(150), req_grade_to_exe(150) {}

AForm::AForm(const AForm &copy) : name(copy.getName()), sign(copy.getSign()), req_grade_to_sign(copy.getReqGradeToSign()), req_grade_to_exe(copy.getReqGradeToExe()) {}

AForm	&AForm::operator=(const AForm &copy) {
	if (this != &copy)
		this->sign = copy.getSign();
	return *this;
}

AForm::~AForm() {}

//*-----------------------*

AForm::AForm(std::string _name, int grade_to_sign, int grade_to_exe) : name(_name), sign(false), req_grade_to_sign(grade_to_sign), req_grade_to_exe(grade_to_exe) {
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

std::string		AForm::getName() const {
	return this->name;
}

bool			AForm::getSign() const {
	return this->sign;
}

unsigned int	AForm::getReqGradeToSign() const {
	return this->req_grade_to_sign;
}

unsigned int	AForm::getReqGradeToExe() const {
	return this->req_grade_to_exe;
}

void			AForm::beSigned(Bureaucrat &officer) {
	if (this->sign)
		return;
	if (this->getReqGradeToSign() < officer.getGrade())
		throw GradeTooLowException(officer.getGrade());
	else
		this->sign = true;
}

AForm::GradeTooHighException::GradeTooHighException(int _grade) {
	std::stringstream ss;
    ss << "Error: Grade " << _grade << " is too hight!";
	this->msg = RED;
	this->msg += ss.str();
	this->msg += RESET;
}

AForm::GradeTooLowException::GradeTooLowException(int _grade) {
	std::stringstream ss;
    ss << "Error: Grade " << _grade << " is too low!";
	this->msg = RED;
	this->msg += ss.str();
	this->msg += RESET;
}

AForm::FormNotSignedException::FormNotSignedException() {
	this->msg = "Procedural Error 404: Signature missing. Please submit form 27B-6 first.";
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::FormNotSignedException::~FormNotSignedException() throw() {}

const char *AForm::GradeTooHighException::what() const throw() {
	return (this->msg.c_str());
}

const char *AForm::GradeTooLowException::what() const throw() {
	return (this->msg.c_str());
}

const char *AForm::FormNotSignedException::what() const throw() {
	return (this->msg.c_str());
}

std::ostream		&operator<<(std::ostream &stream, const AForm &ins) {
	std::string sign = ins.getSign() ? "signed" : "not signed";
	stream << ins.getName() << " is " << sign << " and the grade to sign is " << ins.getReqGradeToSign() << " and to execute it is " << ins.getReqGradeToExe() << std::endl;
	return stream;
}

void	AForm::setSign(bool _sign) {
	this->sign = _sign;
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (!this->getSign())
		throw FormNotSignedException();
	else if (this->getReqGradeToExe() < executor.getGrade()) {
		throw GradeTooLowException(executor.getGrade());
	}
	exe();
}
