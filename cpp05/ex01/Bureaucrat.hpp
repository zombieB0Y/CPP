#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name;
	unsigned int grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();

	Bureaucrat(std::string _name, int _grade);

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

	std::string getName() const;
	unsigned int getGrade() const;

	void inc_grade(void);
	void dec_grade(void);

	void	signForm(Form &form);
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &ins);