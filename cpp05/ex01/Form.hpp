#ifndef FORM_HPP
#define FORM_HPP

#include <iomanip>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NotEnoughGradeToSignException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class AlreadySignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	Form(void);
	Form(const std::string &name, int MinGradeToSign, int MinGradeToExec);
	Form(const Form &src);
	Form &operator=(const Form &src);
	~Form(void);

	const std::string &getName(void) const;
	bool getIsSigned(void) const;
	int getMinGradeToSign(void) const;
	int getMinGradeToExec(void) const;

	void setIsSigned(bool);
	void beSigned(const Bureaucrat &bureaucrat);

private:
	const std::string _name;
	bool _issigned;
	const int _MinGradeToSign;
	const int _MinGradeToExec;
};

std::ostream &operator<<(std::ostream &o, const Form &form);
#endif
