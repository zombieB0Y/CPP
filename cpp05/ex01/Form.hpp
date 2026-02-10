#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				sign;
	const unsigned int	req_grade_to_sign;
	const unsigned int	req_grade_to_exe;

public:
	Form();
	Form(const Form &copy);
	Form	&operator=(const Form &copy);
	~Form();

	Form(std::string _name, int grade_to_sign, int grade_to_exe);
	class GradeTooHighException : public std::exception
	{
	private:
		std::string msg;

	public:
		GradeTooHighException(int _grade);
		~GradeTooHighException() throw();
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	private:
		std::string msg;

	public:
		GradeTooLowException(int _grade);
		~GradeTooLowException() throw();
		const char *what() const throw();
	};

	std::string		getName() const;
	bool			getSign() const;
	unsigned int	getReqGradeToSign() const;
	unsigned int	getReqGradeToExe() const;

	void			beSigned(Bureaucrat &officer);
};

std::ostream	&operator<<(std::ostream &stream, const Form &ins);