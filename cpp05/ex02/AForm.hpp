#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

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
		GradeTooHighException(std::string name);
		~GradeTooHighException() throw();
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	private:
		std::string msg;

	public:
		GradeTooLowException(std::string name);
		~GradeTooLowException() throw();
		const char *what() const throw();
	};

	std::string		getName() const;
	bool			getSign() const;
	unsigned int	getReqGradeToSign() const;
	unsigned int	getReqGradeToExe() const;

	virtual void	beSigned(Bureaucrat &officer) = 0;

	void			setSign(bool _sign);
};

std::ostream	&operator<<(std::ostream &stream, const AForm &ins);