#ifndef AFORM_HPP
#define AFORM_HPP

#include <iomanip>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

	class NotEnoughGradeToExecException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	AForm(void);
	AForm(const std::string &name, int MinGradeToSign, int MinGradeToExec);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm(void);

	const std::string &getName(void) const;
	bool getIsSigned(void) const;
	int getMinGradeToSign(void) const;
	int getMinGradeToExec(void) const;

	void setIsSigned(bool);
	void beSigned(const Bureaucrat &executor);

	virtual void execute(Bureaucrat const &executor) const = 0;

private:
	const std::string _name;
	bool _issigned;
	const int _MinGradeToSign;
	const int _MinGradeToExec;
};

std::ostream &operator<<(std::ostream &o, const AForm &form);
#endif
