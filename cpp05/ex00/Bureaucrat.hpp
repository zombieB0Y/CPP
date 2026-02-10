#pragma once

#include <iostream>
#include <sstream>

#define RED "\033[31m"
#define RESET "\033[0m"

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

	std::string getName() const;
	unsigned int getGrade() const;

	void inc_grade(void);
	void dec_grade(void);
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &ins);