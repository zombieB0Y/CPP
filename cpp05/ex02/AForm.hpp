#pragma once

#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				sign;
	const unsigned int	req_grade_to_sign;
	const unsigned int	req_grade_to_exe;

public:
	AForm();
	AForm(const AForm &copy);
	AForm	&operator=(const AForm &copy);
	virtual ~AForm();

	AForm(std::string _name, int grade_to_sign, int grade_to_exe);
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
	class FormNotSignedException : public std::exception
	{
	private:
		std::string msg;

	public:
		FormNotSignedException();
		~FormNotSignedException() throw();
		const char *what() const throw();
	};

	std::string		getName() const;
	bool			getSign() const;
	unsigned int	getReqGradeToSign() const;
	unsigned int	getReqGradeToExe() const;

	void			beSigned(Bureaucrat &officer);
	virtual	void	exe() const = 0;

	void			setSign(bool _sign);

	void			execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &stream, const AForm &ins);